#ifndef ENVIRONMENTSYSTEMINFOMATION_H
#define ENVIRONMENTSYSTEMINFOMATION_H

namespace Environment {

class CpuInfoBriefly;
class MemoryInfoBriefly;

class EnvironmentSystemInfomation
{
public:
    EnvironmentSystemInfomation();
    static void getCpuInfoBriefly(CpuInfoBriefly& cpuInfoBriefly);
    static void getMemoryInfoBriefly(MemoryInfoBriefly& memoryInfoBriefly);
};
}

#endif // ENVIRONMENTSYSTEMINFOMATION_H
