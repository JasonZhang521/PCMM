#ifndef _DEVICEMESSAGE_IDEVICEMESSAGE_H_
#define _DEVICEMESSAGE_IDEVICEMESSAGE_H_
#include "DeviceMessageType.h"

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace DeviceMessage {
class IDeviceMessage
{
public:
    IDeviceMessage();
    virtual ~IDeviceMessage();
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const = 0;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer) = 0;
    virtual DeviceMessageType getMessageType() = 0;
};

}

#endif // _DEVICEMESSAGE_IDEVICEMESSAGE_H_
