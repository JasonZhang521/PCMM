#include "ClusterMgtBrieflyRequest.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace ClusterMgtMessage {
ClusterMgtBrieflyRequest::ClusterMgtBrieflyRequest()
{

}

ClusterMgtBrieflyRequest::~ClusterMgtBrieflyRequest()
{

}

void ClusterMgtBrieflyRequest::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessageType::IpcMessage_ClusterMgt));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ClusterMgtBrieflyRequestMessage));
    IpcMessage::IIpcMessage::write(writeBuffer);
}

void ClusterMgtBrieflyRequest::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
}

IpcMessage::IpcClusterMgtMessageType ClusterMgtBrieflyRequest::getClusterMgtType() const
{
    return IpcMessage::ClusterMgtBrieflyRequestMessage;
}

std::ostream& ClusterMgtBrieflyRequest::operator<< (std::ostream& os) const
{
    os << "[";
    IpcMessage::IIpcMessage::print(os);
    os << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_ClusterMgt)
       << ", clusterMgtType=" << IpcMessage::IpcClusterMgtTypeToString(IpcMessage::ClusterMgtBrieflyRequestMessage)
       << "]";
    return os;
}
}
