#ifndef _DEVICEMESSAGE_IOEZPRESOURCE_H_
#define _DEVICEMESSAGE_IOEZPRESOURCE_H_
#include <stdint.h>

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}
namespace DeviceMessage {

const uint16_t USROPTS_BZ06 = 0x01;
const uint16_t DEVOPTS_BZ06 = 0x04;
const uint16_t RUNDATA_BZ06 = 0x10;
const uint16_t OUTCTL_BZ06 = 0x20;
const uint16_t RELATED_BZ06 = 0x40;

struct UsrOptsBz06
{
    char devName[16];
    uint32_t upInfoDelay;
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
};

struct DevoptsBz06
{
    uint32_t devNumber;
    uint16_t modeINum;
    uint32_t date;
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
};

struct RunDataBz06
{
    int16_t temp1;
    int16_t temp2;
    uint16_t hum;
    uint8_t output;
    uint16_t input;
    uint16_t battVol;
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
};

struct OutCtlBz06
{
    uint32_t delay;
    int8_t reserved;
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
};

struct IoeZpResource
{
    uint16_t resourceId;
    void* resource;
    IoeZpResource();
    IoeZpResource(uint16_t resId);
    IoeZpResource(const IoeZpResource& res);
    IoeZpResource& operator=(const IoeZpResource& res);
    ~IoeZpResource();
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
private:
    void allocate();
    void dellocate();
    void copy(void* otherResource);
};

}
#endif // _DEVICEMESSAGE_IOEZPRESOURCE_H_
