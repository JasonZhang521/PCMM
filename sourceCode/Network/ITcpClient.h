#ifndef _NETWORK_ITCPCLIENT_H_
#define _NETWORK_ITCPCLIENT_H_

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace Network {

class TcpBuffer;
class IpSocketEndpoint;

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
    virtual TcpClientResult send(const Serialize::WriteBuffer&) = 0;
    virtual TcpClientResult receive(Serialize::ReadBuffer&) = 0;
    virtual TcpClientResult disconnect() = 0;
    virtual TcpClientResult cleanup() = 0;
};

}

#endif // ITCPCLIENT_H
