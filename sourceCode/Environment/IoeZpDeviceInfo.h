#ifndef _ENVIRONMENT_IOEZPDEVICEINFO_H_
#define _ENVIRONMENT_IOEZPDEVICEINFO_H_
#include <stdint.h>
#include <ostream>

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace Environment {
const int32_t InvalidTemp = -100000;
const uint32_t InvalidHumidity = 10000;
const uint32_t InvalidValtage_ = 0xFFFFFFFF;

class IoeZpDeviceInfo
{
    // NetId
    uint32_t netId_;
    // factory number of the device
    uint32_t deviceNumber_;
    // Equipment model
    uint32_t modelNum_;
    // manufactory date;
    uint32_t date_;
    // temperature for device1, uint 0.01K
    int32_t temperature1_;
    // temperature for device2, uint 0.01K
    int32_t temperature2_;
    // uint32_t humitidy, uint 0.1%
    uint32_t humitidy_;
    // valtage for battery, uint mv
    uint32_t batteryVoltage_;
public:
    IoeZpDeviceInfo();
    IoeZpDeviceInfo(const IoeZpDeviceInfo& info);
    ~IoeZpDeviceInfo();
    IoeZpDeviceInfo& operator=(const IoeZpDeviceInfo& info);

    inline void setNetId(uint32_t netId) {netId_ = netId;}
    inline uint32_t getNetId() const {return netId_;}
    inline void setDeviceNumber(uint32_t deviceNumber) {deviceNumber_ = deviceNumber;}
    inline uint32_t getDeviceNumber() const {return deviceNumber_;}
    inline void setModelNum(uint32_t modelNum) {modelNum_ = modelNum;}
    inline uint32_t getModelNum() const {return modelNum_;}
    inline void setDate(uint32_t date) {date_ = date;}
    inline uint32_t getDate() const {return date_;}
    inline void setTemperature1(int32_t temp) {temperature1_ = temp;}
    inline int32_t getTemperature1() const {return temperature1_;}
    inline void setTemperature2(int32_t temp) {temperature2_ = temp;}
    inline int32_t getTemperature2() const {return temperature2_;}
    inline void setHumitidy(uint32_t hum) {humitidy_ = hum;}
    inline uint32_t getHumitidy() const {return humitidy_;}
    inline void setBatteryVoltage(uint32_t vol) {batteryVoltage_ = vol;}
    inline uint32_t getBatteryVoltage() const {return batteryVoltage_;}

    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);

    std::ostream& print(std::ostream& os) const;
};
}

inline std::ostream& operator <<(std::ostream& os, const Environment::IoeZpDeviceInfo& info)
{
    return info.print(os);
}
#endif // _ENVIRONMENT_IOEZPDEVICEINFO_H_
