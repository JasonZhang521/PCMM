#ifndef CLUSTERMGTBRIEFLYRESPONSE_H
#define CLUSTERMGTBRIEFLYRESPONSE_H
#include "IClusterMgtMessage.h"
#include "CpuInfoBriefly.h"

namespace ClusterMgtMessage {
class ClusterMgtBrieflyResponse : public IClusterMgtMessage
{
public:
    ClusterMgtBrieflyResponse();
    virtual ~ClusterMgtBrieflyResponse();
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcClusterMgtMessageType getClusterMgtType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;
};

}

#endif // CLUSTERMGTBRIEFLYRESPONSE_H
