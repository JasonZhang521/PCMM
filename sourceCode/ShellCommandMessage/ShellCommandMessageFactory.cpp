#include "ShellCommandMessageFactory.h"
#include "ShellCommandRequest.h"
#include "Trace.h"
namespace ShellCommandMessage {
ShellCommandMessageFactory::ShellCommandMessageFactory()
{

}

ShellCommandMessageFactory::~ShellCommandMessageFactory()
{

}

IpcMessage::IIpcMessage* ShellCommandMessageFactory::createMessage(IpcMessage::IpcMessageApplicationIntType type) const
{
    if (static_cast<IpcMessage::IpcShellCommandMessageType>(type) == IpcMessage::ShellCommandRequestMessage)
    {
        return new ShellCommandRequest();
    }
    else
    {
        TRACE_ERROR("Unsupported message type");
        return nullptr;
    }
}

}
