#include "TcpSocket.h"

namespace Network {

TcpSocket::TcpSocket(const IpSocketEndpoint& localEndpoint)
    :SocketImp(localEndpoint.getSocketAddressFamily(), SOCKET_SOCK_STREAM, SOCKET_IPPROTO_TCP)
    ,localEndpoint_(localEndpoint)
{

}

}
