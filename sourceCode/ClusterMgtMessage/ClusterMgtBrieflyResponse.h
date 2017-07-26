#ifndef CLUSTERMGTBRIEFLYRESPONSE_H
#define CLUSTERMGTBRIEFLYRESPONSE_H
#include "IClusterMgtMessage.h"
#include "SystemInfoBriefly.h"

namespace ClusterMgtMessage {
class ClusterMgtBrieflyResponse : public IClusterMgtMessage
{
    Environment::SystemInfoBriefly systemInfoBriefly_;
public:
    ClusterMgtBrieflyResponse();
    virtual ~ClusterMgtBrieflyResponse();
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);

    virtual IpcMessage::IpcClusterMgtMessageType getClusterMgtType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;

    void setSystemInfoBriefly(const Environment::SystemInfoBriefly& info);
    const Environment::SystemInfoBriefly& getSystemInfoBriefly() const;
};

}

inline std::ostream& operator<< (std::ostream& os, const ClusterMgtMessage::ClusterMgtBrieflyResponse& response)
{
    return response.operator <<(os);
}

#endif // CLUSTERMGTBRIEFLYRESPONSE_H
