#ifndef _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
#define _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
#include "IDeviceClientManager.h"

namespace DeviceCommunication {
class DeviceClientManager : public IDeviceClientManager
{
public:
    DeviceClientManager();
    virtual ~DeviceClientManager();
    virtual void addClient(std::unique_ptr<IDeviceClient> client);
    virtual void handleMessage(DeviceMessage::IDeviceMessage& message);
};

}

#endif // _DEVICECOMMUNICATION_DEVICECLIENTMANAGER_H_
