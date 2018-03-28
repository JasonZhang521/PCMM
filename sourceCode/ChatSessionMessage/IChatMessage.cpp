#include "IChatMessage.h"

namespace ChatSessionMessage {

IChatMessage::IChatMessage()
{
}

IChatMessage::~IChatMessage()
{
}

IpcMessage::IpcMessageType IChatMessage::getMessageType() const
{
    return IpcMessage::IpcMessage_ChatSession;
}

}
