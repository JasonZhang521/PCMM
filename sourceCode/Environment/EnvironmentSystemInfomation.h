#ifndef ENVIRONMENTSYSTEMINFOMATION_H
#define ENVIRONMENTSYSTEMINFOMATION_H

namespace Environment {

class CpuInfoBriefly;

class EnvironmentSystemInfomation
{
public:
    EnvironmentSystemInfomation();
    static void getCpuInfoBriefly(CpuInfoBriefly& cpuInfoBriefly);
};
}

#endif // ENVIRONMENTSYSTEMINFOMATION_H
