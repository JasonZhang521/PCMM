#ifndef _IPC_IPCCLIENT_H_
#define _IPC_IPCCLIENT_H_
#include "IConnectionRx.h"
#include "Component.h"
#include "Macro.h"
#include <memory>
namespace Ipc {

class IIpcConnectionClientStrategy;

class IpcClient : public Connection::IConnectionRx
{
    std::shared_ptr<IIpcConnectionClientStrategy> strategy_;
public:
    IpcClient(std::shared_ptr<IIpcConnectionClientStrategy> strategy);
private:
    virtual ~IpcClient();
    virtual void connect();
    virtual void send(Serialize::WriteBuffer& writeBuffer);
    virtual void disconnect();

public:
     GETCLASSNAME(IpcClient)
};

}

#endif // _IPC_IPCCLIENT_H_
