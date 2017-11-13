#ifndef _PROCESSMANAGEMENT_PROCESSHANDLER_H_
#define _PROCESSMANAGEMENT_PROCESSHANDLER_H_
#include "ITimer.h"
#include <memory>

namespace ProcessManagementSupport {
class IUnixProcess;
}

namespace ProcessManagement {


class ProcessHandler : public TimerHandler::ITimer
{
    std::unique_ptr<ProcessManagementSupport::IUnixProcess> process;
public:
    ProcessHandler();
    virtual ~ProcessHandler();
    virtual void onTime();
    virtual std::ostream& operator<<(std::ostream& os);
};
}

#endif // _PROCESSMANAGEMENT_PROCESSHANDLER_H_
