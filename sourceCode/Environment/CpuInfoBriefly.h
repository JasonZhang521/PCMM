#ifndef CPUINFOBRIEFLY_H
#define CPUINFOBRIEFLY_H
#include <string>
#include <ostream>

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}
namespace Environment {
class CpuInfoBriefly
{
    uint16_t numOfCpu_;
    std::string modelName_;
    std::string frequency_;
    int usage_;
public:
    CpuInfoBriefly();
    inline void setNumOfCpu(uint16_t num) {numOfCpu_ = num;}
    inline uint16_t getNumOfCpu() const {return numOfCpu_;}
    inline void setModelName(const std::string& modelName) {modelName_ = modelName;}
    inline const std::string& getModeName() const {return modelName_;}
    inline void setFrequency(const std::string& frequency) {frequency_ = frequency;}
    inline const std::string& getFrequency() const {return frequency_;}
    inline void setUsage(int usage) {usage_ = usage;}
    inline int getUsage() const {return usage_;}

    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);

    std::ostream& operator <<(std::ostream& os) const;
};
}

#endif // CPUINFOBRIEFLY_H
