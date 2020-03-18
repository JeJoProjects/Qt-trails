// Own headers
#include "SysInfo.h"

// Qt headers
#include <QtGlobal>

// C++ headers

// forward declarations


#ifdef Q_OS_WIN
    #include "SysInfoWindowsImpl.h"
#elif defined(Q_OS_MAC)
    #include "SysInfoMacImpl.h"
#elif defined(Q_OS_LINUX)
    #include "SysInfoLinuxImpl.h"
#endif

SysInfo::SysInfo() noexcept
{

}

SysInfo& SysInfo::instance() noexcept
{
    #ifdef Q_OS_WIN
        static SysInfoWindowsImpl singleton;
    #elif defined(Q_OS_MAC)
        static SysInfoMacImpl singleton;
    #elif defined(Q_OS_LINUX)
        static SysInfoLinuxImpl singleton;
    #endif
    return singleton;
}



SysInfo::~SysInfo() noexcept
{

}
