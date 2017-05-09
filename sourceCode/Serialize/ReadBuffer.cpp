#include "ReadBuffer.h"

namespace Serialize {

const static unsigned int DefaultReadBufferSize = 2048;
ReadBuffer::ReadBuffer(unsigned int bufferSize = DefaultReadBufferSize)
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

bool ReadBuffer::Read(char* newBuffer, unsigned int readSize)
{
    if (pos_ + readSize >= dataSize_)
    {
        return false;
    }
    BufferToData::Read(buffer_ + pos_, newBuffer, readSize);
    pos_ += readSize;
    return true;
}

}
