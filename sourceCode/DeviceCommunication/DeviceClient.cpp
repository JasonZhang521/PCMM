#include "DeviceClient.h"
#include "ITcpClient.h"
#include "IDeviceMessage.h"
#include "WriteBuffer.h"
#include "Component.h"
#include "Macro.h"
#include "Trace.h"

namespace DeviceCommunication {

GETCLASSNAME(DeviceClient)
DeviceClient::DeviceClient(std::unique_ptr<Network::ITcpClient> client)
    :client_(std::move(client))
{

}

DeviceClient::~DeviceClient()
{

}

void DeviceClient::connect()
{
    TRACE_ENTER();
    client_->connect();
}

void DeviceClient::send(DeviceMessage::IDeviceMessage& msg)
{
    TRACE_ENTER();
    Serialize::WriteBuffer writeBuffer;
    msg.serialize(writeBuffer);
    TRACE_DEBUG("send msg:" << writeBuffer);
    client_->send(writeBuffer);
}

void DeviceClient::disconnect()
{
    TRACE_ENTER();
    client_->disconnect();
    client_->cleanup();
    client_->restart();
}

}
