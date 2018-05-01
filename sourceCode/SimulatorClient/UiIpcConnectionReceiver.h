#ifndef _SIMULATORCLIENT_UIIPCCONNECTIONRECEIVER_H_
#define _SIMULATORCLIENT_UIIPCCONNECTIONRECEIVER_H_
#include "IIpcConnectionReceiver.h"
#include "Component.h"
#include "Macro.h"

namespace IpcMessage {
class IIpcMessageQueue;
}

namespace SimulatorClient {
class IUiClientHandler;

class UiIpcConnectionReceiver : public Ipc::IIpcConnectionReceiver
{
    std::shared_ptr<IUiClientHandler> uiClientHandler_;
    std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageReceiveQueue_;
public:
    UiIpcConnectionReceiver(std::shared_ptr<IUiClientHandler> uiClientHandler,
                            std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageReceiveQueue);
    virtual ~UiIpcConnectionReceiver();
    virtual void onConnect();
    virtual void onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg);
    virtual void onDisconnect();

private:
    void handleMessage(std::unique_ptr<IpcMessage::IIpcMessage> msg);

public:
     GETCLASSNAME(UiIpcConnectionReceiver)
};

}

#endif // _SIMULATORCLIENT_UIIPCCONNECTIONRECEIVER_H_
