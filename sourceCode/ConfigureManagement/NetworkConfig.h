#ifndef NETWORKCONFIG_H
#define NETWORKCONFIG_H
#include <string>
#include <vector>

namespace ConfigureManagement {
class NetworkConfig
{
public:
    NetworkConfig();
    static std::vector<std::string> getNodeServerIpPort();
    static std::vector<std::string> getUiServerIpPort();
    static std::vector<std::string> getChatServerIpPort();
private:
    static bool readIpPortFromConfigFile(const std::string& configFile, std::vector<std::string>& ipPorts);
};

}

#endif // NETWORKCONFIG_H
