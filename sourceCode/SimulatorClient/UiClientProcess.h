#ifndef _SIMULATORCLIENT_UICLIENTPROCESS_H_
#define _SIMULATORCLIENT_UICLIENTPROCESS_H_
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace IpcMessage {
class IIpcMessageQueue;
class IIpcMessage;
}

namespace DeviceMessage {
class IDeviceMessage;
class IDeviceMessageQueue;
}

namespace std {
class thread;
}

namespace SimulatorClient {
class UiClientProcess
{
    std::unique_ptr<std::thread> uiClientThread_;
    std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageSendQueue_;
    std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageReceiveQueue_;
    std::shared_ptr<DeviceMessage::IDeviceMessageQueue> deviceMessageQueue_;
public:
    UiClientProcess();
    ~UiClientProcess();
    void start();
    bool messageReceived();
    std::unique_ptr<IpcMessage::IIpcMessage> getOneMessage();
    void sendMessage(std::unique_ptr<IpcMessage::IIpcMessage> msg);
    void sendMessage(std::unique_ptr<DeviceMessage::IDeviceMessage> msg);
private:
    void process();
public:
     GETCLASSNAME(UiClientProcess)
};
}
#endif // _SIMULATORCLIENT_UICLIENTPROCESS_H_
