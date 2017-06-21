#include "ClusterMgtConnectionReceiver.h"

namespace ClusterManagement {
ClusterMgtConnectionReceiver::ClusterMgtConnectionReceiver(std::shared_ptr<IClusterMgtController> clusterMgtController)
    :clusterMgtController_(clusterMgtController)
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

}

void ClusterMgtConnectionReceiver::onDisconnect()
{

}

}
