#ifndef TCPSERVER_H
#define TCPSERVER_H
#include "ITcpServer.h"
#include "IEvent.h"
#include "TcpSocket.h"
#include "TcpState.h"
#include "Component.h"
#include "Macro.h"

namespace Network {

class TcpServer : public ITcpServer, public EventHandler::IEvent
{
    TcpSocket socket_;
    TcpState state_;
public:
    TcpServer(const IpSocketEndpoint& localEndpoint);
    ~TcpServer();
    virtual TcpResult init();
    virtual TcpResult listen(int backlog);
    virtual TcpResult accept(int flag);
    virtual TcpResult disconnect();
    virtual TcpResult cleanup();
    virtual void run();

public:
     GETCLASSNAME(SocketImp)
};

}

#endif // TCPSERVER_H
