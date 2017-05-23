#ifndef _NETWORK_TCPSTATE_H_
#define _NETWORK_TCPSTATE_H_

namespace Network {
enum class TcpState
{
    Tcp_Closed,
    Tcp_Connecting,
    Tcp_Listening,
    Tcp_Established
};

}

#endif // _NETWORK_TCPSTATE_H_
