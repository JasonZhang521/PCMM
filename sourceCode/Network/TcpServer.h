#ifndef TCPSERVER_H
#define TCPSERVER_H
#include "ITcpServer.h"
#include "ITcpClient.h"
#include "IEvent.h"
#include "TcpSocket.h"
#include "TcpState.h"
#include "Component.h"
#include "Macro.h"
#include <vector>

namespace Network {

class TcpServer : public ITcpServer, public EventHandler::IEvent
{
    uint64_t eventId_;
    TcpSocket socket_;
    TcpState state_;
    using Clients = std::vector<ITcpClient*>;
    Clients clients_;
public:
    TcpServer(const IpSocketEndpoint& localEndpoint);
    ~TcpServer();
    virtual TcpResult init();
    virtual TcpResult listen(int backlog);
    virtual TcpResult accept(int flag);
    virtual TcpResult disconnect();
    virtual TcpResult cleanup();
    virtual void run(EventHandler::EventFlag flag = EventHandler::EventFlag::Event_NoFlag);

public:
     GETCLASSNAME(SocketImp)
};

}

#endif // TCPSERVER_H
