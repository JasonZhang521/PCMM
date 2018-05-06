#ifndef _SIMULATORCLIENT_CLIENTMESSAGESENDTIMER_H_
#define _SIMULATORCLIENT_CLIENTMESSAGESENDTIMER_H_
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

namespace DeviceMessage {
class IDeviceMessageQueue;
}

namespace DeviceCommunication {
class IDeviceClient;
}

namespace SimulatorClient {
class ClientMessageSendTimer : public TimerHandler::ITimer
{
    std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageSendQueue_;
    std::shared_ptr<Ipc::IIpcClient> ipcClient_;

    std::shared_ptr<DeviceMessage::IDeviceMessageQueue> deviceMessageQueue_;
    std::shared_ptr<DeviceCommunication::IDeviceClient> deviceClient_;
public:
    ClientMessageSendTimer(std::shared_ptr<IpcMessage::IIpcMessageQueue> ipcMessageSendQueue,
                           std::shared_ptr<Ipc::IIpcClient> ipcClient,
                           std::shared_ptr<DeviceMessage::IDeviceMessageQueue> deviceMessageQueue,
                           std::shared_ptr<DeviceCommunication::IDeviceClient> deviceClient);
    ~ClientMessageSendTimer();
    virtual void onTime();
    virtual std::ostream& operator<<(std::ostream& os);
public:
     GETCLASSNAME(UiClientRestartTimer)
};

}
#endif // _SIMULATORCLIENT_CLIENTMESSAGESENDTIMER_H_
