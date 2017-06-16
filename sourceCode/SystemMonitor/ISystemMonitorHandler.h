#ifndef ISYSTEMMONITORHANDLER_H
#define ISYSTEMMONITORHANDLER_H

namespace SystemMonitor {
class ISystemMonitorHandler
{
public:
    ISystemMonitorHandler();
    ~ISystemMonitorHandler();
    virtual void reportSystemInfo() = 0;
};

}

#endif // ISYSTEMMONITORHANDLER_H
