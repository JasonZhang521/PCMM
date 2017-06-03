#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "ITcpClient.h"
#include "IEvent.h"
#include "TcpSocket.h"
#include "TcpState.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "Component.h"
#include "Macro.h"

namespace Network {

class TcpClient : public ITcpClient, public EventHandler::IEvent
{
    uint64_t eventId_;
    TcpSocket socket_;
    TcpState state_;
    Serialize::WriteBuffer writeBuffer_;
    Serialize::ReadBuffer readBuffer_;
public:
    TcpClient(const IpSocketEndpoint& localEndpoint, const IpSocketEndpoint& remoteEndpoint);
    ~TcpClient();
    virtual TcpResult init();
    virtual TcpResult connect();
    virtual TcpResult send(const Serialize::WriteBuffer&);
    virtual TcpResult receive(Serialize::ReadBuffer&);
    virtual TcpResult disconnect();
    virtual TcpResult cleanup();
    virtual void run(EventHandler::EventFlag flag = EventHandler::EventFlag::Event_NoFlag);

public:
     GETCLASSNAME(SocketImp)
};

}

#endif // TCPCLIENT_H
