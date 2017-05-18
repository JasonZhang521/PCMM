#include "TcpClient.h"

namespace Network {

TcpClient::TcpClient(const IpSocketEndpoint& localEndpoint)
    :socket_(localEndpoint)
{
}

TcpClient::~TcpClient()
{
}

}
