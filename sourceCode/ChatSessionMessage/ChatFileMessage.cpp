#include "ChatFileMessage.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace ChatSessionMessage {
ChatFileMessage::ChatFileMessage()
{
}

ChatFileMessage::~ChatFileMessage()
{
}

void ChatFileMessage::setFileId(uint32_t fileId)
{
    fileId_ = fileId;
}

uint32_t ChatFileMessage::getFileId() const
{
    return fileId_;
}

void ChatFileMessage::setFilename(const std::string& fileName)
{
    fileName_ = fileName;
}

const std::string& ChatFileMessage::getFileName() const
{
    return fileName_;
}

void ChatFileMessage::setSequence(uint32_t sequence)
{
    sequence_ = sequence;
}

uint32_t ChatFileMessage::getSequence() const
{
    return sequence_;
}

void ChatFileMessage::setTotalFragment(uint32_t totalFragment)
{
    totalFragment_ = totalFragment;
}

uint32_t ChatFileMessage::getTotalFragment() const
{
    return totalFragment_;
}

void ChatFileMessage::setStartPos(uint32_t startPos)
{
    startPos_ = startPos;
}

uint32_t ChatFileMessage::getStartPos() const
{
    return startPos_;
}
void ChatFileMessage::setEndPos(uint32_t endPos)
{
    endPos_ = endPos;
}

uint32_t ChatFileMessage::getEndPos() const
{
    return endPos_;
}

void ChatFileMessage::setBuffer(const MessageBuffer& buffer)
{
    buffer_ = buffer;
}

const MessageBuffer& ChatFileMessage::getBuffer() const
{
    return buffer_;
}

void ChatFileMessage::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessage_ChatSession));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ChatFileMessage));
    IIpcMessage::write(writeBuffer);
    IChatMessage::write(writeBuffer);
    writeBuffer.write(fileId_);
    writeBuffer.write(fileName_);
    writeBuffer.write(sequence_);
    writeBuffer.write(totalFragment_);
    writeBuffer.write(startPos_);
    writeBuffer.write(endPos_);
    writeBuffer.write(buffer_.len());
    writeBuffer.write(buffer_.buffer(), buffer_.len());
}
void ChatFileMessage::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
    IChatMessage::read(readBuffer);
    readBuffer.read(fileId_);
    readBuffer.read(fileName_);
    readBuffer.read(sequence_);
    readBuffer.read(totalFragment_);
    readBuffer.read(startPos_);
    readBuffer.read(endPos_);
    uint32_t len = 0;
    readBuffer.read(len);
    if (len > 0)
    {
        char* buffer = new char[len];
        readBuffer.read(buffer, len);
        buffer_ = MessageBuffer(len, buffer);
    }
}

IpcMessage::IpcChatMessageType ChatFileMessage::getChatMessageType() const
{
    return IpcMessage::ChatFileMessage;
}
std::ostream& ChatFileMessage::operator<< (std::ostream& os) const
{
    os << "["
       << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_ChatSession)
       << ", ipcChatMessageType=" << IpcMessage::IpcChatMessageTypeToString(IpcMessage::ChatFileMessage);
    IpcMessage::IIpcMessage::print(os);
    os << ", fileId=" << fileId_
       << ", fileName=" << fileName_
       << ", sequence=" << sequence_
       << ", totalFragment=" << totalFragment_
       << ", startPos=" << startPos_
       << ", endPos=" << endPos_
       << ", buffer=" << buffer_;
    return os;
}

}
