#include "ClusterManagementProcess.h"
#include "ClusterMgtClientsManagement.h"
#include "ClusterMgtConnectionAcceptor.h"
#include "ClusterMgtController.h"
#include "DeviceClientManager.h"
#include "DeviceConnectionReceiverCreator.h"
#include "DeviceServerCreator.h"
#include "IDeviceServer.h"
#include "IpcServerCreator.h"
#include "IIpcServer.h"
#include "IpSocketEndpoint.h"
#include "LoopMain.h"
#include "Environment.h"
#include "ShellCommandThread.h"
#include "NetworkConfig.h"
#include "CoredumpConfig.h"
#include "Configure.h"
#include "AppConst.h"
#include <vector>
#include <string>

namespace ClusterManagement {
ClusterManagementProcess::ClusterManagementProcess()
{

}

void ClusterManagementProcess::process()
{
    CoredumpConfig::LimitSet();
    Configure::getInstance().setTraceLogFilePath("/opt/HongClusterMgt/log/ClusterManagement.message.log");

    // create the Cluster mananger control
    std::shared_ptr<IClusterMgtController> clusterMgtController(new ClusterMgtController());
    DeviceCommunication::DeviceClientManager deviceClientManager;

    std::vector<std::string> nodeServerIpPorts = ConfigureManagement::NetworkConfig::getNodeServerIpPort();
    std::vector<std::string> uiServerIpPorts = ConfigureManagement::NetworkConfig::getUiServerIpPort();
    std::vector<std::string> deviceServerIpPorts = ConfigureManagement::NetworkConfig::getDeviceServerIpPort();
    // create node server
    {
        // create the Ipc server, will set the tcp acceptor later
        Network::IpSocketEndpoint localEndpoint(nodeServerIpPorts[0]);
        // create ipc acceptor
        ClusterMgtConnectionAcceptor* acceptorPtr = new ClusterMgtConnectionAcceptor(NodeType, clusterMgtController);
        std::shared_ptr<Ipc::IIpcConnectionAcceptor> acceptor(acceptorPtr);
        std::shared_ptr<Ipc::IIpcServer> ipcServer(Ipc::IpcServerCreator::CreateWithTcpServer(localEndpoint, acceptor));
        // add the client manger to the  mananger control
        std::unique_ptr<IClusterMgtClientsManagement> clientsManager(new ClusterMgtClientsManagment(NodeType, ipcServer));
        clusterMgtController->addClientManager(NodeType, std::move(clientsManager));
    }

    // create UI server
    {
        // create the Ipc server, will set the tcp acceptor later
        Network::IpSocketEndpoint localEndpoint(uiServerIpPorts[0]);
        // create ipc acceptor
        ClusterMgtConnectionAcceptor* acceptorPtr = new ClusterMgtConnectionAcceptor(UiType, clusterMgtController);
        std::shared_ptr<Ipc::IIpcConnectionAcceptor> acceptor(acceptorPtr);
        std::shared_ptr<Ipc::IIpcServer> ipcServer(Ipc::IpcServerCreator::CreateWithTcpServer(localEndpoint, acceptor));
        // add the client manger to the  mananger control
        std::unique_ptr<IClusterMgtClientsManagement> clientsManager(new ClusterMgtClientsManagment(UiType, ipcServer));
        clusterMgtController->addClientManager(UiType, std::move(clientsManager));
    }

    // create Device server
    {
        // create the Ipc server, will set the tcp acceptor later
        Network::IpSocketEndpoint localEndpoint(deviceServerIpPorts[0]);
        std::unique_ptr<DeviceCommunication::IDeviceServer> deviceServer = DeviceCommunication::DeviceServerCreator::CreateDeviceServer(DeviceCommunication::DeviceType::IOEZP, deviceClientManager, localEndpoint);
        (static_cast<DeviceCommunication::IDeviceClientManager&>(deviceClientManager)).setDeviceServer(std::move(deviceServer));
    }

    // start service
    clusterMgtController->startup();
    (static_cast<DeviceCommunication::IDeviceClientManager&>(deviceClientManager)).startup();

    // register the commands
    {
        Environment::IShellCommand* commandDf =
                new Environment::ShellCommandThread(Environment::ShellCommand::getCmdString(Environment::ShellCommandType::DiskUsageDf), DfCommandPeriod);
        Environment::Environment::instance().registerShellCmd(Environment::ShellCommandType::DiskUsageDf, commandDf);

        Environment::IShellCommand* commandDuHome =
                new Environment::ShellCommandThread(Environment::ShellCommand::getCmdString(Environment::ShellCommandType::DiskUsageDuHome), DuCommandPeriod);
        Environment::Environment::instance().registerShellCmd(Environment::ShellCommandType::DiskUsageDuHome, commandDuHome);
    }
    // run
    Core::LoopMain::instance().loopStart();
}


}
