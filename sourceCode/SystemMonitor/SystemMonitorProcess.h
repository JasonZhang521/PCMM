#ifndef _SYSTEMMONITOR_SYSTEMMONITORPROCESS_H_
#define _SYSTEMMONITOR_SYSTEMMONITORPROCESS_H_
#include <string>

namespace SystemMonitor {

class SystemMonitorProcess
{
public:
    SystemMonitorProcess();
    void process();
private:
    std::string getServerIpAddressPort() const;
};
}

#endif // _SYSTEMMONITOR_SYSTEMMONITORPROCESS_H_
