#include "TcpSocket.h"
#include "Trace.h"
#include <sstream>

namespace Network {

TcpSocket::TcpSocket(const IpSocketEndpoint& localEndpoint)
    :SocketImp(localEndpoint.getSocketAddressFamily(), SOCKET_SOCK_STREAM, SOCKET_IPPROTO_TCP)
    ,type_(TcpSocketType::TcpServer)
    ,localEndpoint_(localEndpoint)
{
    setBlocking(false);
}

TcpSocket::TcpSocket(const SocketHandle& fd,
                     const IpSocketEndpoint& localEndpoint,
                     const IpSocketEndpoint& remoteEndpoint)
    :SocketImp(localEndpoint.getSocketAddressFamily(), SOCKET_SOCK_STREAM, SOCKET_IPPROTO_TCP, fd)
    ,type_(TcpSocketType::TcpServerClient)
    ,localEndpoint_(localEndpoint)
    ,remoteEndpoint_(remoteEndpoint)
{
    TRACE_DEBUG("localEndpoint:" << localEndpoint << ", remoteEndpoint:" << remoteEndpoint);
    if (localEndpoint_.getIpFamilyType() == IPFamilyType::IPFamilyInvalid ||
        localEndpoint_.getIpFamilyType() != remoteEndpoint_.getIpFamilyType())
    {
        TRACE_ERROR("localEndpoint address family is different from the remoteEndpoint, local = "
                    << localEndpoint_ << ", remote = " << remoteEndpoint_);
        throw std::invalid_argument(std::string("address family is different between local and remote ip address"));
    }
    setBlocking(false);
}

TcpSocket::TcpSocket(const IpSocketEndpoint& localEndpoint, const IpSocketEndpoint& remoteEndpoint)
    :SocketImp(localEndpoint.getSocketAddressFamily(), SOCKET_SOCK_STREAM, SOCKET_IPPROTO_TCP)
    ,type_(TcpSocketType::TcpClient)
    ,localEndpoint_(localEndpoint)
    ,remoteEndpoint_(remoteEndpoint)
{
    TRACE_DEBUG("localEndpoint:" << localEndpoint << ", remoteEndpoint:" << remoteEndpoint);
    if (localEndpoint_.getIpFamilyType() == IPFamilyType::IPFamilyInvalid ||
        localEndpoint_.getIpFamilyType() != remoteEndpoint_.getIpFamilyType())
    {
        TRACE_ERROR("localEndpoint address family is different from the remoteEndpoint, local = "
                    << localEndpoint_ << ", remote = " << remoteEndpoint_);
        throw std::invalid_argument(std::string("address family is different between local and remote ip address"));
    }
    setBlocking(false);
}

TcpSocket::~TcpSocket()
{
}

int TcpSocket::bind() const
{
    TRACE_ENTER();
    if (IPFamilyType::IPFamilyV4 == localEndpoint_.getIpFamilyType())
    {
        return SocketImp::bind(reinterpret_cast<const SocketAddress*>(&localEndpoint_.getIpAddress().getAddressIpv4()), sizeof(SocketAddress));
    }
    else if(IPFamilyType::IPFamilyV6 == localEndpoint_.getIpFamilyType())
    {
       return SocketImp::bind(reinterpret_cast<const SocketAddress*>(&localEndpoint_.getIpAddress().getAddressIpv6()), sizeof(SocketAddress));
    }
    else
    {
        TRACE_ERROR("localEndpoint address family is invalid");
        throw std::invalid_argument(std::string("local address family is invalid"));
    }
}

int TcpSocket::connect() const
{
    TRACE_ENTER();
    if (IPFamilyType::IPFamilyV4 == remoteEndpoint_.getIpFamilyType())
    {
        return SocketImp::connect(reinterpret_cast<const SocketAddress*>(&remoteEndpoint_.getIpAddress().getAddressIpv4()), sizeof(SocketAddress));
    }
    else if(IPFamilyType::IPFamilyV6 == remoteEndpoint_.getIpFamilyType())
    {
       return SocketImp::connect(reinterpret_cast<const SocketAddress*>(&remoteEndpoint_.getIpAddress().getAddressIpv6()), sizeof(SocketAddress));
    }
    else
    {
        TRACE_ERROR("remoteEndpoint address family is invalid");
        throw std::invalid_argument(std::string("remote address family is invalid"));
    }
}

int TcpSocket::accept(IpSocketEndpoint& remoteEndPoint, SocketFlag flags) const
{
    TRACE_ENTER();
    if (IPFamilyType::IPFamilyV4 == localEndpoint_.getIpFamilyType())
    {
        SocketAddresstLength len = 0;
        SocketAddress address;

        int fd = SocketImp::accept(&address, &len, flags);
        remoteEndPoint = IpSocketEndpoint(IpAddress(IoPlatformWrapper::getInetAddressFromSocketAddress(address)),
                                          IpPort(IoPlatformWrapper::SocketAddressToAddressIn(address).sin_port));
        return fd;
    }
    else if(IPFamilyType::IPFamilyV6 == localEndpoint_.getIpFamilyType())
    {
        SocketAddress address;
        SocketAddresstLength len = 0;
        int fd = SocketImp::accept(&address, &len, flags);
        remoteEndPoint = IpSocketEndpoint(IpAddress(IoPlatformWrapper::getInet6AddressFromSocketAddress(address)),
                                          IpPort(IoPlatformWrapper::SocketAddressToAddressIn6(address).sin6_port));
        return fd;
    }
    else
    {
        TRACE_ERROR("remoteEndpoint address family is invalid");
        throw std::invalid_argument(std::string("remote address family is invalid"));
    }
}

std::string TcpSocket::toString() const
{
    std::stringstream ss;
    ss << "["
       << SocketImp::toString()
       << "[tcpType=" << static_cast<int>(type_) << ", localEndpoint=" << localEndpoint_.toString() << "remoteEndpoint=" << remoteEndpoint_.toString() << "]"
       << "]";
    return ss.str();
}

std::ostream& TcpSocket::operator<< (std::ostream& os) const
{
    os << toString();
    return os;
}

std::ostream& operator<< (std::ostream& os, const TcpSocket& socket)
{
    return socket.operator <<(os);
}

}
