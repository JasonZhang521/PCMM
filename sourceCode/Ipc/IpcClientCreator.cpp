#include "IpcClientCreator.h"
#include "IpcClient.h"
#include "IpcConnectionTcpClientStrategy.h"
#include "TcpClient.h"
#include "IpSocketEndpoint.h"

namespace Ipc {
IpcClientCreator::IpcClientCreator()
{
}

IIpcClient* IpcClientCreator::CreateWithTcpClientStrategy(const Network::IpSocketEndpoint& localEndpoint,
                                                          const Network::IpSocketEndpoint& remoteEndpoint,
                                                          std::shared_ptr<IIpcConnectionReceiver> receiver,
                                                          std::shared_ptr<IpcMessage::IIpcMessageFactory> factory)
{
    // Tcp client
    Network::TcpClient* tcpClientPtr = new Network::TcpClient(localEndpoint, remoteEndpoint);
    std::shared_ptr<Network::ITcpClient> tcpClient(tcpClientPtr);

    // Ipc client strategy
    Ipc::IpcConnectionTcpClientStrategy* ipcConnectionClientStrategyPtr =
            new Ipc::IpcConnectionTcpClientStrategy(tcpClient);
    std::shared_ptr<Ipc::IpcConnectionTcpClientStrategy> ipcConnectionClientStrategy(ipcConnectionClientStrategyPtr);

    // Ipc client
    Ipc::IpcClient* ipcClientPtr = new Ipc::IpcClient(ipcConnectionClientStrategy);

    // tcp connection receiver
    static_cast<Network::ITcpClient*>(tcpClientPtr)->setConnectionReceiver(ipcConnectionClientStrategy);

    // Set ipcConnectionTcpStrategy
    Ipc::IIpcConnectionClientStrategy* strategy = static_cast<Ipc::IIpcConnectionClientStrategy*>(ipcConnectionClientStrategyPtr);

    strategy->setIpcConnectionReceiver(receiver);
    strategy->addIpcMessageFactory(factory);

    return ipcClientPtr;
}

}
