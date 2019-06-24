// C++ headers
#include <Windows.h>

// own header
#include "SysInfoWindowsImpl.h"

QVector<quint64> SysInfoWindowsImpl::cpuRowData() noexcept
{
    FILETIME idleTime, kernelTime, userTime;
    GetSystemTimes(&idleTime, &kernelTime, &userTime);
    return {
        convertFileTime(idleTime),
        convertFileTime(kernelTime),
        convertFileTime(userTime)
    };
}

quint64 SysInfoWindowsImpl::convertFileTime(const FILETIME &fileTime) const noexcept
{
    ULARGE_INTEGER largeInteger;
    largeInteger.LowPart = fileTime.dwLowDateTime;
    largeInteger.HighPart = fileTime.dwHighDateTime;
    return largeInteger.QuadPart;
}

SysInfoWindowsImpl::SysInfoWindowsImpl()
    : SysInfo{}, _cpuLoadLastValues{}
{}


void SysInfoWindowsImpl::init() noexcept
{
    _cpuLoadLastValues = cpuRowData();
}

double SysInfoWindowsImpl::cpuLoadAverage() noexcept
{
    const QVector<quint64> firstSample = _cpuLoadLastValues;
    const QVector<quint64> secondSample = cpuRowData();
    _cpuLoadLastValues = secondSample;
    const quint64 currentIdle = secondSample[0] - firstSample[0];
    const quint64 currentKernel = secondSample[1] - firstSample[1];
    const quint64 currentUser = secondSample[2] - firstSample[2];
    const quint64 currentSystem = currentKernel + currentUser;
    const double percent = (currentSystem - currentIdle) * 100.0 /
            static_cast<double>(currentSystem) ;
    return qBound(0.0, percent, 100.0);
}

double SysInfoWindowsImpl::memoryUsed() noexcept
{
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memoryStatus);
    return static_cast<double>(memoryStatus.ullTotalPhys - memoryStatus.ullAvailPhys) // memory used
           / static_cast<double>(memoryStatus.ullTotalPhys) * 100.0;
}
