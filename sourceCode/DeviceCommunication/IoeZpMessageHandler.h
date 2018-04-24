#ifndef _DEVICECOMMUNICATION_IOEZPMESSAGEHANDLER_H_
#define _DEVICECOMMUNICATION_IOEZPMESSAGEHANDLER_H_
#include "IDeviceMessageHandler.h"

namespace DeviceCommunication {
class IoeZpMessageHandler : public IDeviceMessageHandler
{
public:
    IoeZpMessageHandler();
    virtual ~IoeZpMessageHandler();
    virtual void handleMessage(const DeviceMessage::IDeviceMessage* message);
};
}

#endif // _DEVICECOMMUNICATION_IOEZPMESSAGEHANDLER_H_
