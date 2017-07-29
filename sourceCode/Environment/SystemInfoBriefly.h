#ifndef SYSTEMINFOBRIEFLY_H
#define SYSTEMINFOBRIEFLY_H
#include "CpuInfoBriefly.h"
#include "MemoryInfoBriefly.h"
#include "NetworkInfo.h"
#include "MiscInfo.h"

namespace Environment {
class SystemInfoBriefly
{
    CpuInfoBriefly cpuInfoBriefly_;
    MemoryInfoBriefly memoryInfoBriefly_;
    NetworkInfo networkInfo_;
    MiscInfo miscInfo_;

public:
    SystemInfoBriefly();
    SystemInfoBriefly(const SystemInfoBriefly& info);
    SystemInfoBriefly& operator =(const SystemInfoBriefly& info);
	void setCpuInfoBriefly(const CpuInfoBriefly& info);
    const CpuInfoBriefly& getCpuInfoBriefly() const;
    const MemoryInfoBriefly& getMemoryInfoBriefly() const;
	void setMemoryInfoBriefly(const MemoryInfoBriefly& info);
    const NetworkInfo& getNetworkInfo() const;
	void setNetworkInfo(const NetworkInfo& info);
    const MiscInfo& getMiscInfo() const;
	void setMiscInfo(const MiscInfo& info);

    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
    std::ostream& operator <<(std::ostream& os) const;

    void update();
};
}

inline std::ostream& operator <<(std::ostream& os, const Environment::SystemInfoBriefly& info)
{
    return info.operator <<(os);
}

#endif // SYSTEMINFOBRIEFLY_H
