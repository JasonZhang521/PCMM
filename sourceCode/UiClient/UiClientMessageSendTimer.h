#ifndef UICLIENTMESSAGESENDTIMER_H
#define UICLIENTMESSAGESENDTIMER_H
#include "ITimer.h"
#include <memory>

namespace IpcMessage {
class IIpcMessageQueue;
}

namespace Ipc {
class IIpcClient;
}

namespace UiClient {
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
};

}
#endif // UICLIENTMESSAGESENDTIMER_H
