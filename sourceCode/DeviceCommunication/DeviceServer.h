#ifndef _DEVICECOMMUNICATION_IOEZPSERVER_H_
#define _DEVICECOMMUNICATION_IOEZPSERVER_H_
#include "IDeviceServer.h"
#include "DeviceType.h"
#include <memory>

namespace Network {
class ITcpServer;
}
namespace DeviceCommunication {
class DeviceConnectionAcceptor;
class DeviceServer : public IDeviceServer
{
    DeviceType type_;
    std::unique_ptr<Network::ITcpServer> server_;
public:
    DeviceServer() = delete;
    DeviceServer(DeviceType type, std::unique_ptr<Network::ITcpServer> server);
    virtual ~DeviceServer();
    virtual void startup();
    virtual void shutdown();
};

}

#endif // _DEVICECOMMUNICATION_IOEZPSERVER_H_
