#include "ChatAuthorizationResponse.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
namespace ChatSessionMessage {

std::string ChatAuthorizationResponse::resultToString(AuthorizationResult result)
{
    switch (result) {
    case Authorized:
        return std::string("Authorized");
    case WrongUserName:
        return std::string("WrongUserName");
    case WrongSecret:
        return std::string("WrongSecret");
    default:
        return std::string("Unknown");
    }
}

ChatAuthorizationResponse::ChatAuthorizationResponse()
{
}

ChatAuthorizationResponse::~ChatAuthorizationResponse()
{
}

void ChatAuthorizationResponse::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessage_ChatSession));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ChatAuthorizationResponse));
    IIpcMessage::write(writeBuffer);
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(result_));
}

void ChatAuthorizationResponse::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
    readBuffer.read(temp);
    result_ = static_cast<AuthorizationResult>(temp);
}

IpcMessage::IpcChatMessageType ChatAuthorizationResponse::getChatMessageType() const
{
    return IpcMessage::ChatAuthorizationResponse;
}

std::ostream& ChatAuthorizationResponse::operator<< (std::ostream& os) const
{
    os << "["
       << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_ChatSession)
       << ", ipcChatMessageType=" << IpcMessage::IpcChatMessageTypeToString(IpcMessage::ChatAuthorizationResponse);
    IpcMessage::IIpcMessage::print(os);
    os << ", result" << result_;
    return os;
}

}
