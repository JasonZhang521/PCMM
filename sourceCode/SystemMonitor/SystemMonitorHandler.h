#ifndef _SYSTEMMONITOR_SYSTEMMONITORHANDLER_H_
#define _SYSTEMMONITOR_SYSTEMMONITORHANDLER_H_
#include "ISystemMonitorHandler.h"
#include "SystemInfoCollector.h"
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace Ipc {
    class IIpcClient;
    class IConnectionTx;
}

namespace TimerHandler {
    class ITimer;
}

namespace SystemMonitor {

class SystemMonitorHandler : public ISystemMonitorHandler
{
    std::shared_ptr<Ipc::IIpcClient> ipcClient_;
public:
    SystemMonitorHandler(std::shared_ptr<Ipc::IIpcClient> ipcClient);
    ~SystemMonitorHandler();
private:
    virtual void reportSystemInfo();
    virtual void startup();
    virtual void shutdown();

public:
     GETCLASSNAME(SystemInfoCollector)
};

}

#endif // _SYSTEMMONITOR_SYSTEMMONITORHANDLER_H_
