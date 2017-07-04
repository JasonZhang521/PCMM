#ifndef IPCCLIENTCREATOR_H
#define IPCCLIENTCREATOR_H
#include <memory>
namespace Network {
class IpSocketEndpoint;
}

namespace IpcMessage {
class IIpcMessageFactory;
}
namespace Ipc {
class IIpcClient;
class IIpcConnectionReceiver;

class IpcClientCreator
{
public:
    IpcClientCreator();
    static IIpcClient* CreateWithTcpClientStrategy(const Network::IpSocketEndpoint& localEndPoint,
                                                   const Network::IpSocketEndpoint& remoteEndPoint,
                                                   std::shared_ptr<IIpcConnectionReceiver> receiver,
                                                   std::shared_ptr<IpcMessage::IIpcMessageFactory> factory);
};
}

#endif // IPCCLIENTCREATOR_H
