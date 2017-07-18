#ifndef _ENVIRONMENT_MEMORYINFODATATYPE_H_
#define _ENVIRONMENT_MEMORYINFODATATYPE_H_
#include <vector>
#include <string>
#include <map>

namespace Environment {

enum MemoryInfoType
{
    MEMTOTAL,
    MEMFREE,
    BUFFERS,
    CACHED,
    SWAPCACHED,
    ACTIVE,
    INACTIVE,
    ACTIVE_ANON,
    INACTIVE_ANON,
    ACTIVE_FILE,
    INACTIVE_FILE,
    UNEVICTABLE,
    MLOCKED,
    SWAPTOTAL,
    SWAPFREE,
    DIRTY,
    WRITEBACK,
    ANONPAGES,
    MAPPED,
    SHMEM,
    SLAB,
    SRECLAIMABLE,
    SUNRECLAIM,
    KERNELSTACK,
    PAGETABLES,
    NFS_UNSTABLE,
    BOUNCE,
    WRITEBACKTMP,
    COMMITLIMIT,
    COMMITTED_AS,
    VMALLOCTOTAL,
    VMALLOCUSED,
    VMALLOCCHUNK,
    HARDWARECORRUPTED,
    ANONHUGEPAGES,
    HUGEPAGES_TOTAL,
    HUGEPAGES_FREE,
    HUGEPAGES_RSVD,
    HUGEPAGES_SURP,
    HUGEPAGESIZE,
    DIRECTMAP4K,
    DIRECTMAP2M,
    DIRECTMAP1G,
    MEMORYINFO_INVALID
};
const size_t NUM_OF_MEMORY_INFO_ATTRIBUTE = 43;
using MemoryInfoRawData = std::vector<std::string>;

class MemoryInfoRawDataAttributeString
{
    static std::vector<std::string> attribute_;
    static std::map<std::string, MemoryInfoType> attributeToIndex_;
public:
    static std::string getAttribute(MemoryInfoType type);
    static MemoryInfoType getAttributeIndex(const std::string& attribute);
};

}

#endif // _ENVIRONMENT_MEMORYINFODATATYPE_H_
