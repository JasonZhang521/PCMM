#include "UiClientMessageSendTimer.h"
#include "IIpcClient.h"
#include "IIpcMessageQueue.h"
#include "IIpcMessage.h"

namespace UiClient {
UiClientMessageSendTimer::UiClientMessageSendTimer(std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageSendQueue,
                                                   std::shared_ptr<Ipc::IIpcClient> ipcClient)
    : TimerHandler::ITimer(1000, TimerHandler::TimerType::PeriodTimer)
    , ipcMessageSendQueue_(ipcMessageSendQueue)
    , ipcClient_(ipcClient)
{

}

UiClientMessageSendTimer::~UiClientMessageSendTimer()
{

}

void UiClientMessageSendTimer::onTime()
{
    if (!ipcMessageSendQueue_->isEmpty())
    {
        std::unique_ptr<IpcMessage::IIpcMessage> msg = std::move(ipcMessageSendQueue_->popFront());
        ipcClient_->send(*msg);
    }
}

std::ostream& UiClientMessageSendTimer::operator<<(std::ostream& os)
{
    os << "[";
    TimerHandler::ITimer::print(os);
    os << ", messageQueueSize=" << ipcMessageSendQueue_->getSize();
    os << "]";
    return os;
}

}
