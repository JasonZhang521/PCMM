#ifndef _DEVICECOMMUNICATION_DEVICESERVERCREATOR_H_
#define _DEVICECOMMUNICATION_DEVICESERVERCREATOR_H_
#include "DeviceType.h"


namespace DeviceCommunication {
class IDeviceServer;
class DeviceServerCreator
{
public:
    DeviceServerCreator();
    IDeviceServer* CreateDeviceServer(DeviceType type);
};
}
#endif // _DEVICECOMMUNICATION_DEVICESERVERCREATOR_H_
