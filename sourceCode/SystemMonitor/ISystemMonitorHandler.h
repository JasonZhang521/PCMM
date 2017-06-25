#ifndef _SYSTEMMONITOR_ISYSTEMMONITORHANDLER_H_
#define _SYSTEMMONITOR_ISYSTEMMONITORHANDLER_H_

namespace SystemMonitor {
class ISystemMonitorHandler
{
public:
    ISystemMonitorHandler();
    ~ISystemMonitorHandler();
    virtual void reportSystemInfo() = 0;
    virtual void startup() = 0;
    virtual void shutdown() = 0;
};

}

#endif // _SYSTEMMONITOR_ISYSTEMMONITORHANDLER_H_
