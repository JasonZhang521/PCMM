#ifndef CPUUSAGEDATATYPE_H
#define CPUUSAGEDATATYPE_H
#include<stdint.h>
#include<vector>

namespace SystemMonitor {

#ifdef WIN32
//#else
enum CpuUsageType
{
    CPU_USER        = 0,
    CPU_NICE        = 1,
    CPU_SYS         = 2,
    CPU_IDLE        = 3,
    CPU_IOWAIT      = 4,
    CPU_IRQ         = 5,
    CPU_SOFTIRQ     = 6,
    CPU_STEALSTOLEN = 7,
    CPU_GUEST       = 8,
    CPU_TYPE_NUMBER = 9
};

using CpuUsageRawData = std::vector<uint64_t>;

class CpuUsageEntry
{
    unsigned int total_;
    unsigned int user_;
    unsigned int nice_;
    unsigned int sys_;
    unsigned int idle_;
    unsigned int intr_;
};

#endif

}

#endif // CPUUSAGEDATATYPE_H
