#ifndef _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
#define _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
#include "IIpcConnectionReceiver.h"
#include "ClusterMgtClientType.h"

namespace ClusterManagement {

class IClusterMgtController;

class ClusterMgtConnectionReceiver : public Ipc::IIpcConnectionReceiver
{
    ClientType clientType_;
    std::shared_ptr<IClusterMgtController> clusterMgtController_;
public:
    ClusterMgtConnectionReceiver(ClientType type, std::shared_ptr<IClusterMgtController> clusterMgtController);
    virtual ~ClusterMgtConnectionReceiver();
    virtual void onConnect();
    virtual void onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg);
    virtual void onDisconnect();
};

}
#endif // _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
