#include "WriteBuffer.h"
#include <algorithm>

namespace Serialize {

WriteBuffer::WriteBuffer(unsigned int bufferSize = DefaultWriteBufferSize)
:bufferSize_(bufferSize)
,buffer_(new char[bufferSize])
,dataSize_(0)
,pos_(0)
{

}

WriteBuffer::~WriteBuffer()
{
   delete []  buffer_;
}

void WriteBuffer::Write(const char* newBuffer, unsigned int writeSize)
{
    if (pos_ + writeSize >= dataSize_)
    {
        resizeBuffer(writeSize);
    }

    DataToBuffer::Write(buffer_ + pos_, newBuffer, writeSize);
    pos_ += writeSize;
}

char* WriteBuffer::getBuffer() const
{
    return buffer_;
}

void WriteBuffer::resizeBuffer(unsigned int additionSize)
{
    bufferSize_ = bufferSize_ * 2 + additionSize;
    char* tempBuffer = new char[bufferSize_];
    std::copy(buffer_, buffer_ + dataSize_, tempBuffer);
    delete [] buffer_;
    buffer_ = tempBuffer;
}

}
