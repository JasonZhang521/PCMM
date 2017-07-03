#include "SystemMonitorProcess.h"
#include "SystemInfoCollector.h"
#include "SystemMonitorHandler.h"
#include "SystemMonitorConnectionReceiver.h"
#include "SystemMonitorMessageFactory.h"
#include "IpcClient.h"
#include "IpcConnectionTcpClientStrategy.h"
#include "TcpClient.h"
#include "IpSocketEndpoint.h"
#include "EventTimer.h"
#include "LoopMain.h"
#include "NetworkEnv.h"
#include "IpAddress.h"
#include <memory>

namespace SystemMonitor {

SystemMonitorProcess::SystemMonitorProcess()
{
}

void SystemMonitorProcess::process()
{
    Network::IpAddresses ipAddresses = Network::NetworkEnv::getLocalIpAddress();
    for (auto ipAddress : ipAddresses)
    {
        std::cout << ipAddress << std::endl;
    }
    // Tcp client
    Network::IpSocketEndpoint localEndpoint(std::string("127.0.0.1:8000"));
    Network::IpSocketEndpoint remoteEndpoint(std::string("127.0.0.1:7001"));
    Network::TcpClient* tcpClientPtr = new Network::TcpClient(localEndpoint, remoteEndpoint);
    std::shared_ptr<Network::ITcpClient> tcpClient(tcpClientPtr);
    tcpClient->bind();


    // Ipc client strategy
    Ipc::IpcConnectionTcpClientStrategy* ipcConnectionClientStrategyPtr =
            new Ipc::IpcConnectionTcpClientStrategy(tcpClient);
    std::shared_ptr<Ipc::IpcConnectionTcpClientStrategy> ipcConnectionClientStrategy(ipcConnectionClientStrategyPtr);

    // Ipc client
    Ipc::IpcClient* ipcClientPtr = new Ipc::IpcClient(ipcConnectionClientStrategy);
    std::shared_ptr<Ipc::IpcClient> ipcClient(ipcClientPtr);

    // SystemMonitorHandler
    SystemMonitorHandler* systemMonitorHandlerPtr = new SystemMonitorHandler(ipcClient);
    std::shared_ptr<ISystemMonitorHandler> systemMonitorHandler(systemMonitorHandlerPtr);

    // SystemMonitorConnectionReceiver
    std::shared_ptr<SystemMonitorConnectionReceiver>
            systemMonitorConnectionReceiver(new SystemMonitorConnectionReceiver(systemMonitorHandler));


    // tcp connection receiver

    static_cast<Network::ITcpClient*>(tcpClientPtr)->setConnectionReceiver(ipcConnectionClientStrategy);

    // System monitor factory
    std::shared_ptr<IpcMessage::IIpcMessageFactory>
            factory(new SystemMonitorMessage::SystemMonitorMessageFactory());

    // Set ipcConnectionTcpStrategy
    Ipc::IIpcConnectionClientStrategy* strategy = static_cast<Ipc::IIpcConnectionClientStrategy*>(ipcConnectionClientStrategyPtr);
    strategy->setIpcConnectionReceiver(systemMonitorConnectionReceiver);
    strategy->addIpcMessageFactory(IpcMessage::IpcMessageType::IpcMessage_SystemMonitor, factory);

    // SystemInfoCollector
    SystemInfoCollector* systemInfoCollectorPtr = new SystemInfoCollector(systemMonitorHandler);
    std::shared_ptr<SystemInfoCollector> systemInfoCollector(systemInfoCollectorPtr);

    // EventTimer
    TimerHandler::EventTimer* timerPtr = new TimerHandler::EventTimer(5000, TimerHandler::TimerType::PeriodTimer, systemInfoCollectorPtr);
    std::unique_ptr<TimerHandler::EventTimer> eTimer(timerPtr);

    Core::LoopMain::instance().registerTimer(timerPtr);

    systemMonitorHandler->startup();
    // run
    Core::LoopMain::instance().loop();
}

}

