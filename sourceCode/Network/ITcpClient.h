#ifndef _NETWORK_ITCPCLIENT_H_
#define _NETWORK_ITCPCLIENT_H_

namespace Network {

class ITcpSendBuf;
class ITcpReceiveBuf;

enum class TcpClientResult
{
    Success,
    Failed
};

class ITcpClient
{
public:
    ITcpClient();
    virtual ~ITcpClient();
    virtual TcpClientResult init() = 0;
    virtual TcpClientResult connect() = 0;
    virtual TcpClientResult send(const ITcpSendBuf&) = 0;
    virtual TcpClientResult receive(ITcpReceiveBuf&) = 0;
    virtual TcpClientResult disconnect() = 0;
    virtual TcpClientResult cleanup() = 0;
};

}

#endif // ITCPCLIENT_H
