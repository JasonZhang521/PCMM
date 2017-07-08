#include "IIpcMessage.h"
#include "IpcMessageIdGenerator.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "SocketWrapper.h"

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

const Network::IpSocketEndpoint& IIpcMessage::getSource() const
{
    return source_;
}
void IIpcMessage::setSource(const Network::IpSocketEndpoint& source)
{
    source_ = source;
}

const Network::IpSocketEndpoint& IIpcMessage::getDestnation() const
{
    return destination_;
}

void IIpcMessage::setDestnation(const Network::IpSocketEndpoint& destnation)
{
    destination_ = destnation;
}

void IIpcMessage::write(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(IoPlatformWrapper::Htonll(messageId_));
    source_.serialize(writeBuffer);
    destination_.serialize(writeBuffer);
}

void IIpcMessage::read(Serialize::ReadBuffer& readBuffer)
{
    uint64_t temp;
    readBuffer.read(temp);
    messageId_ = IoPlatformWrapper::Ntohll(temp);
    source_.unserialize(readBuffer);
    destination_.unserialize(readBuffer);
}

void IIpcMessage::print(std::ostream& os) const
{
    os << "["
       << "messageId=" << messageId_
       << ", source=" << source_
       << ", destination=" << destination_
       << "]";
}

}
