#ifndef IDEVICECLIENTMANAGER_H
#define IDEVICECLIENTMANAGER_H
#include <memory>

namespace DeviceCommunication {

class IDeviceClient;
class IDeviceClientManager
{
public:
    IDeviceClientManager();
    virtual ~IDeviceClientManager();
    virtual void addClient(std::unique_ptr<IDeviceClient> client) = 0;

};
}
#endif // IDEVICECLIENTMANAGER_H
