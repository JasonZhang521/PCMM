#include "CpuInfoBriefly.h"
#include "CpuInfo.h"
#include "CpuUsage.h"
#include "CpuUsageInfo.h"
#include "CpuInfoDataType.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "SocketWrapper.h"
#include "Trace.h"
#include <fstream>
namespace Environment {
CpuInfoBriefly::CpuInfoBriefly()
    :numOfCpu_(0)
    ,usage_(0)
    ,temprature_(0)
{

}

CpuInfoBriefly::CpuInfoBriefly(const CpuInfoBriefly& info)
    : numOfCpu_(info.numOfCpu_)
    , modelName_(info.modelName_)
    , frequency_(info.frequency_)
    , usage_(info.usage_)
    , temprature_(info.temprature_)
{

}

CpuInfoBriefly& CpuInfoBriefly::operator =(const CpuInfoBriefly& info)
{
    numOfCpu_ = info.numOfCpu_;
    modelName_ = info.modelName_;
    frequency_ = info.frequency_;
    usage_ = info.usage_;
    temprature_ = info.temprature_;
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
    writeBuffer.write(temprature_);
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
    readBuffer.read(temprature_);
}

std::ostream& CpuInfoBriefly::operator <<(std::ostream& os) const
{
    os << "["
	   << "numOfCpu=" << numOfCpu_
       << ", modeName=" << modelName_
       << ", frequency=" << frequency_
       << ", usage=" << usage_
       << ", temprature=" << temprature_
       << "]";
    return os;
}

bool CpuInfoBriefly::operator ==(const CpuInfoBriefly& info) const
{
    return (numOfCpu_ == info.numOfCpu_ &&
            modelName_ == info.modelName_ &&
            frequency_ == info.frequency_ &&
            usage_ == info.usage_ &&
            temprature_ == info.temprature_);
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

void CpuInfoBriefly::updateCpuTemprature()
{
    std::string tempfileName("/sys/class/thermal/thermal_zone0/temp");
    //std::string nodeTimeInfofileName("/proc/acpi/thermal_zone/THM0/temperature");
    // for the Linux operation system, the temprature infomation always got from above files
    std::ifstream ifs(tempfileName.c_str());

    if (!ifs.good())
    {
        TRACE_WARNING("Failed to open file: " << tempfileName << ", stop reading, try next time." << std::endl);
        return;
    }

    char buffer[128];
    std::fill(buffer, buffer + 128, 0);
    ifs.getline(buffer, 128);
    std::stringstream ss;
    ss << buffer;

    int temp = 0;
    ss >> temp;
    temprature_ = temp / 1000;
}

}
