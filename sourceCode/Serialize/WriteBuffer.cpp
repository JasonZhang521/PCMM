#include "WriteBuffer.h"
#include <algorithm>

namespace Serialize {

WriteBuffer::WriteBuffer(unsigned int bufferSize)
:bufferSize_(bufferSize)
,buffer_(new char[bufferSize])
,dataSize_(0)
,pos_(0)
{

}
const unsigned int WriteBuffer::DefaultWriteBufferSize = 2048;
WriteBuffer::~WriteBuffer()
{
   delete []  buffer_;
}

void WriteBuffer::write(const char* newBuffer, unsigned int writeSize)
{
    if (pos_ + writeSize > dataSize_)
    {
        resizeBuffer(writeSize);
    }

    DataToBuffer::Write(buffer_ + pos_, newBuffer, writeSize);
    pos_ += writeSize;
    dataSize_ += writeSize;
}

char* WriteBuffer::getBuffer() const
{
    return buffer_;
}

unsigned int WriteBuffer::getBufferSize() const
{
    return bufferSize_;
}

unsigned int WriteBuffer::getDataSize() const
{
    return dataSize_;
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
