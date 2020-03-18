#ifndef SYSINFO_H
#define SYSINFO_H

// Qt headers

// C++ headers

// forward declarations

/** class SysInfo is a singleton class:
 * The singleton must guarantee that there will be only one
 * instance of the class and that this instance will be
 * easily accessible from a single access point.
 */

class SysInfo
{
private:
    /* Copying: not allowed
     * Since only one instance of the object must exist,
     * allowing the copy constructor and the assignment operator is nonsense.
     *
     * alternatively(since C++11): can be 'delete'd.
     */
    SysInfo(const SysInfo &other) noexcept;
    SysInfo& operator=(const SysInfo &other) noexcept;

protected:
    // access granted only for the child classes
    explicit SysInfo() noexcept;

public:
    static SysInfo& instance() noexcept;

    virtual ~SysInfo() noexcept;

    /* allows the derived class to perform
     * any initialization process depending on the OS platform
     */
    virtual void init() noexcept = 0;

    /* calls some OS-specific code to retrieve the
     * average CPU load and returns it as a percentage value
     */
    virtual double cpuLoadAverage() noexcept = 0;

    /* calls some OS-specific code to retrieve the memory
     * used and returns it as a percentage value
     */
     virtual double memoryUsed() noexcept = 0;
};

#endif // SYSINFO_H
