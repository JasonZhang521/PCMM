#ifndef _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
#define _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
#include "IIpcConnectionReceiver.h"
#include "ClusterMgtClientType.h"
#include "Component.h"
#include "Macro.h"

namespace ClusterManagement {

class IClusterMgtController;

class ClusterMgtConnectionReceiver : public Ipc::IIpcConnectionReceiver
{
    ClientType clientType_;
    std::shared_ptr<IClusterMgtController> clusterMgtController_;
    std::string remoteIpEndpoint_;
public:
    ClusterMgtConnectionReceiver(ClientType type,
                                 std::shared_ptr<IClusterMgtController> clusterMgtController,
                                 const std::string& remoteIpEndpoint);
    virtual ~ClusterMgtConnectionReceiver();
    virtual void onConnect();
    virtual void onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg);
    virtual void onDisconnect();
public:
    GETCLASSNAME(ClusterMgtConnectionReceiver)
};

}
#endif // _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
