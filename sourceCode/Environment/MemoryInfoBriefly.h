#ifndef _ENVIRONMENT_MEMORYINFOBRIEFLY_H_
#define _ENVIRONMENT_MEMORYINFOBRIEFLY_H_
#include <string>
#include <ostream>

namespace Serialize {
class WriteBuffer;
class ReadBuffer;
}

namespace Environment {
class MemoryInfoBriefly
{
    std::string memTotal_;
    std::string memFree_;
public:
    MemoryInfoBriefly();
    MemoryInfoBriefly(const MemoryInfoBriefly& info);
    MemoryInfoBriefly& operator =(const MemoryInfoBriefly& info);
    void serialize(Serialize::WriteBuffer& writeBuffer) const;
    void unserialize(Serialize::ReadBuffer& readBuffer);
    std::ostream& operator <<(std::ostream& os) const;
    bool operator ==(const MemoryInfoBriefly& info) const;
    void update();

	inline const std::string& getMemTotal() const {return memTotal_;}
	inline void setMemTotal(const std::string& memTotal) {memTotal_ = memTotal;}
	inline const std::string& getMemFree() const {return memFree_;}
	inline void setMemFree(const std::string& memFree) {memFree_ = memFree;}
private:
    void updateMemUsageInfo();
};
}

inline std::ostream& operator <<(std::ostream& os, const Environment::MemoryInfoBriefly& info)
{
    return info.operator <<(os);
}

#endif // _ENVIRONMENT_MEMORYUSAGEINFO_H_
