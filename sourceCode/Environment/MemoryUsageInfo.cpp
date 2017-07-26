#include "MemoryUsageInfo.h"
#include "RemoveCharacter.h"
#include "Trace.h"
#include <sstream>
#include <memory>
#include <fstream>
namespace Environment {
MemoryUsageInfo::MemoryUsageInfo()
{

}

std::ostream& MemoryUsageInfo::operator << (std::ostream& os) const
{
    os << "[";
    for (MemoryUsageInfoRawData::const_iterator it = rawData_.cbegin(); it != rawData_.cend(); ++it)
    {
        size_t index = 0;
        os << MemoryUsageInfoRawDataAttributeString::getAttribute(static_cast<MemoryUsageInfoType>(index))
           << "=" << *it;
        os << ",";
    }
    os << "]";

    return os;
}
void MemoryUsageInfo::update()
{
#ifdef WIN32
#else
	getMemoryInfoFromcProcMemoInfoFile();
#endif
}

const MemoryUsageInfoRawData MemoryUsageInfo::getMemoryUsageInfoRawData() const
{
    return rawData_;
}

MemoryUsageInfo& MemoryUsageInfo::instance()
{
    static std::unique_ptr<MemoryUsageInfo> instance(new MemoryUsageInfo());
    return *instance;
}

void MemoryUsageInfo::getMemoryInfoFromcProcMemoInfoFile()
{
    std::string memInfofileName("/proc/meminfo");
    // for the Linux operation system, the memory infomation always got from /proc/meminfo files
    std::ifstream ifs(memInfofileName.c_str());

    if (!ifs.good())
    {
        TRACE_WARNING("Failed to open file: " << memInfofileName << ", stop reading, try next time." << std::endl);
        return;
    }

    clear();
    MemoryUsageInfoRawData rawData(NUM_OF_MEMORY_INFO_ATTRIBUTE, std::string(""));
    RemoveCharacter remover;
    char buffer[512];
    while(ifs.good())
    {
        std::fill(buffer, buffer + 512, 0);
        ifs.getline(buffer, 512);
        std::stringstream ss;
        ss << buffer;
        std::string oneline = ss.str();
        size_t posOfSep = oneline.find(':');
        std::string attribute = oneline.substr(0, posOfSep);
        // delete the front and end space
        attribute = remover(attribute);
        std::string value = oneline.substr(posOfSep + 1, attribute.size() - posOfSep - 1);
        // delete the front and end space
        value = remover(value);
        MemoryUsageInfoType memInfoType = MemoryUsageInfoRawDataAttributeString::getAttributeIndex(attribute);
        if (memInfoType != MEMORYINFO_INVALID)
        {
            rawData[static_cast<size_t>(memInfoType)] = value;
        }
    }
    rawData_.swap(rawData);
}

void MemoryUsageInfo::clear()
{
    MemoryUsageInfoRawData rawData;
    rawData_.swap(rawData);
}

}
