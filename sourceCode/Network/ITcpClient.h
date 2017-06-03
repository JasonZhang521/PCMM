#ifndef _NETWORK_ITCPCLIENT_H_
#define _NETWORK_ITCPCLIENT_H_
#include "TcpResult.h"

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace Network {

class TcpBuffer;
class IpSocketEndpoint;

class ITcpClient
{
public:
    ITcpClient();
    virtual ~ITcpClient();
    virtual TcpResult init() = 0;
    virtual TcpResult connect() = 0;
    virtual TcpResult send(const Serialize::WriteBuffer&) = 0;
    virtual TcpResult receive() = 0;
    virtual TcpResult disconnect() = 0;
    virtual TcpResult cleanup() = 0;
};

}

#endif // ITCPCLIENT_H
