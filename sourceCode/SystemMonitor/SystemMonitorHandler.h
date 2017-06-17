#ifndef SYSTEMMONITORHANDLER_H
#define SYSTEMMONITORHANDLER_H
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

public:
     GETCLASSNAME(SystemInfoCollector)
};

}

#endif // SYSTEMMONITORHANDLER_H
