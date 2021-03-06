#include "IoeZpMessage.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "Number.h"
namespace DeviceMessage {

std::vector<uint16_t> IoeZpMessage::IoeZpResIdSet;

IoeZpMessage::IoeZpMessagePayload::IoeZpMessagePayload()
{
    initIoeZpResIdSet();
}

IoeZpMessage::IoeZpMessagePayload::~IoeZpMessagePayload()
{
}

std::string IoeZpMessage::IoeZpMessagePayload::modeName() const
{
    Number highByte((mode & 0xF0) >> 4);
    Number lowByte((mode & 0x0F));
    return "BZ" + highByte.getHexAlign() + lowByte.getHexAlign();
}

void IoeZpMessage::IoeZpMessagePayload::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(reserved);
    writeBuffer.write(netId);
    writeBuffer.write(extnum);
    writeBuffer.write(mode);
    writeBuffer.write(resIndex);
    writeBuffer.write(resOffset);
    writeBuffer.write(resLength);

    for (auto it = resources.begin(); it != resources.end(); ++it)
    {
        it->second.serialize(writeBuffer);
    }
}

void IoeZpMessage::IoeZpMessagePayload::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(reserved);
    readBuffer.read(netId);
    readBuffer.read(extnum);
    readBuffer.read(mode);
    readBuffer.read(resIndex);
    readBuffer.read(resOffset);
    readBuffer.read(resLength);
    for (uint16_t index : IoeZpResIdSet)
    {
        if (index & resIndex)
        {
            IoeZpResource resource(index);
            resource.unserialize(readBuffer);
            resources[index] = resource;
        }
    }
}

void IoeZpMessage::IoeZpMessagePayload::initIoeZpResIdSet()
{
    IoeZpResIdSet.push_back(USROPTS_BZ06);
    IoeZpResIdSet.push_back(DEVOPTS_BZ06);
    IoeZpResIdSet.push_back(RUNDATA_BZ06);
    IoeZpResIdSet.push_back(OUTCTL_BZ06);
}

void IoeZpMessage::IoeZpMessagePayload::print(std::ostream& os) const
{
    os << "["
       << "reserved=" << reserved
       << ", netId=" << netId
       << ", extnum=" << extnum
       << ", mode=" << mode
       << ", resIndex=" << resIndex
       << ", resOffset=" << resOffset
       << ", resLength=" << static_cast<int>(resLength);
    for (auto it = resources.begin(); it != resources.end(); ++it)
    {
        os << ", [index=" << it->first << ", resource=" << it->second << "]";
    }
    os << "]";
}

IoeZpMessage::IoeZpMessage()
{

}

IoeZpMessage::~IoeZpMessage()
{

}

void IoeZpMessage::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(header_);
    writeBuffer.write(length_);
    writeBuffer.write(length_Inverse_);
    writeBuffer.write(checkSum_);
    writeBuffer.write(cmd_);
    payload_.serialize(writeBuffer);
}

void IoeZpMessage::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(header_);
    readBuffer.read(length_);
    readBuffer.read(length_Inverse_);
    readBuffer.read(checkSum_);
    readBuffer.read(cmd_);
    payload_.unserialize(readBuffer);
}


DeviceMessageType IoeZpMessage::getMessageType()
{
    return DeviceMessageType::IoeZpType;
}

void IoeZpMessage::print(std::ostream& os) const
{
    os << "["
       << "header=" << header_
       << ", length=" << static_cast<int>(length_)
       << ", length_Inverse=" << static_cast<int>(length_Inverse_)
       << ", checkSum=" << checkSum_
       << ", cmd=" << cmd_
       << ", payload=";
    payload_.print(os);
    os << "]";
}

}
