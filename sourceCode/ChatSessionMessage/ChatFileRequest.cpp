#include "ChatFileRequest.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace ChatSessionMessage {
ChatFileRequest::ChatFileRequest()
{

}

ChatFileRequest::~ChatFileRequest()
{

}
void ChatFileRequest::setFileId(uint32_t fileId)
{
    fileId_ = fileId;
}

uint32_t ChatFileRequest::getFileId() const
{
    return fileId_;
}

void ChatFileRequest::setFilename(const std::string& fileName)
{
    fileName_ = fileName;
}

const std::string& ChatFileRequest::getFileName() const
{
    return fileName_;
}

void ChatFileRequest::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessage_ChatSession));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ChatFileMessage));
    IIpcMessage::write(writeBuffer);
    writeBuffer.write(fileId_);
    writeBuffer.write(fileName_);
}
void ChatFileRequest::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
    readBuffer.read(fileId_);
    readBuffer.read(fileName_);
}

IpcMessage::IpcChatMessageType ChatFileRequest::getChatMessageType() const
{
    return IpcMessage::ChatFileFragmentRequestMessage;
}
std::ostream& ChatFileRequest::operator<< (std::ostream& os) const
{
    os << "["
       << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_ChatSession)
       << ", ipcChatMessageType=" << IpcMessage::IpcChatMessageTypeToString(IpcMessage::ChatFileFragmentRequestMessage);
    IpcMessage::IIpcMessage::print(os);
    os << ", fileId=" << fileId_
       << ", fileName=" << fileName_;

    return os;
}
}
