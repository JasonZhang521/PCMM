#ifndef _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
#define _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
#include "IIpcConnectionReceiver.h"

namespace ClusterManagement {

class IClusterMgtController;

class ClusterMgtConnectionReceiver : public Ipc::IIpcConnectionReceiver
{
    std::shared_ptr<IClusterMgtController> clusterMgtController_;
public:
    ClusterMgtConnectionReceiver(std::shared_ptr<IClusterMgtController> clusterMgtController);
    virtual ~ClusterMgtConnectionReceiver();
    virtual void onConnect();
    virtual void onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg);
    virtual void onDisconnect();
};

}
#endif // _CLUSTERMANAGEMENT_CLUSTERMGTCONNECTIONRECEIVER_H_
