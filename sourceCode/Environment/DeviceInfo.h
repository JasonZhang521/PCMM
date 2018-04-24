#ifndef _ENVIRONMENT_DEVICEINFO_H_
#define _ENVIRONMENT_DEVICEINFO_H_
#include "IoeZpDeviceInfo.h"

namespace Environment {
class DeviceInfo
{
public:
    DeviceInfo();
    ~DeviceInfo();
    static DeviceInfo& instance();

    IoeZpDeviceInfo& getIoeZpDeviceInfo();
private:
    IoeZpDeviceInfo ioeZpDeviceInfo_;
};
}
#endif // _ENVIRONMENT_DEVICEINFO_H_
