#include "ClientMessageSendTimer.h"
#include "IIpcClient.h"
#include "IIpcMessageQueue.h"
#include "IIpcMessage.h"
#include "IDeviceClient.h"
#include "IDeviceMessage.h"
#include "IDeviceMessageQueue.h"
#include "Trace.h"

namespace SimulatorClient {
ClientMessageSendTimer::ClientMessageSendTimer(std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageSendQueue,
                                               std::shared_ptr<Ipc::IIpcClient> ipcClient,
                                               std::shared_ptr<DeviceMessage::IDeviceMessageQueue> deviceMessageQueue,
                                               std::shared_ptr<DeviceCommunication::IDeviceClient> deviceClient)
    : TimerHandler::ITimer(1000, TimerHandler::TimerType::PeriodTimer)
    , ipcMessageSendQueue_(ipcMessageSendQueue)
    , ipcClient_(ipcClient)
    , deviceMessageQueue_(deviceMessageQueue)
    , deviceClient_(deviceClient)

{

}

ClientMessageSendTimer::~ClientMessageSendTimer()
{

}

void ClientMessageSendTimer::onTime()
{
    TRACE_DEBUG3("send message, message number in queue is " << ipcMessageSendQueue_->getSize());
    if (!ipcMessageSendQueue_->isEmpty())
    {
        std::unique_ptr<IpcMessage::IIpcMessage> msg = std::move(ipcMessageSendQueue_->popFront());
        ipcClient_->send(*msg);
    }

    TRACE_DEBUG3("send message, message number in queue is " << deviceMessageQueue_->getSize());
    if (!deviceMessageQueue_->isEmpty())
    {
        std::unique_ptr<DeviceMessage::IDeviceMessage> msg = std::move(deviceMessageQueue_->popFront());
        deviceClient_->send(*msg);
    }
}

std::ostream& ClientMessageSendTimer::operator<<(std::ostream& os)
{
    os << "[";
    TimerHandler::ITimer::print(os);
    os << ", ipcMessageQueueSize=" << ipcMessageSendQueue_->getSize();
    os << ", deviceMessageQueueSize=" << deviceMessageQueue_->getSize();
    os << "]";
    return os;
}

}
