#ifndef _SIMULATORCLIENT_UICLIENTMESSAGESENDTIMER_H_
#define _SIMULATORCLIENT_UICLIENTMESSAGESENDTIMER_H_
#include "ITimer.h"
#include <memory>
#include "Component.h"
#include "Macro.h"

namespace IpcMessage {
class IIpcMessageQueue;
}

namespace Ipc {
class IIpcClient;
}

namespace SimulatorClient {
class UiClientMessageSendTimer : public TimerHandler::ITimer
{
    std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageSendQueue_;
    std::shared_ptr<Ipc::IIpcClient> ipcClient_;
public:
    UiClientMessageSendTimer(std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageSendQueue,
                             std::shared_ptr<Ipc::IIpcClient> ipcClient);
    ~UiClientMessageSendTimer();
    virtual void onTime();
    virtual std::ostream& operator<<(std::ostream& os);
public:
     GETCLASSNAME(UiClientRestartTimer)
};

}
#endif // _SIMULATORCLIENT_UICLIENTMESSAGESENDTIMER_H_
