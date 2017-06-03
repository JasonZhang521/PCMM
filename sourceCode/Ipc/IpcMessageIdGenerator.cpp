#include "IpcMessageIdGenerator.h"

namespace Ipc {

uint64_t IpcMessageIdGenerator::ipcMessagetId_ = 0;

IpcMessageIdGenerator::IpcMessageIdGenerator()
{
}

uint64_t IpcMessageIdGenerator::generateIpcMessageId()
{
    return ipcMessagetId_++;
}

}
