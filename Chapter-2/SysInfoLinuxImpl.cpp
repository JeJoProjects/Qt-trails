// C++ headers
#include <sys/types.h>
#include <sys/sysinfo.h>

// Qt header
#include <QFile>

// own header
#include "SysInfoLinuxImpl.h"

QVector<quint64> SysInfoLinuxImpl::cpuRowData() noexcept
{
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);
    const QByteArray line = file.readLine();
    file.close();

    quint64 totalUser = 0, totalUserNice = 0;
    quint64 totalSystem = 0, totalIdle = 0;
    std::sscanf(line.data(), "cpu %llu %llu %llu %llu",
                &totalUser, &totalUserNice, &totalSystem, &totalIdle);

    return {totalUser, totalUserNice, totalSystem, totalIdle};
}

SysInfoLinuxImpl::SysInfoLinuxImpl()
    : SysInfo{}, _cpuLoadLastValues{}
{}

void SysInfoLinuxImpl::init() noexcept
{
    _cpuLoadLastValues = cpuRawData();
}

double SysInfoLinuxImpl::cpuLoadAverage() noexcept
{
    const QVector<quint64> firstSample = _cpuLoadLastValues;
    const QVector<quint64> secondSample = cpuRawData();
    _cpuLoadLastValues = secondSample;

    /* https://www.kernel.org/doc/Documentation/filesystems/proc.txt
     * overall is equal to user + nice + kernel
     */
    const double overall = (secondSample[0] - firstSample[0])
                         + (secondSample[1] - firstSample[1])
                         + (secondSample[2] - firstSample[2]);
    // total is equal to overall + idle
    const double total = overall + (secondSample[3] - firstSample[3]);
    const double percent = (overall / total) * 100.0;
    return qBound(0.0, percent, 100.0);
}

double SysInfoLinuxImpl::memoryUsed() noexcept
{
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    quint64 totalMemory = memInfo.totalram;
    totalMemory += memInfo.totalswap;
    totalMemory *= memInfo.mem_unit;

    quint64 totalMemoryUsed = memInfo.totalram - memInfo.freeram;
    totalMemoryUsed += memInfo.totalswap - memInfo.freeswap;
    totalMemoryUsed *= memInfo.mem_unit;

    const double percent = static_cast<double>(totalMemoryUsed) /
    static_cast<double>(totalMemory) * 100.0;
    return qBound(0.0, percent, 100.0);
}
