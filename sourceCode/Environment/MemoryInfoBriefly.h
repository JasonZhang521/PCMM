#ifndef _ENVIRONMENT_MEMORYINFOBRIEFLY_H_
#define _ENVIRONMENT_MEMORYINFOBRIEFLY_H_
#include <string>
#include <ostream>

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace Environment {
class MomeryInfoBriefly
{
    std::string memTotal_;
    std::string memFree_;
public:
    MomeryInfoBriefly();
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
    std::ostream& operator <<(std::ostream& os) const;

    void updateMemUsageInfo();
};
}

#endif // _ENVIRONMENT_MEMORYUSAGEINFO_H_
