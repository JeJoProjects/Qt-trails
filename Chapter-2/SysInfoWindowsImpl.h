#pragma once

// Qt headers
#include <QtGlobal>
#include <QVector>

// other headers
#include "SysInfo.h"

using FILETIME = struct _FILETIME;

class SysInfoWindowsImpl final: public SysInfo
{
private:
    // member variable: system timing (idle, Kernel, and User) at a given moment
    QVector<quint64> _cpuLoadLastValues;

private:
    // helper function(s)

    /* will perform the Windows API call to retrieve system timing information
     * and return values in a generic format. We will retrieve and
     * return three values: the amount of time that the system has spent
     * in idle, in Kernel, and in User mode
     */
    QVector<quint64> cpuRowData() noexcept;

    /* will convert a Windows FILETIME struct syntax to a qulonglong type.
     */
    inline quint64 convertFileTime(const FILETIME &fileTime) const noexcept;

public:
    // constructors
    SysInfoWindowsImpl();
    ~SysInfoWindowsImpl() override = default;

    // SysInfo interface
    void init()  noexcept override;

    double cpuLoadAverage()  noexcept override;

    double memoryUsed()  noexcept override;
};
