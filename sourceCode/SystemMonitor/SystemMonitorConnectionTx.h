#ifndef SYSTEMMONITORCONNECTIONTX_H
#define SYSTEMMONITORCONNECTIONTX_H
#include "ISystemMonitorHandler.h"
#include "IIpcConnectionReceiver.h"
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace IpcMessage {
class IIpcMessage;
}

namespace SystemMonitor {

class SystemMonitorConnectionReceiver : public Ipc::IIpcConnectionReceiver
{
    std::shared_ptr<ISystemMonitorHandler> monitorHandler_;
public:
    SystemMonitorConnectionReceiver(std::shared_ptr<ISystemMonitorHandler> monitorHandler);
    ~SystemMonitorConnectionReceiver();
protected:
    virtual void onConnect();
    virtual void onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg);
    virtual void onDisconnect();

public:
     GETCLASSNAME(SystemInfoCollector)
};

}

#endif // SYSTEMMONITORCONNECTIONTX_H
