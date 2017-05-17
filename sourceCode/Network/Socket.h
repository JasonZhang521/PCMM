#ifndef _NETWORK_SOCKET_H_
#define _NETWORK_SOCKET_H_
#include "SocketWrapper.h"

namespace Network {
class Socket
{
    SocketAddressFamily addrFamily_;
    SocketType type_;
    SocketProtocol protocol_;
    SocketHandle fd_;
public:
    Socket(const SocketAddressFamily& addrFamily,
           const SocketType& type,
           const SocketProtocol& protocol);
    ~Socket();

    std::string getErrorInfo();
};

}

#endif // _NETWORK_SOCKET_H_
