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
#include <memory>

namespace SystemMonitor {

SystemMonitorProcess::SystemMonitorProcess()
{
}

void SystemMonitorProcess::process()
{
    // Tcp client
    Network::IpSocketEndpoint localEndpoint(std::string("192.168.5.1:5678"));
    Network::IpSocketEndpoint remoteEndpoint(std::string("192.168.5.138:6678"));
    Network::TcpClient* tcpClientPtr = new Network::TcpClient(localEndpoint, remoteEndpoint);
    std::shared_ptr<Network::TcpClient> tcpClient(tcpClientPtr);


    // Ipc client strategy
    Ipc::IpcConnectionTcpClientStrategy* ipcConnectionClientStrategyPtr =
            new Ipc::IpcConnectionTcpClientStrategy(tcpClient);
    std::shared_ptr<Ipc::IpcConnectionTcpClientStrategy> ipcConnectionClientStrategy(ipcConnectionClientStrategyPtr);

    // Ipc client
    Ipc::IpcClient* ipcClientPtr = new Ipc::IpcClient(ipcConnectionClientStrategy);
    std::shared_ptr<Ipc::IpcClient> ipcClient(ipcClientPtr);

    // SystemMonitorHandler
    SystemMonitorHandler* systemMonitorHandlerPtr = new SystemMonitorHandler(ipcClient);
    std::shared_ptr<SystemMonitorHandler> systemMonitorHandler(systemMonitorHandlerPtr);

    // SystemMonitorConnectionReceiver
    std::shared_ptr<SystemMonitorConnectionReceiver>
            systemMonitorConnectionReceiver(new SystemMonitorConnectionReceiver(systemMonitorHandler));


    // tcp connection receiver

    static_cast<Network::ITcpClient*>(tcpClientPtr)->setConnectionReceiver(ipcConnectionClientStrategy);

    // System monitor factory
    std::shared_ptr<IpcMessage::IIpcMessageFactory>
            factory(new SystemMonitorMessage::SystemMonitorMessageFactory());

    // Set ipcConnectionTcpStrategy
    static_cast<Ipc::IIpcConnectionClientStrategy*>(ipcConnectionClientStrategyPtr)->setIpcConnectionReceiver(systemMonitorConnectionReceiver);
    static_cast<Ipc::IIpcConnectionClientStrategy*>(ipcConnectionClientStrategyPtr)->setIpcMessageFactory(factory);

    // SystemInfoCollector
    SystemInfoCollector* systemInfoCollectorPtr = new SystemInfoCollector(systemMonitorHandler);
    std::shared_ptr<SystemInfoCollector> systemInfoCollector(systemInfoCollectorPtr);

    // EventTimer
    TimerHandler::EventTimer* timerPtr = new TimerHandler::EventTimer(5000, TimerHandler::TimerType::PeriodTimer, systemInfoCollectorPtr);
    std::unique_ptr<TimerHandler::EventTimer> eTimer(timerPtr);

    std::unique_ptr<Core::LoopMain> loopMain(new Core::LoopMain());
    loopMain->registerTimer(timerPtr);

    Io::IIoEvent* ioEvent = tcpClient.get();
    loopMain->registerIo(Io::IoFdType::IoFdRead, ioEvent);


    // run
    loopMain->loop();
}

}

