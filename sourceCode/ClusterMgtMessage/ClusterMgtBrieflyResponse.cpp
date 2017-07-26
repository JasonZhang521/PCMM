#include "ClusterMgtBrieflyResponse.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
namespace ClusterMgtMessage {
ClusterMgtBrieflyResponse::ClusterMgtBrieflyResponse()
{

}

ClusterMgtBrieflyResponse::~ClusterMgtBrieflyResponse()
{

}

void ClusterMgtBrieflyResponse::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessageType::IpcMessage_ClusterMgt));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ClusterMgtBrieflyResponseMessage));
    IpcMessage::IIpcMessage::write(writeBuffer);
    systemInfoBriefly_.serialize(writeBuffer);
}
void ClusterMgtBrieflyResponse::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
    systemInfoBriefly_.unserialize(readBuffer);
}

IpcMessage::IpcClusterMgtMessageType ClusterMgtBrieflyResponse::getClusterMgtType() const
{
    return IpcMessage::ClusterMgtBrieflyResponseMessage;
}

std::ostream& ClusterMgtBrieflyResponse::operator<< (std::ostream& os) const
{
    os << "[";
    IpcMessage::IIpcMessage::print(os);
    os << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_ClusterMgt)
       << ", clusterMgtType=" << IpcMessage::IpcClusterMgtTypeToString(IpcMessage::ClusterMgtBrieflyResponseMessage)
       << ", systemInfoBriefly=" << systemInfoBriefly_
       << "]";
    return os;
}

void ClusterMgtBrieflyResponse::setSystemInfoBriefly(const Environment::SystemInfoBriefly& info)
{
    systemInfoBriefly_ = info;
}

const Environment::SystemInfoBriefly& ClusterMgtBrieflyResponse::getSystemInfoBriefly() const
{
    return systemInfoBriefly_;
}


}
