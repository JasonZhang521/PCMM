#ifndef _SIMULATORCLIENT_UICLIENTPROCESS_H_
#define _SIMULATORCLIENT_UICLIENTPROCESS_H_
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace IpcMessage {
class IIpcMessageQueue;
class IIpcMessage;
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
public:
    UiClientProcess();
    ~UiClientProcess();
    void start();
    bool messageReceived();
    std::unique_ptr<IpcMessage::IIpcMessage> getOneMessage();
    void sendMessage(std::unique_ptr<IpcMessage::IIpcMessage> msg);
private:
    void process();
public:
     GETCLASSNAME(UiClientProcess)
};
}
#endif // _SIMULATORCLIENT_UICLIENTPROCESS_H_
