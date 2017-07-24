#include "MiscInfo.h"
#include "SystemTime.h"
#include "Trace.h"
namespace Environment {
MiscInfo::MiscInfo()
    : nodeStartTimeStamp_(0)
    , elapseTimeFromNodeStart_(0)
{

}

void MiscInfo::updateElapseTimeFromNodeStart()
{
    std::string nodeTimeInfofileName("/proc/uptime");
    // for the Linux operation system, the time infomation always got from /proc/uptime files
    std::ifstream ifs(nodeTimeInfofileName.c_str());

    if (!ifs.good())
    {
        TRACE_WARNING("Failed to open file: " << nodeTimeInfofileName << ", stop reading, try next time." << std::endl);
        return;
    }

    char buffer[128];
    std::fill(buffer, buffer + 128, 0);
    ifs.getline(buffer, 128);
    std::stringstream ss;
    ss << buffer;

    float elapse = 0.0;
    ss << elapse;
    elapseTimeFromNodeStart_ = static_cast<uint32_t>(elapse);
    nodeStartTimeStamp_ = SystemTime::currentTimeStampAsSecond();
}

}
