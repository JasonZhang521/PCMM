#include "ClusterManagementProcess.h"
#include "ClusterMgtClientsManagement.h"
#include "ClusterMgtConnectionAcceptor.h"
#include "ClusterMgtController.h"
#include "IpcConnectionTcpServerStrategy.h"
#include "IpcServer.h"
#include "TcpServer.h"
#include "IpSocketEndpoint.h"
namespace ClusterManagement {
ClusterManagementProcess::ClusterManagementProcess()
{

}

void ClusterManagementProcess::process()
{

    IpSocketEndpoint localEndPoint("192.168.5.135:7000");
    Network::ITcpServer* tcpServerPtr = new Network::TcpServer(localEndPoint);
    std::shared_ptr<Network::ITcpServer> tcpServer(tcpServerPtr);


    Ipc::IpcConnectionTcpServerStrategy* strategyPtr = new Ipc::IpcConnectionTcpServerStrategy(tcpServer);
    std::shared_ptr<Ipc::IpcConnectionTcpServerStrategy> strategy(strategyPtr);

    Ipc::IIpcServer* ipcServerPtr = new Ipc::IpcServer(strategy);

    std::shared_ptr<IClusterMgtController> clusterMgtController(new ClusterMgtController());
    std::shared_ptr<IClusterMgtClientsManagement> clientsManager(new ClusterMgtClientsManagment());
    clusterMgtController->addClientManager(NodeType, clientsManager);

    ClusterMgtConnectionAcceptor* acceptorPtr = new ClusterMgtConnectionAcceptor(clusterMgtController);
    std::shared_ptr<Ipc::IIpcConnectionAcceptor> acceptor(acceptorPtr);

    strategyPtr->setIpcConnectionAcceptor(acceptor);


}


}
