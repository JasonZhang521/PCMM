#include "ChatTextMessage.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace ChatSessionMessage {
ChatTextMessage::ChatTextMessage()
{

}

ChatTextMessage::~ChatTextMessage()
{

}

void ChatTextMessage::setBuffer(const MessageBuffer& buffer)
{
    buffer_ = buffer;
}

const MessageBuffer& ChatTextMessage::getBuffer() const
{
    return buffer_;
}

void ChatTextMessage::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessage_ChatSession));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ChatTextMessage));
    IIpcMessage::write(writeBuffer);
    writeBuffer.write(buffer_.len());
    writeBuffer.write(buffer_.buffer(), buffer_.len());
}

void ChatTextMessage::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
    uint32_t len = 0;
    readBuffer.read(len);
    if (len > 0)
    {
        char* buffer = new char[len];
        readBuffer.read(buffer, len);
        buffer_ = MessageBuffer(len, buffer);
    }
}

IpcMessage::IpcChatMessageType ChatTextMessage::getChatMessageType() const
{
    return IpcMessage::ChatTextMessage;
}

std::ostream& ChatTextMessage::operator<< (std::ostream& os) const
{
    os << "["
       << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_ChatSession)
       << ", ipcChatMessageType=" << IpcMessage::IpcChatMessageTypeToString(IpcMessage::ChatTextMessage);
    IpcMessage::IIpcMessage::print(os);
    os << buffer_;
    return os;
}

}
