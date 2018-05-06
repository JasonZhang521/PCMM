#include "DeviceClientHandler.h"
#include "Component.h"
#include "Macro.h"
#include "Trace.h"

namespace SimulatorClient {

 GETCLASSNAME(DeviceClientHandler)

DeviceClientHandler::DeviceClientHandler()
{

}

DeviceClientHandler::~DeviceClientHandler()
{

}

void DeviceClientHandler::setDeviceClient(std::shared_ptr<DeviceCommunication::IDeviceClient> client)
{
    TRACE_ENTER();
    client_ = client;
}

void DeviceClientHandler::startup()
{
    TRACE_ENTER();
    client_->connect();
}

void DeviceClientHandler::shutdown()
{
    TRACE_ENTER();
    client_->disconnect();
}

void DeviceClientHandler::reStartup()
{

}

void DeviceClientHandler::onStartup()
{

}

void DeviceClientHandler::onShutdown()
{

}

}
