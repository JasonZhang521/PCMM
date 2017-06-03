#ifndef _IPC_IIPCCONNECTIONSTRATEGY_H_
#define _IPC_IIPCCONNECTIONSTRATEGY_H_

namespace Serialize {
class WriteBuffer;
}

namespace Ipc {

class IIpcConnectionStrategy
{
public:
    IIpcConnectionStrategy();
    virtual ~IIpcConnectionStrategy();
    virtual void connect() = 0;
    virtual void send(Serialize::WriteBuffer& writeBuffer) = 0;
    virtual void disconnect() = 0;
};

}

#endif // _IPC_IIPCCONNECTIONSTRATEGY_H_
