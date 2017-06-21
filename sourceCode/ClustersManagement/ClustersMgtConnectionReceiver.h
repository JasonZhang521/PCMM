#ifndef CLUSTERSMGTCONNECTIONRECEIVER_H
#define CLUSTERSMGTCONNECTIONRECEIVER_H
#include "IIpcConnectionReceiver.h"

namespace ClustersManagement {

class ClustersMgtConnectionReceiver : public Ipc::IIpcConnectionReceiver
{
public:
    ClustersMgtConnectionReceiver();
    virtual ~ClustersMgtConnectionReceiver();
    virtual void onConnect();
    virtual void onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg);
    virtual void onDisconnect();
};

}
#endif // CLUSTERSMGTCONNECTIONRECEIVER_H
