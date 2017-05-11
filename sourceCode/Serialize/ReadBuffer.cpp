#include "ReadBuffer.h"

namespace Serialize {

const unsigned int ReadBuffer::DefaultReadBufferSize = 2048;
ReadBuffer::ReadBuffer(unsigned int bufferSize)
:bufferSize_(bufferSize)
,buffer_(new char[bufferSize])
,dataSize_(0)
,pos_(0)
{
}

ReadBuffer::~ReadBuffer()
{
    delete [] buffer_;
}

bool ReadBuffer::read(char* newBuffer, unsigned int readSize)
{
    if (pos_ + readSize > dataSize_)
    {
        return false;
    }
    BufferToData::Read(buffer_ + pos_, newBuffer, readSize);
    pos_ += readSize;
    return true;
}

bool ReadBuffer::setDataSize(unsigned int dataSize)
{
    if (dataSize > bufferSize_)
    {
        return false;
    }
    dataSize_ = dataSize;
    return true;
}

char* ReadBuffer::getBuffer() const
{
    return buffer_;
}

unsigned int ReadBuffer::getBufferSize() const
{
    return bufferSize_;
}

unsigned int ReadBuffer::getDataSize() const
{
    return dataSize_;
}

}
