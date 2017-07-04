#ifndef _IPC_IPCCONNECTIONTCPCLIENTSTRATEGY_H_
#define _IPC_IPCCONNECTIONTCPCLIENTSTRATEGY_H_
#include "IIpcConnectionClientStrategy.h"
#include "IIpcMessageFactory.h"
#include "ITcpConnectionReceiver.h"
#include "Component.h"
#include "Macro.h"
#include <memory>
#include <string>
#include <map>

namespace Network {
class ITcpClient;
}

namespace Ipc {

class IIpcConnectionReceiver;

class IpcConnectionTcpClientStrategy : public IIpcConnectionClientStrategy,
                                       public Network::ITcpConnectionReceiver
{
    std::shared_ptr<IIpcConnectionReceiver> connectionReceiver_;
    using IpcMessageFactroyMap = std::map<IpcMessage::IpcMessageType, std::shared_ptr<IpcMessage::IIpcMessageFactory> >;
    IpcMessageFactroyMap ipcMessageFactories_;
    std::shared_ptr<Network::ITcpClient> client_;
public:
    IpcConnectionTcpClientStrategy(std::shared_ptr<IIpcConnectionReceiver> connectionReceiver,
                                   IpcMessageFactroyMap ipcMessageFactories,
                                   std::shared_ptr<Network::ITcpClient> client);
    IpcConnectionTcpClientStrategy(std::shared_ptr<Network::ITcpClient> client);
    virtual ~IpcConnectionTcpClientStrategy();
private:
    virtual void connect();
    virtual void send(const IpcMessage::IIpcMessage& msg);
    virtual void disconnect();
    virtual void setIpcConnectionReceiver(std::shared_ptr<IIpcConnectionReceiver> receiver);
    virtual void addIpcMessageFactory(std::shared_ptr<IpcMessage::IIpcMessageFactory> factory);


    virtual void onConnect();
    virtual void onReceive(Serialize::ReadBuffer& readBuffer);
    virtual void onDisconnect();

public:
     GETCLASSNAME(IpcConnectionTcpClientStrategy)
};

}

#endif // _IPC_IPCCONNECTIONTCPCLIENTSTRATEGY_H_
