#ifndef _IPC_IPCCONNECTIONTCPSTRATEGY_H_
#define _IPC_IPCCONNECTIONTCPSTRATEGY_H_
#include "IIpcConnectionStrategy.h"

namespace Ipc {
class IpcConnectionTcpStrategy : public IIpcConnectionStrategy
{
public:
    IpcConnectionTcpStrategy();
    virtual ~IpcConnectionTcpStrategy();
    virtual void connect();
    virtual void send(Serialize::WriteBuffer& writeBuffer);
    virtual void disconnect();
};

}

#endif // _IPC_IPCCONNECTIONTCPSTRATEGY_H_
