#ifndef _IPC_IPCCONNECTIONTX_H_
#define _IPC_IPCCONNECTIONTX_H_
#include "IConnectionTx.h"

namespace Ipc {

class IpcMessageReceiver : public Connection::IConnectionTx
{
public:
    IpcMessageReceiver();
    virtual ~IpcMessageReceiver();
protected:
    virtual void onConnect();
    virtual void onReceive(Serialize::ReadBuffer& readBuffer) = 0;
    virtual void onDisconnect();
};

}

#endif // _IPC_IPCCONNECTIONTX_H_
