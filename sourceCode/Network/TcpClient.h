#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "ITcpClient.h"
#include "IEvent.h"
#include "TcpSocket.h"
#include "TcpState.h"
#include "Component.h"
#include "Macro.h"

namespace Network {

class TcpClient : public ITcpClient, public EventHandler::IEvent
{
    TcpSocket socket_;
    TcpState state_;
public:
    TcpClient(const IpSocketEndpoint& localEndpoint);
    ~TcpClient();
    virtual TcpClientResult init();
    virtual TcpClientResult connect(const IpSocketEndpoint& remodeEndpoint);
    virtual TcpClientResult send(const ITcpSendBuf&);
    virtual TcpClientResult receive(ITcpReceiveBuf&);
    virtual TcpClientResult disconnect();
    virtual TcpClientResult cleanup();
    virtual void run();

public:
     GETCLASSNAME(SocketImp)
};

}

#endif // TCPCLIENT_H
