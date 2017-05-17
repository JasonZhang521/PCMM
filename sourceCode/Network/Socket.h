#ifndef _NETWORK_SOCKET_H_
#define _NETWORK_SOCKET_H_
#include "SocketWrapper.h"
#include "Component.h"
#include "Macro.h"

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

    inline int bind(const SocketAddress& address, SocketAddresstLength addrLen) const
    {
        return Bind(fd_, &address, addrLen);
    }

    inline int connect(const SocketAddress& address, SocketAddresstLength addrLen) const
    {
        return Connect(fd_, &address, addrLen);
    }

    inline int close()
    {
        return Close(fd_);
    }

    inline int shutdown(SocketShutDownFlag how) const
    {
        return Shutdown(fd_, how);
    }

    inline int accept(SocketAddress& addr, SocketAddresstLength& addrLen, SocketFlag flags)
    {
        return Accept(fd_, &addr, &addrLen, flags);
    }

    inline int listen(int backlog) const
    {
        return Listen(fd_, backlog);
    }

    inline int recv(SocketDataBuffer buf, SocketDataBufferSize bufLen, SocketFlag flags) const
    {
        return Recv(fd_, buf, bufLen, flags);
    }

    inline int recvFrom(SocketDataBuffer buf, SocketDataBufferSize bufLen, SocketFlag flags,
                 SocketAddress& srcAddr, SocketAddresstLength& addrLen) const
    {
        return RecvFrom(fd_, buf, bufLen, flags, &srcAddr, &addrLen);
    }

    inline int send(const SocketDataBuffer buf, SocketDataBufferSize bufLen, SocketFlag flags) const
    {
        return Send(fd_, buf, bufLen, flags);
    }

    inline int sendTo(const SocketDataBuffer buf, SocketDataBufferSize bufLen, SocketFlag flags,
               const SocketAddress& destAddr, SocketAddresstLength addrLen) const
    {
        return SendTo(fd_, buf, bufLen, flags, &destAddr, addrLen);
    }

    inline int setsockopt(SocketOptLevel level, SocketOptName optname,
                          const SocketOptVal optval, SocketOptLength optlen)
    {
        return SetSockOpt(fd_, level, optname, optval, optlen);
    }

    inline int getsockopt(SocketOptLevel level, SocketOptName optname,
                          SocketOptVal optval, SocketOptLength* optlen)
    {
        return GetSockOpt(fd_, level, optname, optval, optlen);
    }

    inline int getsockname(SocketAddress& addr, SocketAddresstLength& addrLen)
    {
        return GetSockName(fd_, &addr, &addrLen);
    }

public:
     GETCLASSNAME(Socket)
};

}

#endif // _NETWORK_SOCKET_H_
