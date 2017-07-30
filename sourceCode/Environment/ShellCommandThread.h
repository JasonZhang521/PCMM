#ifndef _ENVIRONMENT_SHELLCOMMANDTHREAD_H_
#define _ENVIRONMENT_SHELLCOMMANDTHREAD_H_
#include "IShellCommand.h"
#include "ITimer.h"
#include "Component.h"
#include "Macro.h"
#include <string>
#include <vector>
#include <memory>
#include <mutex>

namespace std {
class thread;
}

namespace Environment {
class ShellCommandThread : public TimerHandler::ITimer, public IShellCommand
{
    enum class ExcuteState
    {
        Thread_Start,
        Thread_Stop,
        OutPut_Retreived,
        Invalid
    };

    std::string cmd_;
    std::string outPutFile_;
    std::unique_ptr<std::thread> shellCmdThread_;
    ExcuteState excuteState_;
    std::mutex mutex_;
public:
    ShellCommandThread(const std::string& cmd, uint32_t timeout);
    ~ShellCommandThread();
protected:
    virtual void execute();
    virtual void onTime();
    virtual std::ostream& operator<<(std::ostream& os);
private:
    void startThread();
    void getCmdOutPutFromFile();
public:
    GETCLASSNAME(ShellCommandThread)
};
}

#endif // _ENVIRONMENT_SHELLCOMMANDTHREAD_H_
