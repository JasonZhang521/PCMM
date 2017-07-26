#include "SystemInfoBriefly.h"
namespace Environment {
SystemInfoBriefly::SystemInfoBriefly()
{

}

SystemInfoBriefly::SystemInfoBriefly(const SystemInfoBriefly& info)
    : cpuInfoBriefly_(info.cpuInfoBriefly_)
    , memoryInfoBriefly_(info.memoryInfoBriefly_)
    , networkInfo_(info.networkInfo_)
    , miscInfo_(info.miscInfo_)
{

}

SystemInfoBriefly& SystemInfoBriefly::operator =(const SystemInfoBriefly& info)
{
    cpuInfoBriefly_ = info.cpuInfoBriefly_;
    memoryInfoBriefly_ = info.memoryInfoBriefly_;
    networkInfo_ = info.networkInfo_;
    miscInfo_ = info.miscInfo_;
    return *this;
}

const CpuInfoBriefly& SystemInfoBriefly::getCpuInfoBriefly() const
{
    return cpuInfoBriefly_;
}

const MemoryInfoBriefly& SystemInfoBriefly::getMemoryInfoBriefly() const
{
    return memoryInfoBriefly_;
}

const NetworkInfo& SystemInfoBriefly::getNetworkInfo() const
{
    return networkInfo_;
}

const MiscInfo& SystemInfoBriefly::getMiscInfo() const
{
    return miscInfo_;
}

void SystemInfoBriefly::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    cpuInfoBriefly_.serialize(writeBuffer);
    memoryInfoBriefly_.serialize(writeBuffer);
    networkInfo_.serialize(writeBuffer);
    miscInfo_.serialize(writeBuffer);
}

void SystemInfoBriefly::unserialize(Serialize::ReadBuffer& readBuffer)
{
    cpuInfoBriefly_.unserialize(readBuffer);
    memoryInfoBriefly_.unserialize(readBuffer);
    networkInfo_.unserialize(readBuffer);
    miscInfo_.unserialize(readBuffer);
}

std::ostream& SystemInfoBriefly::operator <<(std::ostream& os) const
{
    os << "["
       << "cpuInfoBriefly=" << cpuInfoBriefly_
       << ", memoryInfoBriefly=" << memoryInfoBriefly_
       << ", networkInfo=" << networkInfo_
       << ", miscInfo=" << miscInfo_
       << "]";
    return os;
}

void SystemInfoBriefly::update()
{
    cpuInfoBriefly_.update();
    memoryInfoBriefly_.update();
    networkInfo_.update();
    miscInfo_.update();
}

}
