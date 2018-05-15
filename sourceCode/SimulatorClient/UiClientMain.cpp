#include "UiClientProcess.h"
#include "ControlNodeBrieflyInfoRequest.h"
#include "ControlNodeBrieflyInfoResponse.h"
#include "DeviceMessageGenerator.h"
#include "IoeZpResource.h"
#include "IDeviceMessage.h"
#include "IIpcMessage.h"
#include "Sleep.h"
#include "Trace.h"
#include "Configure.h"
#include <memory>
std::string className()
{
    return "";
}

int main(int argc, char**argv)
{
    static_cast<void>(argc);
    static_cast<void>(argv);
    Configure::getInstance().setTraceLogFilePath("C:\\message.log");
    SimulatorClient::UiClientProcess process;
    DeviceMessage::DeviceMessageGenerator generator;
    process.start();
    while (true) {

        while (process.messageReceived())
        {
            std::unique_ptr<IpcMessage::IIpcMessage> msg = std::move(process.getOneMessage());
            std::cout << "-----------------------" << std::endl;
            std::cout << *msg << std::endl;
            std::cout << "-----------------------" << std::endl;
            std::cout.flush();
            TRACE_NOTICE(*msg);
        }
        System::Sleep(5000);

        static int count = 0;
        count ++;
        if (count < 40)
        {
            std::unique_ptr<DeviceMessage::IDeviceMessage> deviceMessage(std::move(generator.generateIoZpResourceMessage(DeviceMessage::RESOURCE_MASK)));
            std::cout << "-----------------------" << std::endl;
            std::cout << "send Device Message:" << *deviceMessage << std::endl;
            std::cout << "-----------------------" << std::endl;
            process.sendMessage(std::move(deviceMessage));

            System::Sleep(1000);

            std::unique_ptr<IpcMessage::IIpcMessage>
                    controlNodeBrieflyInfoRequest(new SystemMonitorMessage::ControlNodeBrieflyInfoRequest);
            process.sendMessage(std::move(controlNodeBrieflyInfoRequest));

            System::Sleep(1000);
        }
        else
        {
            break;
        }

        System::Sleep(5000);
    }
    return 0;
}
