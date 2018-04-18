#ifndef _DEVICECOMMUNICATION_IDEVICESERVER_H_
#define _DEVICECOMMUNICATION_IDEVICESERVER_H_

namespace DeviceCommunication {
class IDeviceServer
{
public:
    IDeviceServer(); 
    virtual ~IDeviceServer();
    virtual void startup() = 0;
    virtual void shutdown() = 0;
};

}

#endif // _DEVICECOMMUNICATION_IDEVICESERVER_H_
