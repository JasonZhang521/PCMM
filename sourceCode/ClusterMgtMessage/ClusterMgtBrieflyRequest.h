#ifndef CLUSTERMGTBRIEFLYREQUEST_H
#define CLUSTERMGTBRIEFLYREQUEST_H
#include "IClusterMgtMessage.h"
#include "IpcMessageType.h"

namespace ClusterMgtMessage {
class ClusterMgtBrieflyRequest : public IClusterMgtMessage
{
public:
    ClusterMgtBrieflyRequest();
    ~ClusterMgtBrieflyRequest();
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcClusterMgtMessageType getClusterMgtType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;
};
}

#endif // CLUSTERMGTBRIEFLYREQUEST_H
