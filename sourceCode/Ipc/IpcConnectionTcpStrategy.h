#ifndef _IPC_IPCCONNECTIONTCPSTRATEGY_H_
#define _IPC_IPCCONNECTIONTCPSTRATEGY_H_
#include "IIpcConnectionClientStrategy.h"
#include "IIpcMessageFactory.h"
#include "ITcpConnectionReceiver.h"
#include "Component.h"
#include "Macro.h"
#include <memory>
#include <string>

namespace Network {
class ITcpClient;
class ITcpServer;
}

namespace Ipc {

class IIpcConnectionReceiver;

enum class IpcConnectionType
{
    IpcConnection_None,
    IpcConnection_Server,
    IpcConnection_Client
};

std::string IpcConnectionTypeString(IpcConnectionType type);

class IpcConnectionTcpStrategy : public IIpcConnectionClientStrategy, public Network::ITcpConnectionReceiver
{
    IpcConnectionType type_;
    std::shared_ptr<IIpcConnectionReceiver> connectionReceiver_;
    std::shared_ptr<IpcMessage::IIpcMessageFactory> ipcMessageFactory_;
    std::shared_ptr<Network::ITcpClient> client_;
    std::shared_ptr<Network::ITcpServer> server_;
public:
    IpcConnectionTcpStrategy(IpcConnectionType type,
                             std::shared_ptr<IIpcConnectionReceiver> connectionReceiver,
                             std::shared_ptr<IpcMessage::IIpcMessageFactory> ipcMessageFactory,
                             std::shared_ptr<Network::ITcpClient> client,
                             std::shared_ptr<Network::ITcpServer> server);
    IpcConnectionTcpStrategy(IpcConnectionType type,
                             std::shared_ptr<Network::ITcpClient> client,
                             std::shared_ptr<Network::ITcpServer> server);
    virtual ~IpcConnectionTcpStrategy();
private:
    virtual void connect();
    virtual void send(const IpcMessage::IIpcMessage& msg);
    virtual void disconnect();
    virtual void setIpcConnectionReceiver(std::shared_ptr<IIpcConnectionReceiver> receiver);
    virtual void setIpcMessageFactory(std::shared_ptr<IpcMessage::IIpcMessageFactory> factory);

    virtual void onConnect();
    virtual void onReceive(Serialize::ReadBuffer& readBuffer);
    virtual void onDisconnect();

public:
     GETCLASSNAME(IpcConnectionTcpStrategy)
};

}

#endif // _IPC_IPCCONNECTIONTCPSTRATEGY_H_
