#include "UiClientProcess.h"
#include "IIpcMessage.h"
#include "Sleep.h"
#include "Trace.h"
#include <memory>
int main(int argc, char**argv)
{
    static_cast<void>(argc);
    static_cast<void>(argv);
    UiClient::UiClientProcess process;
    process.start();
    while (true) {
        if (process.messageReceived())
        {
            std::unique_ptr<IpcMessage::IIpcMessage> msg = std::move(process.getOneMessage());
            std::cout << "-----------------------" << std::endl;
            std::cout << *msg << std::endl;
            std::cout << "-----------------------" << std::endl;
        }
        System::Sleep(1000);
    }
    return 0;
}
