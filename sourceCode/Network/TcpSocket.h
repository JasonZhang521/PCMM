#ifndef _NETWORK_TCPSOCKET_H
#define _NETWORK_TCPSOCKET_H
#include "SocketImp.h"
#include "IpSocketEndpoint.h"
#include "Component.h"
#include "Macro.h"

namespace Network {

class TcpSocket : public SocketImp
{
    IpSocketEndpoint localEndpoint_;
    IpSocketEndpoint remoteEndpoint_;
public:
    TcpSocket(const IpSocketEndpoint& localEndpoint, const IpSocketEndpoint& remoteEndpoint);
    inline const IpSocketEndpoint& getLocalEndpoint() const {return localEndpoint_;}
    inline const IpSocketEndpoint& getRemoteEndpoint() const {return remoteEndpoint_;}

    int bind() const;
    int connect() const;
    int accept(SocketFlag flags) const;

public:
     GETCLASSNAME(SocketImp)
};

}
#endif // _NETWORK_TCPSOCKET_H
