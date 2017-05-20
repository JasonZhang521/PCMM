#include "TcpSocket.h"
#include "Trace.h"

namespace Network {

TcpSocket::TcpSocket(const IpSocketEndpoint& localEndpoint, const IpSocketEndpoint& remoteEndpoint)
    :SocketImp(localEndpoint.getSocketAddressFamily(), SOCKET_SOCK_STREAM, SOCKET_IPPROTO_TCP)
    ,localEndpoint_(localEndpoint), remoteEndpoint_(remoteEndpoint)
{
    TRACE_DEBUG("localEndpoint:" << localEndpoint << ", remoteEndpoint:" << remoteEndpoint);
    if (localEndpoint_.getSocketAddressFamily() == IPFamilyType::IPFamilyInvalid ||
        localEndpoint_.getSocketAddressFamily() != remoteEndpoint_.getSocketAddressFamily())
    {
        TRACE_ERROR("localEndpoint address family is different from the remoteEndpoint, local = "
                    << localEndpoint_ << ", remote = " << remoteEndpoint_);
        throw std::invalid_argument(std::string("address family is different between local and remote ip address"));
    }
}

int TcpSocket::bind() const
{
    if (IPFamilyType::IPFamilyV4 == localEndpoint_.getSocketAddressFamily())
    {
        return SocketImp::bind(reinterpret_cast<const SocketAddress*>(&localEndpoint_.getIpAddress().getAddressIpv4()), sizeof(SocketAddress));
    }
    else if(IPFamilyType::IPFamilyV6 == localEndpoint_.getSocketAddressFamily())
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
    if (IPFamilyType::IPFamilyV4 == remoteEndpoint_.getSocketAddressFamily())
    {
        return SocketImp::connect(reinterpret_cast<const SocketAddress*>(&remoteEndpoint_.getIpAddress().getAddressIpv4()), sizeof(SocketAddress));
    }
    else if(IPFamilyType::IPFamilyV6 == remoteEndpoint_.getSocketAddressFamily())
    {
       return SocketImp::connect(reinterpret_cast<const SocketAddress*>(&remoteEndpoint_.getIpAddress().getAddressIpv6()), sizeof(SocketAddress));
    }
    else
    {
        TRACE_ERROR("remoteEndpoint address family is invalid");
        throw std::invalid_argument(std::string("remote address family is invalid"));
    }
}

int TcpSocket::accept(SocketFlag flags) const
{
    if (IPFamilyType::IPFamilyV4 == remoteEndpoint_.getSocketAddressFamily())
    {
        SocketInetAddress address = remoteEndpoint_.getIpAddress().getAddressIpv4();
        return SocketImp::accept(reinterpret_cast<SocketAddress*>(&address), sizeof(SocketAddress), flags);
    }
    else if(IPFamilyType::IPFamilyV6 == remoteEndpoint_.getSocketAddressFamily())
    {
       SocketInet6Address address = remoteEndpoint_.getIpAddress().getAddressIpv6();
       return SocketImp::accept(reinterpret_cast<SocketAddress*>(&address), sizeof(SocketAddress), flags);
    }
    else
    {
        TRACE_ERROR("remoteEndpoint address family is invalid");
        throw std::invalid_argument(std::string("remote address family is invalid"));
    }
}

}
