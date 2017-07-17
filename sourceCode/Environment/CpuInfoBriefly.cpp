#include "CpuInfoBriefly.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
namespace Environment {
CpuInfoBriefly::CpuInfoBriefly()
{

}

void CpuInfoBriefly::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(static_cast<uint8_t>(modelName_.size()));
    writeBuffer.write(modelName_.c_str(), modelName_.size());

    writeBuffer.write(static_cast<uint8_t>(frequency_.size()));
    writeBuffer.write(frequency_.c_str(), frequency_.size());

    writeBuffer.write(static_cast<uint8_t>(usage_));
}

void CpuInfoBriefly::unserialize(Serialize::ReadBuffer& readBuffer)
{
    char buffer[256];
    std::fill(buffer, buffer + 256, 0);
    uint8_t len = 0;
    readBuffer.read(len);
    readBuffer.read(buffer, len);
    modelName_ = std::string(buffer, len);

    readBuffer.read(len);
    readBuffer.read(buffer, len);
    frequency_ = std::string(buffer, len);

    readBuffer.read(usage_);
}

std::ostream& CpuInfoBriefly::operator <<(std::ostream& os) const
{
    os << "["
       << "modeName=" << modelName_
       << "frequency=" << frequency_
       << "usage=" << usage_
       << "]";
    return os;
}

}
