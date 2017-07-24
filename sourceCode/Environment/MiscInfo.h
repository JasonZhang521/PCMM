#ifndef _ENVIRONMENT_MISCINFO_H_
#define _ENVIRONMENT_MISCINFO_H_
#include "Component.h"
#include "Macro.h"

namespace Environment {
class MiscInfo
{
    uint64_t nodeStartTimeStamp_; // second
    uint32_t elapseTimeFromNodeStart_;  // second
public:
    MiscInfo();
private:
    void updateElapseTimeFromNodeStart();

public:
     GETCLASSNAME(MiscInfo)
};
}

#endif // MISCINFO_H
