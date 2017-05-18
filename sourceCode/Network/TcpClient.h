#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "ITcpClient.h"

namespace Network {

class TcpClient : public ITcpClient
{
public:
    TcpClient();
};

}

#endif // TCPCLIENT_H
