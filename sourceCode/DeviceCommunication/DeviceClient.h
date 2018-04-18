#ifndef DEVICECLIENT_H
#define DEVICECLIENT_H
#include "IDeviceClient.h"
#include <memory>
namespace Network {
class ITcpClient;
}

namespace DeviceMessage {
class IDeviceMessage;
}

namespace DeviceCommunication {
class DeviceClient : public IDeviceClient
{
    std::unique_ptr<Network::ITcpClient> client_;
public:
    DeviceClient() = delete;
    DeviceClient(std::unique_ptr<Network::ITcpClient> client);
    virtual ~DeviceClient();
    virtual void connect();
    virtual void send(DeviceMessage::IDeviceMessage& msg);
    virtual void disconnect();
};

}

#endif // DEVICECLIENT_H
