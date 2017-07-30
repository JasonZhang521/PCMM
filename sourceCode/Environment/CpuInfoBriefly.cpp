#include "CpuInfoBriefly.h"
#include "CpuInfo.h"
#include "CpuUsage.h"
#include "CpuUsageInfo.h"
#include "CpuInfoDataType.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "SocketWrapper.h"
#include <iostream>
namespace Environment {
CpuInfoBriefly::CpuInfoBriefly()
    :numOfCpu_(0)
    ,usage_(0)
{

}

CpuInfoBriefly::CpuInfoBriefly(const CpuInfoBriefly& info)
    : numOfCpu_(info.numOfCpu_)
    , modelName_(info.modelName_)
    , frequency_(info.frequency_)
    , usage_(info.usage_)
{

}

CpuInfoBriefly& CpuInfoBriefly::operator =(const CpuInfoBriefly& info)
{
    numOfCpu_ = info.numOfCpu_;
    modelName_ = info.modelName_;
    frequency_ = info.frequency_;
    usage_ = info.usage_;
    return *this;
}

void CpuInfoBriefly::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(IoPlatformWrapper::Htons(numOfCpu_));
    writeBuffer.write(static_cast<uint8_t>(modelName_.size()));
    writeBuffer.write(modelName_.c_str(), modelName_.size());

    writeBuffer.write(static_cast<uint8_t>(frequency_.size()));
    writeBuffer.write(frequency_.c_str(), frequency_.size());

    writeBuffer.write(static_cast<uint8_t>(usage_));
}

void CpuInfoBriefly::unserialize(Serialize::ReadBuffer& readBuffer)
{
    unsigned short temp = 0;
    readBuffer.read(temp);
    numOfCpu_ = IoPlatformWrapper::Ntohs(temp);
    char buffer[256];
    std::fill(buffer, buffer + 256, 0);
    uint8_t len = 0;
    readBuffer.read(len);
    readBuffer.read(buffer, len);
    modelName_ = std::string(buffer, len);
    readBuffer.read(len);
    readBuffer.read(buffer, len);
    frequency_ = std::string(buffer, len);
	uint8_t usage = 0;
    readBuffer.read(usage);
	usage_ = usage;
}

std::ostream& CpuInfoBriefly::operator <<(std::ostream& os) const
{
    os << "["
	   << "numOfCpu=" << numOfCpu_
       << ", modeName=" << modelName_
       << ", frequency=" << frequency_
       << ", usage=" << usage_
       << "]";
    return os;
}

bool CpuInfoBriefly::operator ==(const CpuInfoBriefly& info) const
{
    return (numOfCpu_ == info.numOfCpu_ &&
            modelName_ == info.modelName_ &&
            frequency_ == info.frequency_ &&
            usage_ == info.usage_);
}

void CpuInfoBriefly::updateCpuInfoBriefly()
{
    CpuUsage::instance().update();
    CpuUsageInfo cpuUsageInfo(CpuUsage::instance().getCpuUsageEntrys());
    setUsage(cpuUsageInfo.getAverageUsage());

    CpuInfo::instance().update();
    const CpuInfoRawDatas& rawDatas = CpuInfo::instance().getCpuInfoRawData();
    size_t nCpu = rawDatas.size();
    setNumOfCpu(nCpu);
    if (nCpu > 0)
    {
        CpuInfoRawData rawData = rawDatas[0];
        setModelName(rawData[MODEL_NAME]);
        setFrequency(rawData[CPU_MHZ]);
    }
}

void CpuInfoBriefly::update()
{
    updateCpuInfoBriefly();
}

}
