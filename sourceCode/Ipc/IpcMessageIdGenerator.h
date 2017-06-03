#ifndef _IPC_IPCMESSAGEIDGENERATOR_H_
#define _IPC_IPCMESSAGEIDGENERATOR_H_
#include <stdint.h>

namespace Ipc {

class IpcMessageIdGenerator
{
    static uint64_t ipcMessagetId_;
public:
    IpcMessageIdGenerator();
    static uint64_t generateIpcMessageId();
};

}

#endif // _IPC_IPCMESSAGEIDGENERATOR_H_
