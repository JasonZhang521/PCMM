#include "IChatMessage.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace ChatSessionMessage {

IChatMessage::IChatMessage()
{
}

IChatMessage::~IChatMessage()
{
}

IpcMessage::IpcMessageType IChatMessage::getMessageType() const
{
    return IpcMessage::IpcMessage_ChatSession;
}

//Common function
const GroupDestination& IChatMessage::getGroupDestination() const
{
    return groupDestination_;
}

void IChatMessage::write(Serialize::WriteBuffer& writeBuffer) const
{
    uint32_t size = groupDestination_.size();
    writeBuffer.write(size);
    for (GroupDestination::const_iterator it = groupDestination_.cbegin(); it != groupDestination_.cend(); ++it)
    {
        it->serialize(writeBuffer);
    }
}
void IChatMessage::read(Serialize::ReadBuffer& readBuffer)
{
    GroupDestination groupDestination;
    uint32_t size = 0;
    readBuffer.read(size);
    for (uint32_t i = 0; i < size; ++i)
    {
        Network::IpSocketEndpoint endPoint;
        endPoint.unserialize(readBuffer);
        groupDestination.push_back(endPoint);
    }
    groupDestination_.swap(groupDestination);
}

void IChatMessage::print(std::ostream& os) const
{
    os << "groupDestination=[";
    for (GroupDestination::const_iterator it = groupDestination_.cbegin(); it != groupDestination_.cend(); ++it)
    {
        os << *it << ",";
    }
    os << "]";
}

}
