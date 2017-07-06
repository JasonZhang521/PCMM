#include "SystemMonitorProcess.h"
#include "SystemInfoCollector.h"
#include "SystemMonitorHandler.h"
#include "SystemMonitorConnectionReceiver.h"
#include "SystemMonitorMessageFactory.h"
#include "IpcClient.h"
#include "IpcConnectionTcpClientStrategy.h"
#include "IpcClientCreator.h"
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

    // Local and remote endpoint.
    Network::IpSocketEndpoint localEndpoint(std::string("192.168.3.1:8000"));
    //Network::IpSocketEndpoint remoteEndpoint(std::string("127.0.0.1:7001"));
    Network::IpSocketEndpoint remoteEndpoint(std::string("192.168.3.1:7001"));
    // SystemMonitorHandler
    SystemMonitorHandler* systemMonitorHandlerPtr = new SystemMonitorHandler();
    std::shared_ptr<ISystemMonitorHandler> systemMonitorHandler(systemMonitorHandlerPtr);

    // SystemMonitorConnectionReceiver
    std::shared_ptr<SystemMonitorConnectionReceiver>
            systemMonitorConnectionReceiver(new SystemMonitorConnectionReceiver(systemMonitorHandler));

    // System monitor factory
    std::shared_ptr<IpcMessage::IIpcMessageFactory>
            factory(new SystemMonitorMessage::SystemMonitorMessageFactory());

    Ipc::IIpcClient* ipcClientPtr = Ipc::IpcClientCreator::CreateWithTcpClientStrategy(localEndpoint, remoteEndpoint, systemMonitorConnectionReceiver, factory);
    std::shared_ptr<Ipc::IIpcClient> ipcClient(ipcClientPtr);

    systemMonitorHandlerPtr->setIpcClient(ipcClient);

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

