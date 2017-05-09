#include "WriteBuffer.h"

namespace Serialize {

WriteBuffer::WriteBuffer(unsigned int bufferSize)
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

}
