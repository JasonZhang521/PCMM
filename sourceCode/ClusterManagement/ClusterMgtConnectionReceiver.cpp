#include "ClusterMgtConnectionReceiver.h"
#include "IClusterMgtController.h"

namespace ClusterManagement {
ClusterMgtConnectionReceiver::ClusterMgtConnectionReceiver(ClientType type, std::shared_ptr<IClusterMgtController> clusterMgtController)
    :clientType_(type)
    ,clusterMgtController_(clusterMgtController)
{
}

ClusterMgtConnectionReceiver::~ClusterMgtConnectionReceiver()
{

}

void ClusterMgtConnectionReceiver::onConnect()
{

}

void ClusterMgtConnectionReceiver::onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg)
{
    clusterMgtController_->handleMessage(*msg, clientType_);
}

void ClusterMgtConnectionReceiver::onDisconnect()
{

}

}
