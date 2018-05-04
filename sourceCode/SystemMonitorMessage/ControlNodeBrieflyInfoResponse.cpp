#include "ControlNodeBrieflyInfoResponse.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "IpSocketEndpoint.h"
namespace SystemMonitorMessage {
ControlNodeBrieflyInfoResponse::ControlNodeBrieflyInfoResponse()
{

}

ControlNodeBrieflyInfoResponse::~ControlNodeBrieflyInfoResponse()
{

}

void ControlNodeBrieflyInfoResponse::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::IpcMessageType::IpcMessage_SystemMonitor));
    writeBuffer.write<uint8_t>(static_cast<uint8_t>(IpcMessage::ControlNodeBrieflyInfoResponseMessage));
    IpcMessage::IIpcMessage::write(writeBuffer);
    systemInfoBriefly_.serialize(writeBuffer);
    size_t numberOfIoeZpDeviceInfo = ioeZpDeviceInfos_.size();
    writeBuffer.write(numberOfIoeZpDeviceInfo);
    using Infos = Environment::IoeZpDeviceInfos;
    for (Infos::const_iterator it = ioeZpDeviceInfos_.begin(); it != ioeZpDeviceInfos_.end(); ++it)
    {
        it->first.serialize(writeBuffer);
        it->second.serialize(writeBuffer);
    }
}

void ControlNodeBrieflyInfoResponse::unserialize(Serialize::ReadBuffer& readBuffer)
{
    uint8_t temp = 0;
    readBuffer.read(temp);
    readBuffer.read(temp);
    IpcMessage::IIpcMessage::read(readBuffer);
    systemInfoBriefly_.unserialize(readBuffer);
    size_t numberOfIoeZpDeviceInfo = 0;
    readBuffer.read(numberOfIoeZpDeviceInfo);
    for (size_t i = 0; i < numberOfIoeZpDeviceInfo; ++i)
    {
        Network::IpSocketEndpoint remoteEndpoint;
        remoteEndpoint.unserialize(readBuffer);
        Environment::IoeZpDeviceInfo ioeZpDeviceInfo;
        ioeZpDeviceInfo.unserialize(readBuffer);
    }
}

IpcMessage::SystemMonitorMessageType ControlNodeBrieflyInfoResponse::getSystemMonitorType() const
{
    return IpcMessage::ControlNodeBrieflyInfoResponseMessage;
}

std::ostream& ControlNodeBrieflyInfoResponse::operator<< (std::ostream& os) const
{
    os << "[";
    IpcMessage::IIpcMessage::print(os);
    os << ", ipcMessageType=" << IpcMessage::IpcMessageTypeString(IpcMessage::IpcMessage_SystemMonitor)
       << ", clusterMgtType=" << IpcMessage::SystemMonitorTypeString(IpcMessage::ControlNodeBrieflyInfoResponseMessage)
       << ", systemInfoBriefly=" << systemInfoBriefly_;
    os << ", ioeZpDeviceInfos=[";
    using Infos = Environment::IoeZpDeviceInfos;
    for (Infos::const_iterator it = ioeZpDeviceInfos_.begin(); it != ioeZpDeviceInfos_.end(); ++it)
    {
        os << ", [remote=" << it->first << ", ioeZpDeviceInfo=" << it->second << "]";
    }
    os << "]";
    return os;
}

void ControlNodeBrieflyInfoResponse::setSystemInfoBriefly(const Environment::SystemInfoBriefly& info)
{
    systemInfoBriefly_ = info;
}

const Environment::SystemInfoBriefly& ControlNodeBrieflyInfoResponse::getSystemInfoBriefly() const
{
    return systemInfoBriefly_;
}

void ControlNodeBrieflyInfoResponse::setIoeZpDeviceInfos(const Environment::IoeZpDeviceInfos& infos)
{
    ioeZpDeviceInfos_ = infos;
}

const Environment::IoeZpDeviceInfos& ControlNodeBrieflyInfoResponse::getIoeZpDeviceInfos() const
{
    return ioeZpDeviceInfos_;
}

}
