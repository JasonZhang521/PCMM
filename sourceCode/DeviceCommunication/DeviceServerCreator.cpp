#include "DeviceServerCreator.h"
#include "IpSocketEndpoint.h"
#include "DeviceServer.h"
#include "DeviceConnectionAcceptor.h"
#include "TcpServer.h"
#include "LoopMain.h"
namespace DeviceCommunication {
DeviceServerCreator::DeviceServerCreator()
{

}

std::unique_ptr<IDeviceServer> DeviceServerCreator::CreateDeviceServer(DeviceType type, IDeviceClientManager& deviceClientManager, const Network::IpSocketEndpoint& localEndPoint)
{
    std::shared_ptr<Network::ITcpConnectionAcceptor> acceptor(new DeviceConnectionAcceptor(deviceClientManager, type));
    Network::TcpServer* tcpServerPtr = new Network::TcpServer(localEndPoint, acceptor);
    std::unique_ptr<Network::ITcpServer> tcpServer(tcpServerPtr);
    std::unique_ptr<IDeviceServer> deviceServer(new DeviceServer(type, std::move(tcpServer)));
    Core::LoopMain::instance().registerIo(Io::IoFdType::IoFdRead, tcpServerPtr);
    return std::move(deviceServer);
}
}
