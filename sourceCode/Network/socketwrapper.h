#ifndef _NETWORK_SOCKETWRAPPER_H_
#define _NETWORK_SOCKETWRAPPER_H_
#include <string>
#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#define UNSUPPORTED_SOCKET_VERION 0X7FFFFFFF
#define SOCKET_SUCCESS 0

namespace Network {
#ifdef WIN32
// type
using SocketError = int;
using SocketHandle = SOCKET;
using SocketLength = int;
using SocketAddressFamily = int;
using SocketType = int;
using SocketProtocol = int;
using SocketAddress = struct sockaddr;
using SocketFlag = int;
using SocketDataSize = int;
using SocketDataBuffer = char*;
using SocketDataBufferSize = int;
using SocketShutDownFlag = int;
using SocketFdSet = fd_set;
using SocketTimeVal = struct timeval;

// const value
const SocketHandle InvalidSocketHandle = INVALID_SOCKET;

// Error Code
const SocketError SOCKET_NOTINITIALISED = WSANOTINITIALISED;
const SocketError SOCKET_NETDOWN = WSAENETDOWN;
const SocketError SOCKET_ADDRNOTAVAIL = WSAEADDRNOTAVAIL;
const SocketError SOCKET_EINVAL = WSAEINVAL;
const SocketError SOCKET_EHOSTUNREACH = WSAEHOSTUNREACH;
const SocketError SOCKET_ENOBUFS = WSAENOBUFS;
const SocketError SOCKET_EWOULDBLOCK = WSAEWOULDBLOCK;

const SocketError SOCKET_EACCES = WSAEACCES;
//const SocketError SOCKET_EPERM = EPERM;
const SocketError SOCKET_EADDRINUSE = WSAEADDRINUSE;
const SocketError SOCKET_EAFNOSUPPORT = WSAEAFNOSUPPORT;
//const SocketError SOCKET_EAGAIN = EAGAIN;
const SocketError SOCKET_EALREADY = WSAEALREADY;
//const SocketError SOCKET_EBADF = EBADF;
const SocketError SOCKET_ECONNREFUSED = WSAECONNREFUSED;
const SocketError SOCKET_EFAULT = WSAEFAULT;
const SocketError SOCKET_EINPROGRESS = WSAEINPROGRESS;
const SocketError SOCKET_EINTR = WSAEINTR;
const SocketError SOCKET_EISCONN = WSAEISCONN;
const SocketError SOCKET_ENETUNREACH = WSAENETUNREACH;
const SocketError SOCKET_ENOTSOCK = WSAENOTSOCK;
const SocketError SOCKET_ETIMEDOUT = WSAETIMEDOUT;
// Error Code end

// Socket Address Family
const SocketAddressFamily SOCKET_AF_UNSPEC = AF_UNSPEC;
const SocketAddressFamily SOCKET_AF_NETBIOS = AF_NETBIOS;
const SocketAddressFamily SOCKET_AF_IRDA = AF_IRDA;
const SocketAddressFamily SOCKET_AF_BTH = AF_BTH;
const SocketAddressFamily SOCKET_AF_INET = AF_INET;
const SocketAddressFamily SOCKET_AF_IPX = AF_IPX;
const SocketAddressFamily SOCKET_AF_APPLETALK = AF_APPLETALK;
const SocketAddressFamily SOCKET_AF_INET6 = AF_INET6;
// Socket Address Family end

// Socket Type
const SocketType SOCKET_SOCK_STREAM = SOCK_STREAM;
const SocketType SOCKET_SOCK_DGRAM = SOCK_DGRAM;
const SocketType SOCKET_SOCK_RAW = SOCK_RAW;
const SocketType SOCKET_SOCK_RDM = SOCK_RDM;
const SocketType SOCKET_SOCK_SEQPACKET = SOCK_SEQPACKET;
// Socket Type end

// Socket Protocol
const SocketProtocol SOCKET_IPPROTO_ICMP = IPPROTO_ICMP;
const SocketProtocol SOCKET_IPPROTO_IGMP = IPPROTO_IGMP;
//const SocketProtocol SOCKET_BTHPROTO_RFCOMM = BTHPROTO_RFCOMM;
const SocketProtocol SOCKET_IPPROTO_TCP = IPPROTO_TCP;
const SocketProtocol SOCKET_IPPROTO_UDP = IPPROTO_UDP;
const SocketProtocol SOCKET_IPPROTO_ICMPV6 = IPPROTO_ICMPV6;
//const SocketProtocol SOCKET_IPPROTO_RM = IPPROTO_RM;
// Socket Protocol end

// Socket Flag
const SocketFlag SOCKET_FLAG_NONE = 0;
const SocketFlag SOCKET_FLAG_MSG_DONTROUTE = MSG_DONTROUTE;
const SocketFlag SOCKET_FLAG_MSG_OOB = MSG_OOB;
// Socket Flag end

// Socket ShutDown Flag
const SocketShutDownFlag SOCKET_SD_RECEIVE = SD_RECEIVE;
const SocketShutDownFlag SOCKET_SD_SEND = SD_SEND;
const SocketShutDownFlag SOCKET_SD_BOTH = SD_BOTH;
// Socket ShutDown Flag end

int InitSocket();

inline int Cleanup()
{
    return ::WSACleanup();
}

inline Close(SocketHandle sockfd)
{
    return ::closesocket(sockfd);
}

int Accept(SocketHandle sockfd, SocketAddress* addr, SocketLength *addrlen, SocketFlag flags)
{
    static_cast<void>(flags);
    return ::accept(sockfd, addr, addrlen);
}

inline int GetLastSocketErrorNo()
{
    return ::WSAGetLastError();
}

std::string GetSocketErrorMessageFromErrorCode(int errorCode);
std::string GetLastSocketErrorMessage();

#else
// type
using SocketHandle = int;
using SocketLength = socklen_t;
using SocketAddressFamily = int;
using SocketType = int;
using SocketProtocol = int;
using SocketAddress = struct sockaddr;
using SocketFlag = int;
using SocketDataSize = ssize_t;
using SocketDataBuffer = void*;
using SocketDataBufferSize = ssize_t;
using SocketShutDownFlag = int;
using SocketFdSet = fd_set;
using SocketTimeVal = struct timeval;

// const value
const SocketHandle InvalidSocketHandle = -1;

// Error Code
const SocketError SOCKET_EACCES = EACCES;
const SocketError SOCKET_EPERM = EPERM;
const SocketError SOCKET_EADDRINUSE = EADDRINUSE;
const SocketError SOCKET_EAFNOSUPPORT = EAFNOSUPPORT;
const SocketError SOCKET_EAGAIN = EAGAIN;
const SocketError SOCKET_EALREADY = EALREADY;
const SocketError SOCKET_EBADF = EBADF;
const SocketError SOCKET_ECONNREFUSED = ECONNREFUSED;
const SocketError SOCKET_EFAULT = EFAULT;
const SocketError SOCKET_EINPROGRESS = EINPROGRESS;
const SocketError SOCKET_EINTR = EINTR;
const SocketError SOCKET_EISCONN = EISCONN;
const SocketError SOCKET_ENETUNREACH = ENETUNREACH;
const SocketError SOCKET_ENOTSOCK = ENOTSOCK;
const SocketError SOCKET_ETIMEDOUT = ETIMEDOUT;
// Error Code end

// Socket Address Family
const SocketAddressFamily SOCKET_AF_UNIX = AF_UNIX;
const SocketAddressFamily SOCKET_AF_LOCAL = AF_LOCAL;
const SocketAddressFamily SOCKET_AF_NETLINK  = AF_NETLINK;
const SocketAddressFamily SOCKET_AF_X25  = AF_X25;
const SocketAddressFamily SOCKET_AF_AX25 = AF_AX25;
const SocketAddressFamily SOCKET_AF_ATMPVC = AF_ATMPVC;
const SocketAddressFamily SOCKET_AF_PACKET = AF_PACKET;
const SocketAddressFamily SOCKET_AF_INET = AF_INET;
const SocketAddressFamily SOCKET_AF_IPX = AF_IPX;
const SocketAddressFamily SOCKET_AF_APPLETALK = AF_APPLETALK;
const SocketAddressFamily SOCKET_AF_INET6 = AF_INET6;
// Socket Address Family end

// Socket Type
const SocketType SOCKET_SOCK_STREAM = SOCK_STREAM;
const SocketType SOCKET_SOCK_DGRAM = SOCK_DGRAM;
const SocketType SOCKET_SOCK_RAW = SOCK_RAW;
const SocketType SOCKET_SOCK_RDM = SOCK_RDM;
const SocketType SOCKET_SOCK_SEQPACKET = SOCK_SEQPACKET;
const SocketType SOCKET_SOCK_NONBLOCK = SOCK_NONBLOCK;
const SocketType SOCKET_SOCK_CLOEXEC = SOCK_CLOEXEC;
// Socket Type end

// Socket Flag
const SocketFlag SOCKET_FLAG_NONE = 0;
const SocketFlag SOCKET_FLAG_MSG_CONFIRM = MSG_CONFIRM;
const SocketFlag SOCKET_FLAG_MSG_DONTROUTE = MSG_DONTROUTE;
const SocketFlag SOCKET_FLAG_MSG_DONTWAIT = MSG_DONTWAIT;
const SocketFlag SOCKET_FLAG_MSG_EOR = MSG_EOR;
const SocketFlag SOCKET_FLAG_MSG_MORE = MSG_MORE;
const SocketFlag SOCKET_FLAG_MSG_NOSIGNAL = MSG_NOSIGNAL;
const SocketFlag SOCKET_FLAG_MSG_OOB = MSG_OOB;
// Socket Flag end

// Socket Shutdown Flag
const SocketShutDownFlag SOCKET_SD_RECEIVE = SHUT_RD;
const SocketShutDownFlag SOCKET_SD_SEND = SHUT_WR;
const SocketShutDownFlag SOCKET_SD_BOTH = SHUT_RDWR;
// Socket Shutdown Flag end

inline int InitSocket()
{
    return SOCKET_SUCCESS;
}

inline int Cleanup()
{
    return 0;
}

intline Close(SocketHandle sockfd)
{
    return ::close(sockfd);
}

int Accept(SocketHandle sockfd, SocketAddress* addr, SocketLength *addrlen, SocketFlag flags)
{
    return ::accept(sockfd, addr, addrlen, flags);
}

inline int GetLastSocketErrorNo()
{
    return errno;
}

inline std::string GetSocketErrorMessageFromErrorCode(int errorCode)
{
    return strerror(errno);
}

std::string GetLastSocketErrorMessage()
{
    return getSocketErrorMessageFromErrorCode(getLastSocketErrorNo());
};

#endif

inline SocketHandle Socket(SocketAddressFamily addrFamily, SocketType type, SocketProtocol protocol)
{
    return ::socket(addrFamily, type, protocol);
}

inline int Connect(SocketHandle sockfd, const SocketAddress* addr, SocketLength addrLen)
{
    return ::connect(sockfd, addr, addrLen);
}

inline SocketDataSize Send(SocketHandle sockfd, const SocketDataBuffer buf, SocketDataBufferSize len, SocketFlag flags)
{
    return ::send(sockfd, buf, len, flags);
}

inline SocketDataSize Sendto(SocketHandle sockfd, const SocketDataBuffer buf, SocketDataBufferSize len, SocketFlag flags,
               const SocketAddress* dest_addr, SocketLength addrlen)
{
    return ::sendto(sockfd, buf, len, flags, dest_addr, addrlen);
}

inline SocketDataSize Recv(SocketHandle sockfd, SocketDataBuffer buf, SocketDataBufferSize len, SocketFlag flags)
{
    return ::recv(sockfd, buf, len, flags);
}

inline SocketDataSize Recvfrom(SocketHandle sockfd, SocketDataBuffer buf, SocketDataBufferSize len, SocketFlag flags,
                 SocketAddress* src_addr, SocketLength *addrlen)
{
    return ::recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
}

inline int Shutdown(SocketHandle sockfd, SocketShutDownFlag how)
{
    return ::shutdown(sockfd, how);
}

inline int Bind(SocketHandle sockfd, const SocketAddress* addr, SocketLength addrlen)
{
    return ::bind(sockfd, addr, addrlen);
}

inline int Listen(SocketHandle sockfd, int backlog)
{
    return ::listen(sockfd, backlog);
}

inline int Accept(SocketHandle sockfd, SocketAddress* addr, SocketLength *addrlen)
{
    return ::accept(sockfd, addr, addrlen);
}

inline int Select(int nfds, SocketFdSet* readfds, SocketFdSet* writefds,
           SocketFdSet* exceptfds, SocketTimeVal* timeout)
{
    return ::select(nfds, readfds, writefds, exceptfds, timeout);
}

inline void FdSet(SocketHandle sockfd, SocketFdSet* fds)
{
    FD_SET(sockfd, fds);
}

inline void FdZero(SocketFdSet* fds)
{
    FD_ZERO(fds);
}

inline void FdClear(SocketHandle sockfd, SocketFdSet* fds)
{
    FD_CLR(sockfd, fds);
}

inline void FdIsSet(SocketHandle sockfd, SocketFdSet* fds)
{
    FD_ISSET(sockfd, fds);
}

}


#endif // SOCKETWRAPPER_H
