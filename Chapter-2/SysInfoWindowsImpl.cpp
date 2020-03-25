// Own headers
#include "SysInfoWindowsImpl.h"

// Qt headers

// C++ headers
#include <Windows.h>

// forward declarations



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

SysInfoWindowsImpl::SysInfoWindowsImpl() noexcept
    : SysInfo{}
    , mCpuLoadLastValues{}
{}


void SysInfoWindowsImpl::init() noexcept
{
    mCpuLoadLastValues = cpuRowData();
}

double SysInfoWindowsImpl::cpuLoadAverage() noexcept
{
    const QVector<quint64> firstSample = mCpuLoadLastValues;
    const QVector<quint64> secondSample = cpuRowData();
    mCpuLoadLastValues = secondSample;
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
