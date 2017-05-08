#include "ReadBuffer.h"

namespace Serialize {

const static unsigned int DefaultReadBufferSize = 2048;
ReadBuffer::ReadBuffer(unsigned int size = DefaultReadBufferSize)
:buffer_(new char[size])
{
}

ReadBuffer::~ReadBuffer()
{
    delete [] buffer_;
}

}
