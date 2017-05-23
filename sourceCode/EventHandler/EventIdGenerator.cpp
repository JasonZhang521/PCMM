#include "EventIdGenerator.h"

namespace EventHandler {

uint64_t EventIdGenerator::eventId_ = 0;

EventIdGenerator::EventIdGenerator()
{
}

uint64_t EventIdGenerator::generateTimerId()
{
    return ++eventId_;
}

}
