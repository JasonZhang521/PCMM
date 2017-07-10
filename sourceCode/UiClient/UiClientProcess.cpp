#include "UiClientProcess.h"
#include "UiClientHandler.h"
#include "UiIpcConnectionReceiver.h"
#include "SystemMonitorMessageFactory.h"
#include "IpcClient.h"
#include "IpcConnectionTcpClientStrategy.h"
#include "IpcClientCreator.h"
#include "IpcLayerMessageFactory.h"
#include "TcpClient.h"
#include "IpSocketEndpoint.h"
#include "EventTimer.h"
#include "LoopMain.h"
#include "NetworkEnv.h"
#include "IpAddress.h"
#include "Trace.h"
#include <memory>

namespace UiClient {

UiClientProcess::UiClientProcess()
{

}

void UiClientProcess::process()
{
    TRACE_NOTICE("Ui Client is starting!");
    // Local and remote endpoint.
    Network::IpSocketEndpoint localEndpoint("0.0.0.0:0");
    Network::IpSocketEndpoint remoteEndpoint(std::string("127.0.0.1:23832"));
    //Network::IpSocketEndpoint remoteEndpoint(std::string("192.168.5.138:23832"));
    // SystemMonitorHandler
    UiClientHandler* uiClientHandlerPtr = new UiClientHandler();
    std::shared_ptr<IUiClientHandler> uiClientHandler(uiClientHandlerPtr);

    // SystemMonitorConnectionReceiver
    std::shared_ptr<UiIpcConnectionReceiver>
            uiIpcConnectionReceiver(new UiIpcConnectionReceiver(uiClientHandler));

    IpcMessageFactories factories;
    // System monitor factory
    factories.push_back(std::shared_ptr<IpcMessage::IIpcMessageFactory>(new SystemMonitorMessage::SystemMonitorMessageFactory()));
    factories.push_back(std::shared_ptr<IpcMessage::IIpcMessageFactory>(new IpcMessage::IpcLayerMessageFactory()));

    Ipc::IIpcClient* ipcClientPtr = Ipc::IpcClientCreator::CreateWithTcpClientStrategy(localEndpoint, remoteEndpoint, uiIpcConnectionReceiver, factories);
    std::shared_ptr<Ipc::IIpcClient> ipcClient(ipcClientPtr);

    uiClientHandler->setIpcClient(ipcClient);
    uiClientHandler->startup();
    // run
    Core::LoopMain::instance().loop();
    TRACE_NOTICE("Ui Client has ended!");
}
}
