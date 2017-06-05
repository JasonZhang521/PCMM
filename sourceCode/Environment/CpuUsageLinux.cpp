#include "CpuUsageLinux.h"

namespace Environment {

#ifndef WIN32

CpuUsage::CpuUsage()
{

}
void CpuUsage::init()
{
    nCpu_ = get_nprocs();
    statFile_ = std::string("/proc/stat");
}

#endif

}
