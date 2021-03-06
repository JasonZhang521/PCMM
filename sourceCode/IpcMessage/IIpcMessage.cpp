#include "IIpcMessage.h"
#include "IpcMessageIdGenerator.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "SocketWrapper.h"

namespace IpcMessage {


IIpcMessage::IIpcMessage()
    : messageLength_(0)
    , messageId_(IpcMessageIdGenerator::generateIpcMessageId())
    , hostName_(PlatformWrapper::GetHostName())
{
}

IIpcMessage::~IIpcMessage()
{
}

uint32_t IIpcMessage::getMessageLength() const
{
    return messageLength_;
}

void IIpcMessage::setMessageLength(uint32_t len)
{
    messageLength_ = len;
}

uint64_t IIpcMessage::getMessageId() const
{
    return messageId_;
}

const std::string& IIpcMessage::getHostName() const
{
    return hostName_;
}

void IIpcMessage::setHostName(const std::string& hostName)
{
    hostName_ = hostName;
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
    writeBuffer.write(messageLength_);
    writeBuffer.write(messageId_);
    writeBuffer.write(hostName_);
    source_.serialize(writeBuffer);
    destination_.serialize(writeBuffer);
}

void IIpcMessage::read(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(messageLength_);
    readBuffer.read(messageId_);
    readBuffer.read(hostName_);
    source_.unserialize(readBuffer);
    destination_.unserialize(readBuffer);
}

void IIpcMessage::print(std::ostream& os) const
{
    os << "["
       << "messageLength=" << messageLength_
       << ", messageId=" << messageId_
       << ", hostName=" << hostName_
       << ", source=" << source_
       << ", destination=" << destination_
       << "]";
}

}
