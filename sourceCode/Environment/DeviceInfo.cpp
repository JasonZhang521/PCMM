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

IoeZpDeviceInfo& DeviceInfo::getIoeZpDeviceInfo()
{
    return ioeZpDeviceInfo_;
}

}
