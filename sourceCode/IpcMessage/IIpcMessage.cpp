#include "IIpcMessage.h"
#include "IpcMessageIdGenerator.h"

namespace IpcMessage {


IIpcMessage::IIpcMessage()
    :messageId_(IpcMessageIdGenerator::generateIpcMessageId())
{
}

IIpcMessage::~IIpcMessage()
{
}

uint64_t IIpcMessage::getMessageId() const
{
    return messageId_;
}

}
