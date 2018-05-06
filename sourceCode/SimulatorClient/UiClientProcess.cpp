#include "UiClientProcess.h"
#include "UiClientHandler.h"
#include "UiIpcConnectionReceiver.h"
#include "ClientMessageSendTimer.h"
#include "DeviceClientHandler.h"
#include "DeviceClient.h"
#include "DeviceMessageThreadSafeQueue.h"
#include "IDeviceMessage.h"
#include "IoeZpConnectionReceiver.h"
#include "IoeZpClientManager.h"
#include "SystemMonitorMessageFactory.h"
#include "IpcClient.h"
#include "IpcConnectionTcpClientStrategy.h"
#include "IpcClientCreator.h"
#include "IpcLayerMessageFactory.h"
#include "IpcThreadSafeMessageQueue.h"
#include "IIpcMessage.h"
#include "TcpClient.h"
#include "IpSocketEndpoint.h"
#include "EventTimer.h"
#include "LoopMain.h"
#include "NetworkEnv.h"
#include "IpAddress.h"
#include "Trace.h"
#include "Configure.h"
#include <memory>
#include <thread>

namespace SimulatorClient {

UiClientProcess::UiClientProcess()
    : ipcMessageSendQueue_(new IpcMessage::IpcThreadSafeMessageQueue())
    , ipcMessageReceiveQueue_(new IpcMessage::IpcThreadSafeMessageQueue())
    , deviceMessageQueue_(new DeviceMessage::DeviceMessageThreadSafeQueue())
{

}

UiClientProcess::~UiClientProcess()
{
    Core::LoopMain::instance().loopStop();
    uiClientThread_->join();
}

void UiClientProcess::start()
{
     uiClientThread_ = std::unique_ptr<std::thread>(new std::thread(std::bind(&UiClientProcess::process, this)));
}
bool UiClientProcess::messageReceived()
{
    return !ipcMessageReceiveQueue_->isEmpty();
}

std::unique_ptr<IpcMessage::IIpcMessage> UiClientProcess::getOneMessage()
{
    if (!ipcMessageReceiveQueue_->isEmpty())
    {
        return ipcMessageReceiveQueue_->popFront();
    }
    else
    {
        return nullptr;
    }
}

void UiClientProcess::sendMessage(std::unique_ptr<IpcMessage::IIpcMessage> msg)
{
    ipcMessageSendQueue_->pushBack(std::move(msg));
}

void UiClientProcess::sendMessage(std::unique_ptr<DeviceMessage::IDeviceMessage> msg)
{
    deviceMessageQueue_->pushBack(std::move(msg));
}


void UiClientProcess::process()
{
    TRACE_NOTICE("Ui Client is starting!");
    // Local and remote endpoint.
    Network::IpSocketEndpoint uiLocalEndpoint("0.0.0.0:0");
    //Network::IpSocketEndpoint remoteEndpoint(std::string("127.0.0.1:23833"));
    Network::IpSocketEndpoint uiRemoteEndpoint(std::string("192.168.5.138:23833"));
    //Network::IpSocketEndpoint remoteEndpoint(std::string("116.236.169.100:23833"));
    // UiClientHandler
    std::shared_ptr<IUiClientHandler> uiClientHandler(new UiClientHandler());
    // UiClientConnectionReceiver
    std::shared_ptr<UiIpcConnectionReceiver>
            uiIpcConnectionReceiver(new UiIpcConnectionReceiver(uiClientHandler, ipcMessageReceiveQueue_));

    IpcMessageFactories factories;
    // System monitor factory
    factories.push_back(std::shared_ptr<IpcMessage::IIpcMessageFactory>(new SystemMonitorMessage::SystemMonitorMessageFactory()));
    factories.push_back(std::shared_ptr<IpcMessage::IIpcMessageFactory>(new IpcMessage::IpcLayerMessageFactory()));

    std::shared_ptr<Ipc::IIpcClient> ipcClient(Ipc::IpcClientCreator::CreateWithTcpClientStrategy(uiLocalEndpoint,
                                                                                                  uiRemoteEndpoint,
                                                                                                  uiIpcConnectionReceiver,
                                                                                                  factories));

    uiClientHandler->setIpcClient(ipcClient);
    uiClientHandler->startup();




    // Local and remote endpoint.
    Network::IpSocketEndpoint deviceLocalEndpoint("0.0.0.0:0");
    //Network::IpSocketEndpoint remoteEndpoint(std::string("127.0.0.1:23835"));
    Network::IpSocketEndpoint deviceRemoteEndpoint(std::string("192.168.5.138:23835"));
    //Network::IpSocketEndpoint remoteEndpoint(std::string("116.236.169.100:23835"));
    DeviceClientHandler deviceClientHandler;
    IoeZpClientManager ioeZpClientManager(deviceClientHandler);
    // Tcp client
    std::unique_ptr<Network::ITcpConnectionReceiver> ioeZpReceiver(new DeviceCommunication::IoeZpConnectionReceiver(deviceRemoteEndpoint, ioeZpClientManager));
    std::unique_ptr<Network::ITcpClient> tcpClient(new Network::TcpClient(deviceLocalEndpoint, deviceRemoteEndpoint, std::move(ioeZpReceiver)));
    std::shared_ptr<DeviceCommunication::IDeviceClient> deviceClient(new DeviceCommunication::DeviceClient(std::move(tcpClient)));

    deviceClientHandler.setDeviceClient(deviceClient);


    std::shared_ptr<ClientMessageSendTimer>
            clientMessageSendTimer(new ClientMessageSendTimer(ipcMessageSendQueue_, ipcClient, deviceMessageQueue_, deviceClient));
    Core::LoopMain::instance().registerTimer(clientMessageSendTimer.get());
    // run
    Core::LoopMain::instance().loopStart();
    TRACE_NOTICE("Ui Client has ended!");
}
}
