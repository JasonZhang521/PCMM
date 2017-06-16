#ifndef SYSTEMINFOCOLLECTOR_H
#define SYSTEMINFOCOLLECTOR_H
#include "IEvent.h"
#include "CpuUsageInfo.h"
#include "Component.h"
#include "Macro.h"
#include "stdint.h"
#include <memory>

namespace Environment {
    class CpuUsageInfo;
}

namespace SystemMonitor {

class SystemInfoCollector : public EventHandler::IEvent
{
    uint64_t eventId_;
    Environment::CpuUsageInfo cpuUsageInfo_;
public:
    SystemInfoCollector();
    virtual ~SystemInfoCollector();
    const Environment::CpuUsageInfo& getCpuUsageInfo() const;
protected:
    virtual uint64_t getEventId() const;
    virtual void run(EventHandler::EventFlag flag = EventHandler::EventFlag::Event_NoFlag);
    virtual std::ostream& operator<< (std::ostream& os) const;
private:
    void init();

public:
     GETCLASSNAME(SystemInfoCollector)
};

}
#endif // SYSTEMINFOCOLLECTOR_H
