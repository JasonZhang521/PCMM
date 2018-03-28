#include "ChatFileFragmentRequest.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace ChatSessionMessage {
ChatFileFragmentRequest::ChatFileFragmentRequest()
{

}
ChatFileFragmentRequest::~ChatFileFragmentRequest()
{

}

void ChatFileFragmentRequest::setFileId(uint32_t fileId)
{
    fileId_ = fileId;
}

uint32_t ChatFileFragmentRequest::getFileId() const
{
    return fileId_;
}

void ChatFileFragmentRequest::setFilename(const std::string& fileName)
{
    fileName_ = fileName;
}

const std::string& ChatFileFragmentRequest::getFileName() const
{
    return fileName_;
}

void ChatFileFragmentRequest::setSequence(uint32_t sequence)
{
    sequence_ = sequence;
}

uint32_t ChatFileFragmentRequest::getSequence() const
{
    return sequence_;
}

void ChatFileFragmentRequest::setStartPos(uint32_t startPos)
{
    startPos_ = startPos;
}

uint32_t ChatFileFragmentRequest::getStartPos() const
{
    return startPos_;
}
void ChatFileFragmentRequest::setEndPos(uint32_t endPos)
{
    endPos_ = endPos;
}

uint32_t ChatFileFragmentRequest::getEndPos() const
{
    return endPos_;
}

void ChatFileFragmentRequest::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessage_ChatSession));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ChatFileMessage));
    IIpcMessage::write(writeBuffer);
    writeBuffer.write(fileId_);
    writeBuffer.write(fileName_);
    writeBuffer.write(sequence_);
    writeBuffer.write(startPos_);
    writeBuffer.write(endPos_);
}
void ChatFileFragmentRequest::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
    readBuffer.read(fileId_);
    readBuffer.read(fileName_);
    readBuffer.read(sequence_);
    readBuffer.read(startPos_);
    readBuffer.read(endPos_);
}

IpcMessage::IpcChatMessageType ChatFileFragmentRequest::getChatMessageType() const
{
    return IpcMessage::ChatFileFragmentRequestMessage;
}
std::ostream& ChatFileFragmentRequest::operator<< (std::ostream& os) const
{
    os << "["
       << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_ChatSession)
       << ", ipcChatMessageType=" << IpcMessage::IpcChatMessageTypeToString(IpcMessage::ChatFileFragmentRequestMessage);
    IpcMessage::IIpcMessage::print(os);
    os << ", fileId=" << fileId_
       << ", fileName=" << fileName_
       << ", sequence=" << sequence_
       << ", startPos=" << startPos_
       << ", endPos=" << endPos_;

    return os;
}

}
