#ifndef _ENVIRONMENT_DEVICEINFO_H_
#define _ENVIRONMENT_DEVICEINFO_H_
#include "IoeZpDeviceInfo.h"
#include "IpSocketEndpoint.h"
#include <map>

namespace Environment {

class DeviceInfo
{
public:
    DeviceInfo();
    ~DeviceInfo();
    static DeviceInfo& instance();

    IoeZpDeviceInfo& getIoeZpDeviceInfo(const Network::IpSocketEndpoint& remoteEndpoint);
    void addIoeZpDeviceInfo(const Network::IpSocketEndpoint& remoteEndpoint, const IoeZpDeviceInfo& info);
    const IoeZpDeviceInfos& getIoeZpDeviceInfos() const;
private:
    IoeZpDeviceInfos ioeZpDeviceInfos_;
};
}
#endif // _ENVIRONMENT_DEVICEINFO_H_
