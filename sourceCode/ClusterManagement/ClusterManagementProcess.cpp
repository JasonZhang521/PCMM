#include "ClusterManagementProcess.h"
#include "ClusterMgtClientsManagement.h"
#include "ClusterMgtConnectionAcceptor.h"
#include "ClusterMgtController.h"
#include "IpcServerCreator.h"
#include "IIpcServer.h"
#include "IpSocketEndpoint.h"
#include "LoopMain.h"
namespace ClusterManagement {
ClusterManagementProcess::ClusterManagementProcess()
{

}

void ClusterManagementProcess::process()
{
    // create the Cluster mananger control
    std::shared_ptr<IClusterMgtController> clusterMgtController(new ClusterMgtController());

    // create node server
    {
        // create the Ipc server, will set the tcp acceptor later
        Network::IpSocketEndpoint localEndpoint("127.0.0.1:23832");
        // create ipc acceptor
        ClusterMgtConnectionAcceptor* acceptorPtr = new ClusterMgtConnectionAcceptor(NodeType, clusterMgtController);
        std::shared_ptr<Ipc::IIpcConnectionAcceptor> acceptor(acceptorPtr);
        std::shared_ptr<Ipc::IIpcServer> ipcServer(Ipc::IpcServerCreator::CreateWithTcpServer(localEndpoint, acceptor));
        // add the client manger to the  mananger control
        std::shared_ptr<IClusterMgtClientsManagement> clientsManager(new ClusterMgtClientsManagment(ipcServer));
        clusterMgtController->addClientManager(NodeType, clientsManager);
    }

    // create UI server
    {
        // create the Ipc server, will set the tcp acceptor later
        Network::IpSocketEndpoint localEndpoint("127.0.0.1:23833");
        // create ipc acceptor
        ClusterMgtConnectionAcceptor* acceptorPtr = new ClusterMgtConnectionAcceptor(UiType, clusterMgtController);
        std::shared_ptr<Ipc::IIpcConnectionAcceptor> acceptor(acceptorPtr);
        std::shared_ptr<Ipc::IIpcServer> ipcServer(Ipc::IpcServerCreator::CreateWithTcpServer(localEndpoint, acceptor));
        // add the client manger to the  mananger control
        std::shared_ptr<IClusterMgtClientsManagement> clientsManager(new ClusterMgtClientsManagment(ipcServer));
        clusterMgtController->addClientManager(UiType, clientsManager);
    }


    clusterMgtController->startup();
    // run
    Core::LoopMain::instance().loop();
}


}
