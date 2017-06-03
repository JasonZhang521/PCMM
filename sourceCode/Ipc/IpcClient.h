#ifndef IPCCLIENT_H
#define IPCCLIENT_H
#include "IConnectionRx.h"
namespace Ipc {

class IpcClient : public Connection::IConnectionRx
{
public:
    IpcClient();
    virtual ~IpcClient();
    virtual void connect();
    virtual void send(Serialize::WriteBuffer& writeBuffer);
    virtual void disconnect();
};

}

#endif // IPCCLIENT_H
