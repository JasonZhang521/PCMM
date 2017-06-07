#include "CpuUsage.h"
#include "CpuUsageCalculator.h"
#include "Trace.h"
#include <fstream>
#include <iostream>

#ifdef WIN32
#else
#include <sys/sysinfo.h>
#endif
namespace Environment {

#ifdef WIN32

#else

CpuUsage::CpuUsage()
    : nCpu_(get_nprocs())
    , statFilePath_("/proc/stat")
    , preRawDatas_(nCpu_ + 1, CpuUsageRawData(CPU_USAGE_TYPE_NUMBER, 0))
    , curRawDatas_(nCpu_ + 1, CpuUsageRawData(CPU_USAGE_TYPE_NUMBER, 0))
    , usageRawDatas_(nCpu_ + 1, CpuUsageRawData(CPU_USAGE_TYPE_NUMBER, 0))
{
    init();
}

void CpuUsage::init()
{
    getCpuUsageFromProcStatFile();
}

void CpuUsage::getCpuUsageFromProcStatFile()
{
	std::cout << "nCpu:" << nCpu_ << std::endl;
    // save the curRawDatas;
    preRawDatas_.swap(curRawDatas_);
    // for the Linux operation system, the CPU infomation always got from /proc/stat files
    std::ifstream ifs(statFilePath_.c_str());
	
    if (!ifs.good())
    {
		std::cout << "Failed to open file: " << statFilePath_ << std::endl;
        TRACE_WARNING("Failed to open file: " << statFilePath_ << ", stop reading, try next time." << std::endl);
        return;
    }

    /* cpuInde <--> virtual CPU index
     * 0 <--> total
     * 1 <--> 0
     * 2 <--> 1
     * 3 <--> 2
     * ......
     * n <--> n-1
     */
    unsigned int cpuInde = 0;
    while(ifs.good())
    {
		std::string cpuFlag;
		ifs >> cpuFlag;
		if (cpuFlag.find("cpu") == 0)
		{
			break;
		}
        ifs >> curRawDatas_[cpuInde][CPU_USER]
            >> curRawDatas_[cpuInde][CPU_NICE]
            >> curRawDatas_[cpuInde][CPU_SYS]
            >> curRawDatas_[cpuInde][CPU_IDLE]
            >> curRawDatas_[cpuInde][CPU_IOWAIT]
            >> curRawDatas_[cpuInde][CPU_IRQ]
            >> curRawDatas_[cpuInde][CPU_SOFTIRQ]
            >> curRawDatas_[cpuInde][CPU_STEALSTOLEN]
            >> curRawDatas_[cpuInde][CPU_GUEST];
        ++cpuInde;
        if (cpuInde == (nCpu_ + 1))
        {
            break;
        }
    }
}

void CpuUsage::update()
{
    getCpuUsageFromProcStatFile();
    CpuUsageRawDatasDiffCalculator diffRawDataCalculator;
    usageRawDatas_ = diffRawDataCalculator(curRawDatas_, preRawDatas_);
    CpuUsageEntrysCalculator usageEntryCalculator;
    usageEntrys_ = usageEntryCalculator(usageRawDatas_);
}

const CpuUsageRawDatas& CpuUsage::getCpuUsageRawData() const
{
    return usageRawDatas_;
}

const CpuUsageEntrys& CpuUsage::getCpuUsageEntrys() const
{
    return usageEntrys_;
}

#endif

}
