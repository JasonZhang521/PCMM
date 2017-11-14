#include "ProcessManagementProcess.h"
#include "ProcessHandler.h"
#include "LoopMain.h"
#include <memory>
namespace ProcessManagement {
ProcessManagementProcess::ProcessManagementProcess()
{

}

void ProcessManagementProcess::addProcessParameter(const ProcessParameter& parameter)
{
    parameters_.push_back(parameter);
}

void ProcessManagementProcess::process()
{
    using ProcessHandlers = std::vector<std::unique_ptr<ProcessHandler> >;
    ProcessHandlers handlers;
    for (auto parameter : parameters_)
    {
        for (unsigned int i = 0; i < parameter.second; ++i)
        {
            ProcessHandler* handler = new ProcessHandler(parameter.first);
            Core::LoopMain::instance().registerTimer(handler);
            handlers.push_back(std::unique_ptr<ProcessHandler>(handler));
        }
    }

    // run
    Core::LoopMain::instance().loopStart();
}

}
