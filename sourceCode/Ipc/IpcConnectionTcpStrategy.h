#ifndef _IPC_IPCCONNECTIONTCPSTRATEGY_H_
#define _IPC_IPCCONNECTIONTCPSTRATEGY_H_
#include "IIpcConnectionClientStrategy.h"
#include "Component.h"
#include "Macro.h"
#include <memory>
#include <string>

namespace Network {
class ITcpClient;
class ITcpServer;
}

namespace Ipc {

enum class IpcConnectionType
{
    IpcConnection_Server,
    IpcConnection_Client
};

std::string IpcConnectionTypeString(IpcConnectionType type);

class IpcConnectionTcpStrategy : public IIpcConnectionClientStrategy
{
    IpcConnectionType type_;
    std::shared_ptr<Network::ITcpClient> client_;
    std::shared_ptr<Network::ITcpServer> server_;
public:
    IpcConnectionTcpStrategy(IpcConnectionType type,
                             std::shared_ptr<Network::ITcpClient> client,
                             std::shared_ptr<Network::ITcpServer> server);
private:
    virtual ~IpcConnectionTcpStrategy();
    virtual void connect();
    virtual void send(Serialize::WriteBuffer& writeBuffer);
    virtual void disconnect();

public:
     GETCLASSNAME(IpcConnectionTcpStrategy)
};

}

#endif // _IPC_IPCCONNECTIONTCPSTRATEGY_H_
