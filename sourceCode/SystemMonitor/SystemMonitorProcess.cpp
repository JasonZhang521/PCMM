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
    WSADATA wsaData;
    // Initialize Winsock
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return;
    }

    char hostName[100];
    memset(hostName, 0, 100);
    std::cout << "0" << std::endl;
    gethostname(hostName, 100);
    std::cout << "hostName = " << hostName << std::endl;

    struct hostent* host = gethostbyname(hostName);
    for (int i = 0;i<10 ;++i)
    {
        if (host->h_addr_list[i] == nullptr)
        {
            break;
        }
        const char* ipAddr = inet_ntoa(*((struct in_addr *)host->h_addr_list[i]));
        std::cout << "Ip address:" << ipAddr << std::endl;
    }
    struct addrinfo *result = NULL;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    std::cout << "2" << std::endl;
    iResult = getaddrinfo(NULL, "8000", &hints, &result);
    std::cout << "3" << std::endl;
     struct addrinfo *ptr = result;
    for (; ptr != nullptr; ptr = ptr->ai_next)
    {
        SocketAddressIn *addr = (SocketAddressIn*)(ptr->ai_addr);
        std::cout << "family:" << addr->sin_family
                  << ", addr:" << (int)addr->sin_addr.S_un.S_un_b.s_b1 << "."
                             << (int)addr->sin_addr.S_un.S_un_b.s_b2 << "."
                             << (int)addr->sin_addr.S_un.S_un_b.s_b3 << "."
                             << (int)addr->sin_addr.S_un.S_un_b.s_b4
                  << ", port:" << addr->sin_port << std::endl;
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

