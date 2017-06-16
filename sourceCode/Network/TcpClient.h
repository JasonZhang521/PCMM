#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "ITcpClient.h"
#include "IEvent.h"
#include "TcpState.h"
#include "Component.h"
#include "Macro.h"
#include <memory>

namespace Serialize{
class WriteBuffer;
}

namespace Connection {
class IConnectionTx;
}

namespace Network {

class TcpSocket;

class TcpClient : public ITcpClient, public EventHandler::IEvent
{
    uint64_t eventId_;  
    TcpState state_;
    std::shared_ptr<TcpSocket> socket_;
    std::shared_ptr<Connection::IConnectionTx> connectionTx_;
public:
    TcpClient(const IpSocketEndpoint& localEndpoint,
              const IpSocketEndpoint& remoteEndpoint,
              std::shared_ptr<Connection::IConnectionTx> tx);
private:
    virtual ~TcpClient();
    virtual TcpResult init();
    virtual TcpResult connect();
    virtual TcpResult send(const Serialize::WriteBuffer&);
    virtual TcpResult receive();
    virtual TcpResult disconnect();
    virtual TcpResult cleanup();
    virtual void run(EventHandler::EventFlag flag = EventHandler::EventFlag::Event_NoFlag);

public:
     GETCLASSNAME(SocketImp)
};

}

#endif // TCPCLIENT_H
