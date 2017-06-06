#include "CpuUsageLinux.h"
#include <fstream>

namespace Environment {

#ifndef WIN32

CpuUsage::CpuUsage()
    : nCpu_(get_nprocs())
    , statFile_("/proc/stat")
    , preRawDatas_(nCpu_ + 1, CpuUsageRawData(CPU_USAGE_TYPE_NUMBER), 0)
    , curRawDatas_(nCpu_ + 1, CpuUsageRawData(CPU_USAGE_TYPE_NUMBER), 0)
{
    init();
}

void CpuUsage::init()
{
    getCpuUsageFromProcStatFile();
}

void CpuUsage::getCpuUsageFromProcStatFile()
{
    // save the curRawDatas;
    preRawDatas_.swap(curRawDatas_);
    // for the Linux operation system, the CPU infomation always got from /proc/stat files
    std::ifstream ifs(statFilePath_.c_str());
    if (!ifs.good())
    {
        TRACE_WARNING("Failed to open file: " << statFilePath_ << ", stop reading, try next time." << std::endl);
        return;
    }

    unsigned int count = 0;
    while(ifs.good())
    {
        ifs >> curRawDatas_[CPU_USER]
            >> curRawDatas_[CPU_NICE]
            >> curRawDatas_[CPU_SYS]
            >> curRawDatas_[CPU_IDLE]
            >> curRawDatas_[CPU_IOWAIT]
            >> curRawDatas_[CPU_IRQ]
            >> curRawDatas_[CPU_SOFTIRQ]
            >> curRawDatas_[CPU_STEALSTOLEN]
            >> curRawDatas_[CPU_GUEST];
        ++count;
        if (count == (nCpu_ + 1))
        {
            break;
        }
    }
}

#endif

}
