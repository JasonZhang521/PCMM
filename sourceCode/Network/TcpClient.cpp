#include "TcpClient.h"
#include "AppConst.h"
#include "Trace.h"

namespace Network {

TcpClient::TcpClient(const IpSocketEndpoint& localEndpoint)
    :socket_(localEndpoint)
    ,state_(TcpState::Tcp_Closed)
{
}

TcpClient::~TcpClient()
{
}

TcpClientResult TcpClient::init()
{
    socket_.init();
    return TcpClientResult::Success;
}

TcpClientResult TcpClient::connect(const IpSocketEndpoint& remoteEndpoint)
{
    TRACE_DEBUG("localEndpoint:" << socket_.getLocalEndpoint() << ", remoteEndpoint:" << remoteEndpoint);
    if (socket_.getLocalEndpoint().getSocketAddressFamily() != remoteEndpoint.getSocketAddressFamily())
    {
        TRACE_WARNING("localEndpoint address family is different from the remoteEndpoint, local = "
                      << socket_.getLocalEndpoint() << ", remote = " << remoteEndpoint);
        return TcpClientResult::Failed;
    }
    int ret = SOCKET_ERROR;
    if (IPFamilyType::IPFamilyV4 == remoteEndpoint.getSocketAddressFamily())
    {
        ret = Connect(socket_.getFd(),
                      reinterpret_cast<const SocketAddress*>(&remoteEndpoint.getIpAddress().getAddressIpv4()), sizeof(SocketAddress));
    }
    else if (IPFamilyType::IPFamilyV6)
    {
        ret = Connect(socket_.getFd(),
                      reinterpret_cast<const SocketAddress*>(&remoteEndpoint.getIpAddress().getAddressIpv6()), sizeof(SocketAddress));
    }

    if (SOCKET_ERROR == ret)
    {
        if (SOCKET_EINPROGRESS == GetLastSocketErrorNo())
        {
            state_ = TcpState::Tcp_Connecting;
            return TcpClientResult::Success;
        }
        else
        {
            return TcpClientResult::Failed;
        }
    }
    else
    {
        return TcpClientResult::Success;
    }
}

TcpClientResult TcpClient::send(const ITcpSendBuf&)
{

}

TcpClientResult TcpClient::receive(ITcpReceiveBuf&)
{

}

TcpClientResult TcpClient::disconnect()
{

}

TcpClientResult TcpClient::cleanup()
{

}

void TcpClient::run()
{

}

}
