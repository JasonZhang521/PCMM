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

const std::string& IIpcMessage::getDestnation() const
{
    return destnation_;
}

void IIpcMessage::setDestnation(const std::string& destnation)
{
    destnation_ = destnation;
}

}
