#ifndef _NETWORK_TCPSOCKET_H
#define _NETWORK_TCPSOCKET_H
#include "SocketImp.h"
#include "IpSocketEndpoint.h"

namespace Network {

class TcpSocket : public SocketImp
{
    IpSocketEndpoint localEndpoint_;
public:
    TcpSocket(const IpSocketEndpoint& localEndpoint);
    const IpSocketEndpoint& getLocalEndpoint() const {return localEndpoint_;}
};

}
#endif // _NETWORK_TCPSOCKET_H
