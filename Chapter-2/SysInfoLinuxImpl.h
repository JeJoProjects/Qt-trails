#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H

// Qt headers

// C++ headers

// forward declarations


// Qt headers
#include <QtGlobal>
#include <QVector>
#include "SysInfo.h"

class SysInfoLinuxImpl final : public SysInfo
{
private:
    // member variable: system timing at a given moment
    QVector<quint64> mCpuLoadLastValues;

private:
    // helper function(s)

    /* will perform the Linux API call to retrieve system timing information
     * and return values in a QVector. We retrieve and return four values
     * containing the time the CPU has spent on the following: normal processes
     * in User mode, nice processes in User mode, processes in Kernel mode, and idle.
     */
    QVector<quint64> cpuRawData() noexcept;
public:
    // constructors
    SysInfoLinuxImpl();
    ~SysInfoLinuxImpl() override = default;

    // SysInfo interface
    void init() noexcept override;
    double cpuLoadAverage() noexcept override;
    double memoryUsed() noexcept override;
};

#endif // SYSINFOLINUXIMPL_H
