#include "ClusterConnectionAcceptor.h"
#include "TcpSocket.h"
#include "TcpClient.h"

namespace ClustersManagement {
ClusterConnectionAcceptor::ClusterConnectionAcceptor()
{

}

void ClusterConnectionAcceptor::onAccept(int fd,
                                         const Network::IpSocketEndpoint& localEndPoint,
                                         const Network::IpSocketEndpoint& remoteEndPoint)
{
    createClusterConnection(fd, localEndPoint, remoteEndPoint);
}

void ClusterConnectionAcceptor::createClusterConnection(int fd,
                                                        const Network::IpSocketEndpoint& localEndPoint,
                                                        const Network::IpSocketEndpoint& remoteEndPoint)
{
    std::shared_ptr<Network::TcpSocket> socket(new Network::TcpSocket(fd, localEndPoint, remoteEndPoint));
    std::shared_ptr<Network::ITcpClient> tcpAcceptedClient(new Network::TcpClient(socket));

    // Ipc client strategy
    Ipc::IpcConnectionTcpClientStrategy* ipcConnectionClientStrategyPtr =
            new Ipc::IpcConnectionTcpClientStrategy(tcpAcceptedClient);
    std::shared_ptr<Ipc::IpcConnectionTcpClientStrategy> ipcConnectionClientStrategy(ipcConnectionClientStrategyPtr);

    // Ipc client
    Ipc::IpcClient* ipcClientPtr = new Ipc::IpcClient(ipcConnectionClientStrategy);
    std::shared_ptr<Ipc::IpcClient> ipcClient(ipcClientPtr);

    // tcp connection receiver
    tcpAcceptedClient->setConnectionReceiver(ipcConnectionClientStrategy);

    // System monitor factory
    std::shared_ptr<IpcMessage::IIpcMessageFactory>
            factory(new SystemMonitorMessage::SystemMonitorMessageFactory());

    // Set ipcConnectionTcpStrategy
    Ipc::IIpcConnectionClientStrategy* strategy = static_cast<Ipc::IIpcConnectionClientStrategy*>(ipcConnectionClientStrategyPtr);
    strategy->setIpcConnectionReceiver(/*systemMonitorConnectionReceiver*/);
    strategy->addIpcMessageFactory(IpcMessage::IpcMessageType::IpcMessage_SystemMonitor, factory);

}

}
