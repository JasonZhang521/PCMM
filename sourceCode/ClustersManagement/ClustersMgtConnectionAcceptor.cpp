#include "ClustersMgtConnectionAcceptor.h"
#include "ClustersMgtConnectionReceiver.h"
#include "IpcConnectionTcpClientStrategy.h"
#include "IpcClient.h"
#include "TcpSocket.h"
#include "TcpClient.h"
#include "LoopMain.h"

namespace ClustersManagement {
ClustersMgtConnectionAcceptor::ClustersMgtConnectionAcceptor()
{

}

void ClustersMgtConnectionAcceptor::onAccept(int fd,
                                         const Network::IpSocketEndpoint& localEndPoint,
                                         const Network::IpSocketEndpoint& remoteEndPoint)
{
    createClusterConnection(fd, localEndPoint, remoteEndPoint);
}

void ClustersMgtConnectionAcceptor::createClusterConnection(int fd,
                                                        const Network::IpSocketEndpoint& localEndPoint,
                                                        const Network::IpSocketEndpoint& remoteEndPoint)
{
    std::shared_ptr<Network::TcpSocket> socket(new Network::TcpSocket(fd, localEndPoint, remoteEndPoint));
    Network::TcpClient* tcpAcceptedClientPtr = new Network::TcpClient(socket);
    std::shared_ptr<Network::ITcpClient> tcpAcceptedClient(tcpAcceptedClientPtr);

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
    std::shared_ptr<Ipc::IIpcConnectionReceiver> clustersMgtConnectionReceiver(new ClustersMgtConnectionReceiver());

    // Set ipcConnectionTcpStrategy
    Ipc::IIpcConnectionClientStrategy* strategy = static_cast<Ipc::IIpcConnectionClientStrategy*>(ipcConnectionClientStrategyPtr);
    strategy->setIpcConnectionReceiver(clustersMgtConnectionReceiver);
    strategy->addIpcMessageFactory(IpcMessage::IpcMessageType::IpcMessage_SystemMonitor, factory);

    clustersManagementHandler_->addAcceptedIpcClient();

    Core::LoopMain::instance().registerIo(Io::IoFdType::IoFdRead, tcpAcceptedClientPtr);

}

}
