#include "IoeZpDeviceInfo.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace Environment
{
IoeZpDeviceInfo::IoeZpDeviceInfo()
{

}

IoeZpDeviceInfo::IoeZpDeviceInfo(const IoeZpDeviceInfo& info)
    : netId_(info.netId_)
    , deviceNumber_(info.deviceNumber_)
    , modelNum_(info.modelNum_)
    , date_(info.date_)
    , temperature1_(info.temperature1_)
    , temperature2_(info.temperature2_)
    , humitidy_(info.humitidy_)
    , batteryVoltage_(info.batteryVoltage_)
{

}

IoeZpDeviceInfo::~IoeZpDeviceInfo()
{
}

IoeZpDeviceInfo& IoeZpDeviceInfo::operator=(const IoeZpDeviceInfo& info)
{
    netId_ = info.netId_;
    deviceNumber_ = info.deviceNumber_;
    modelNum_ = info.modelNum_;
    date_ = info.date_;
    temperature1_ = info.temperature1_;
    temperature2_ = info.temperature2_;
    humitidy_ = info.humitidy_;
    batteryVoltage_ = info.batteryVoltage_;
    return *this;
}


void IoeZpDeviceInfo::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(netId_);
    writeBuffer.write(deviceNumber_);
    writeBuffer.write(modelNum_);
    writeBuffer.write(date_);
    writeBuffer.write(temperature1_);
    writeBuffer.write(temperature2_);
    writeBuffer.write(humitidy_);
    writeBuffer.write(batteryVoltage_);
}

void IoeZpDeviceInfo::unserialize(Serialize::ReadBuffer& readBuffer)
{
    readBuffer.read(netId_);
    readBuffer.read(deviceNumber_);
    readBuffer.read(modelNum_);
    readBuffer.read(date_);
    readBuffer.read(temperature1_);
    readBuffer.read(temperature2_);
    readBuffer.read(humitidy_);
    readBuffer.read(batteryVoltage_);
}

std::ostream& IoeZpDeviceInfo::print(std::ostream& os) const
{
    os << "["
       << "netId=" << netId_
       << ", deviceNumber=" << deviceNumber_
       << ", modelNum=" << modelNum_
       << ", date=" << date_
       << ", temperature1=" << temperature1_
       << ", temperature2=" << temperature2_
       << ", humitidy=" << humitidy_
       << ", batteryVoltage=" << batteryVoltage_
       << "]";
    return os;
}

}
