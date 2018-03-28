#include "MessageBuffer.h"
#include <cstring>

MessageBuffer::MessageBuffer()
    : len_(0)
    , buffer_(nullptr)
{

}

MessageBuffer::MessageBuffer(uint32_t len, char* buffer)
    : len_(len)
    , buffer_(buffer)
    , reference_(new uint32_t(1))
{
}

MessageBuffer::MessageBuffer(const MessageBuffer& messageBuffer)
    : len_(messageBuffer.len_)
    , buffer_(messageBuffer.buffer_)
    , reference_(messageBuffer.reference_)
{
    ++(*reference_);
}

MessageBuffer::~MessageBuffer()
{
    deReference();
}

MessageBuffer& MessageBuffer::operator=(const MessageBuffer& messageBuffer)
{
    deReference();
    len_ = messageBuffer.len_;
    buffer_ = messageBuffer.buffer_;
    reference_ = messageBuffer.reference_;
    return *this;
}

bool MessageBuffer::operator==(const MessageBuffer& messageBuffer)
{
    if (len_ != messageBuffer.len_)
    {
        return false;
    }


    if (buffer_ == messageBuffer.buffer_)
    {
        return true;
    }
    else
    {
        if (memcmp(buffer_, messageBuffer.buffer_, len_) != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

void MessageBuffer::print(std::ostream& os) const
{
    os << "[";
    os << "len:" << len_
       << ", buffer:";
    for (uint32_t i = 0; i < len_; ++i)
    {
        if ((uint8_t)buffer_[i] <= 0xF)
        {
            os << "0";
        }
        os << std::hex << (uint32_t)buffer_[i];
    }
    os << "]";
}


uint32_t MessageBuffer::len() const
{
    return len_;
}

const char* MessageBuffer::buffer() const
{
    return buffer_;
}

void MessageBuffer::deReference()
{
    --(*reference_);
    if (*reference_ == 0)
    {
        delete [] buffer_;
    }
}
