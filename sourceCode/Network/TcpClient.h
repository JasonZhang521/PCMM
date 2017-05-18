#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "ITcpClient.h"
#include "IEvent.h"
#include "TcpSocket.h"

namespace Network {

class TcpClient : public ITcpClient, public EventHandler::IEvent
{
    TcpSocket socket_;
public:
    TcpClient(const IpSocketEndpoint& localEndpoint);
    ~TcpClient();
    virtual TcpClientResult init();
    virtual TcpClientResult connect();
    virtual TcpClientResult send(const ITcpSendBuf&);
    virtual TcpClientResult receive(ITcpReceiveBuf&);
    virtual TcpClientResult disconnect();
    virtual TcpClientResult cleanup();
    virtual void run();
};

}

#endif // TCPCLIENT_H
