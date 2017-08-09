#ifndef _ENVIRONMENT_DISKUSAGEINFO_H_
#define _ENVIRONMENT_DISKUSAGEINFO_H_
#include "ShellCommandDataType.h"
#include "ShellCommandDfOutput.h"
#include "Component.h"
#include "Macro.h"

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace Environment {
class DiskUsageInfo
{
    ShellCommandDfOutput rootDirUsage_;
    ShellCommandDfOutput bootInitDirUsage_;
public:
    DiskUsageInfo();
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
    std::ostream& operator <<(std::ostream& os) const;
    bool operator ==(const DiskUsageInfo& info) const;

    void update();
public:
     GETCLASSNAME(NetworkInfo)
};
}
#endif // DISKUSAGEINFO_H
