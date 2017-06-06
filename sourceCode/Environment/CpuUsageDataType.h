#ifndef _ENVIRONMENT_CPUUSAGEDATATYPE_H_
#define _ENVIRONMENT_CPUUSAGEDATATYPE_H_
#include<stdint.h>
#include<vector>

namespace Environment {

#ifdef WIN32
#else
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
    CPU_USAGE_TYPE_NUMBER = 9
};

using CpuUsageRawData = std::vector<uint64_t>;
using CpuUsageRawDatas = std::vector<CpuUsageRawData>;

#endif

class CpuUsageEntry
{
    unsigned int total_;
    unsigned int user_;
    unsigned int nice_;
    unsigned int sys_;
    unsigned int idle_;
    unsigned int intr_;
public:
    inline CpuUsageEntry() : total_(0), user_(0), nice_(0), sys_(0), idle_(0), intr_(0) {}
    inline unsigned int getTotalUsage() const {return total_;}
    inline void setTotalUsage(unsigned int total) {total_ = total;}
    inline unsigned int getUserUsage() const {return user_;}
    inline void setUserUsage(unsigned int user) {user_ = user;}
    inline unsigned int getNiceUsage() const {return nice_;}
    inline void setNiceUsage(unsigned int nice) {nice_ = nice;}
    inline unsigned int getSysUsage() const {return sys_;}
    inline void setSysUsage(unsigned int sys) {sys_ = sys;}
    inline unsigned int getIdleUsage() const {return idle_;}
    inline void setIdleUsage(unsigned int idle) {idle_ = idle;}
    inline unsigned int getIntrUsage() const {return intr_;}
    inline void setIntrUsage(unsigned int intr) {intr_ = intr;}
};

using CpuUsageEntrys = std::vector<CpuUsageEntry>;

}

#endif // _ENVIRONMENT_CPUUSAGEDATATYPE_H_
