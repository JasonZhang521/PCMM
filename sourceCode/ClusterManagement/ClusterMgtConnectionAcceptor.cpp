#include "ClusterMgtConnectionAcceptor.h"
#include "ClusterMgtConnectionReceiver.h"
#include "IClusterMgtClientsManagement.h"
#include "IpcConnectionTcpClientStrategy.h"
#include "IClusterMgtController.h"
#include "IpcClient.h"
#include "TcpSocket.h"
#include "TcpClient.h"
#include "SystemMonitorMessageFactory.h"
#include "LoopMain.h"

namespace ClusterManagement {
ClusterMgtConnectionAcceptor::ClusterMgtConnectionAcceptor(ClientType type, std::shared_ptr<IClusterMgtController> clusterMgtController)
    :clientType_(type)
    ,clusterMgtController_(clusterMgtController)
{

}

ClusterMgtConnectionAcceptor::~ClusterMgtConnectionAcceptor()
{

}

void ClusterMgtConnectionAcceptor::onAccept(int fd,
                                         const Network::IpSocketEndpoint& localEndPoint,
                                         const Network::IpSocketEndpoint& remoteEndPoint)
{
    createClusterConnection(fd, localEndPoint, remoteEndPoint);
}

void ClusterMgtConnectionAcceptor::createClusterConnection(int fd,
                                                        const Network::IpSocketEndpoint& localEndPoint,
                                                        const Network::IpSocketEndpoint& remoteEndPoint)
{
    std::shared_ptr<Network::TcpSocket> socket(new Network::TcpSocket(fd, localEndPoint, remoteEndPoint));
    Network::TcpClient* tcpAcceptedClientPtr = new Network::TcpClient(socket);
    std::shared_ptr<Network::ITcpClient> tcpAcceptedClient(tcpAcceptedClientPtr);

    // Ipc client strategy
    std::shared_ptr<Ipc::IpcConnectionTcpClientStrategy>
            ipcConnectionClientStrategy(new Ipc::IpcConnectionTcpClientStrategy(tcpAcceptedClient));

    // tcp connection receiver
    tcpAcceptedClient->setConnectionReceiver(ipcConnectionClientStrategy);

    // Ipc client
    Ipc::IpcClient* ipcClientPtr = new Ipc::IpcClient(ipcConnectionClientStrategy);
    std::shared_ptr<Ipc::IIpcClient> ipcClient(ipcClientPtr);

    // System monitor factory
    std::shared_ptr<IpcMessage::IIpcMessageFactory>
            factory(new SystemMonitorMessage::SystemMonitorMessageFactory());
    std::shared_ptr<Ipc::IIpcConnectionReceiver>
            clustersMgtConnectionReceiver(new ClusterMgtConnectionReceiver(clientType_, clusterMgtController_));

    // Set ipcConnectionTcpStrategy
    Ipc::IIpcConnectionClientStrategy* ipcConnectionClientStrategyPtr = ipcConnectionClientStrategy.get();
    ipcConnectionClientStrategyPtr->setIpcConnectionReceiver(clustersMgtConnectionReceiver);
    ipcConnectionClientStrategyPtr->addIpcMessageFactory(factory);

    clusterMgtController_->addAcceptedIpcClient(remoteEndPoint.toString(), ipcClient, clientType_);

    Core::LoopMain::instance().registerIo(Io::IoFdType::IoFdRead, tcpAcceptedClientPtr);
}

}
