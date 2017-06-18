#include "CpuUsage.h"
#include "CpuUsageCalculator.h"
#include "Trace.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

#ifdef WIN32
#else
#include <sys/sysinfo.h>
#endif
namespace Environment {

CpuUsage::CpuUsage()
    : nCpu_(0)
    , statFilePath_("/proc/stat")
    , preRawDatas_(nCpu_ + 1, CpuUsageRawData(CPU_USAGE_TYPE_NUMBER, 0))
    , curRawDatas_(nCpu_ + 1, CpuUsageRawData(CPU_USAGE_TYPE_NUMBER, 0))
    , usageRawDatas_(nCpu_ + 1, CpuUsageRawData(CPU_USAGE_TYPE_NUMBER, 0))
{
    init();
}

void CpuUsage::init()
{
    nCpu_ = getCpuNumer();
    getCpuUsageFromProcStatFile();
}

/*
 * "/proc/stat" file content sample
 * cpu  5749 2 5482 6263815 7142 57 760 0 0
 * cpu0 1101 0 1840 1525383 1174 27 684 0 0
 * cpu1 1850 0 1750 1587567 2237 0 3 0 0
 * cpu2 366 0 744 1547691 1619 30 52 0 0
 * cpu3 2430 0 1147 1603173 2111 0 20 0 0
 * */
void CpuUsage::getCpuUsageFromProcStatFile()
{
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
	char buffer[128];
	while(ifs.good())
    {
		std::fill(buffer, buffer + 128, 46);
		ifs.getline(buffer, 128);
		std::stringstream ss;
		ss << buffer;
		std::string cpuFlag;
	    
		// cpu flag
		ss >> cpuFlag;
		std::string substr = cpuFlag.substr(0, 3);
		if (cpuFlag.substr(0, 3) != std::string("cpu"))
		{
			break;
		}
        ss  >> curRawDatas_[cpuInde][CPU_USER]
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

unsigned int CpuUsage::getCpuNumer()
{
#ifdef WIN32
    return 0;
#else
    return get_nprocs();
#endif
}

void CpuUsage::update()
{
#ifdef WIN32
#else
    getCpuUsageFromProcStatFile();
#endif
    CpuUsageRawDatasDiffCalculator diffRawDataCalculator;
    usageRawDatas_ = diffRawDataCalculator(curRawDatas_, preRawDatas_);
    CpuUsageEntrysCalculator usageEntryCalculator;
    usageEntrys_ = usageEntryCalculator(usageRawDatas_);
}

CpuUsage& CpuUsage::instance()
{
    static std::unique_ptr<CpuUsage> instance(new CpuUsage());
    return *instance;
}

const CpuUsageRawDatas& CpuUsage::getCpuUsageRawDatas() const
{
    return usageRawDatas_;
}

const CpuUsageEntrys& CpuUsage::getCpuUsageEntrys() const
{
    return usageEntrys_;
}

}
