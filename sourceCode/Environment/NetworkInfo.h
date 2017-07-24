#ifndef _ENVIRONMENT_NETWORKINFO_H_
#define _ENVIRONMENT_NETWORKINFO_H_
#include "NetworkEnv.h"
#include "Component.h"
#include "Macro.h"
#include <string>
#include <ostream>

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace Environment {
class NetworkInfo
{
    std::string macAddress_;
    Network::IpAddresses hostIpAddresses_;

public:
    NetworkInfo();
    NetworkInfo(const NetworkInfo& info);
    NetworkInfo& operator =(const NetworkInfo& info);
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
    std::ostream& operator <<(std::ostream& os) const;
    void update();
private:
    void updateMacAddress();
    void updateIpAddress();

public:
     GETCLASSNAME(NetworkInfo)
};
}

#endif // NETWORKINFO_H
