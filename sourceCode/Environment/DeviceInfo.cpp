#include "DeviceInfo.h"
namespace Environment {
DeviceInfo::DeviceInfo()
{

}

DeviceInfo::~DeviceInfo()
{

}

DeviceInfo& DeviceInfo::instance()
{
   static DeviceInfo info;
   return info;
}

IoeZpDeviceInfo& DeviceInfo::getIoeZpDeviceInfo(const Network::IpSocketEndpoint& remoteEndpoint)
{
    return ioeZpDeviceInfos_[remoteEndpoint];
}

void DeviceInfo::addIoeZpDeviceInfo(const Network::IpSocketEndpoint& remoteEndpoint, const IoeZpDeviceInfo& info)
{
    ioeZpDeviceInfos_[remoteEndpoint] = info;
}

const IoeZpDeviceInfos& DeviceInfo::getIoeZpDeviceInfos() const
{
    return ioeZpDeviceInfos_;
}

}
