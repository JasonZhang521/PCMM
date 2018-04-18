#include "DeviceConnectionAcceptor.h"
#include "IoeZpConnectionReceiver.h"
#include "IDeviceClientManager.h"
#include "DeviceConnectionReceiverCreator.h"
#include "DeviceClient.h"
#include "TcpClient.h"
#include "TcpSocket.h"
#include "LoopMain.h"
#include <memory>

namespace DeviceCommunication {

DeviceConnectionAcceptor::DeviceConnectionAcceptor(IDeviceClientManager& clientManager, DeviceType type)
    : clientManager_(clientManager)
    , type_(type)
{

}

DeviceConnectionAcceptor::~DeviceConnectionAcceptor()
{

}

void DeviceConnectionAcceptor::onAccept(int fd, const Network::IpSocketEndpoint& localEndPoint, const Network::IpSocketEndpoint& remoteEndPoint)
{
    std::shared_ptr<Network::ITcpConnectionReceiver> receiver(DeviceConnectionReceiverCreator::create(type_, remoteEndPoint, clientManager_));
    std::unique_ptr<Network::TcpSocket> socket(new Network::TcpSocket(fd, localEndPoint, remoteEndPoint));
    std::unique_ptr<Network::TcpClient> tcpClient(new Network::TcpClient(Network::TcpState::Tcp_Established, std::move(socket)));
    Network::ITcpClient* pITcpClient = tcpClient.get();
    pITcpClient->setConnectionReceiver(receiver);
    // Tcp client
    Core::LoopMain::instance().registerIo(Io::IoFdType::IoFdRead, tcpClient.get());
    std::unique_ptr<IDeviceClient> deviceClient(new DeviceClient(std::move(tcpClient)));
    clientManager_.addClient(std::move(deviceClient));
}

}
