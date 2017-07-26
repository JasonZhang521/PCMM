#ifndef _ENVIRONMENT_MISCINFO_H_
#define _ENVIRONMENT_MISCINFO_H_
#include "Component.h"
#include "Macro.h"

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace Environment {
class MiscInfo
{
    uint64_t nodeStartTimeStamp_; // second
    uint32_t elapseTimeFromNodeStart_;  // second
public:
    MiscInfo();
    MiscInfo(const MiscInfo& info);
    MiscInfo& operator=(const MiscInfo& info);
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
    std::ostream& operator <<(std::ostream& os) const;
    void update();
private:
    void updateElapseTimeFromNodeStart();

public:
     GETCLASSNAME(MiscInfo)
};
}

inline std::ostream& operator <<(std::ostream& os, const Environment::MiscInfo& info)
{
    return info.operator <<(os);
}

#endif // MISCINFO_H
