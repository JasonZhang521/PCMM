#include "ChatSessionMessageFactory.h"
#include "ChatTextMessage.h"
#include "ChatFileMessage.h"
#include "ChatFileRequest.h"
#include "ChatFileFragmentRequest.h"
#include "ChatAuthorizationRequest.h"
#include "ChatAuthorizationResponse.h"

namespace ChatSessionMessage {
ChatSessionMessageFactory::ChatSessionMessageFactory()
{

}

ChatSessionMessageFactory::~ChatSessionMessageFactory()
{

}

IpcMessage::IIpcMessage* ChatSessionMessageFactory::createMessage(IpcMessage::IpcMessageApplicationIntType type) const
{
    switch (type) {
    case IpcMessage::ChatTextMessage:
        return new ChatTextMessage();
    case IpcMessage::ChatFileMessage:
        return new ChatFileMessage();
    case IpcMessage::ChatFileRequestMessage:
        return new ChatFileRequest();
    case IpcMessage::ChatFileFragmentRequestMessage:
        return new ChatFileFragmentRequest();
    case IpcMessage::ChatAuthorizationRequest:
        return new ChatAuthorizationRequest();
    case IpcMessage::ChatAuthorizationResponse:
        return new ChatAuthorizationResponse();
    default:
        return nullptr;
    }
}
}
