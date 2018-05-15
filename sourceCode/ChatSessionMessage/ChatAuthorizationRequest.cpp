#include "ChatAuthorizationRequest.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace ChatSessionMessage {
ChatAuthorizationRequest::ChatAuthorizationRequest()
{

}

ChatAuthorizationRequest::~ChatAuthorizationRequest()
{
}

void ChatAuthorizationRequest::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessage_ChatSession));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ChatAuthorizationRequest));
    IpcMessage::IIpcMessage::write(writeBuffer);
    IChatMessage::write(writeBuffer);
    writeBuffer.write(userName_);
    writeBuffer.write(secret_);
}
void ChatAuthorizationRequest::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
    IChatMessage::read(readBuffer);
    readBuffer.read(userName_);
    readBuffer.read(secret_);
}

IpcMessage::IpcChatMessageType ChatAuthorizationRequest::getChatMessageType() const
{
    return IpcMessage::ChatAuthorizationRequest;
}
std::ostream& ChatAuthorizationRequest::operator<< (std::ostream& os) const
{
    os << "["
       << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_ChatSession)
       << ", ipcChatMessageType=" << IpcMessage::IpcChatMessageTypeToString(IpcMessage::ChatAuthorizationRequest);
    IpcMessage::IIpcMessage::print(os);
    os << ", userName_" << userName_
       << ", secret" << secret_;
    return os;
}
}
