#ifndef WRITEBUFFER_H
#define WRITEBUFFER_H

namespace Serialize {

class WriteBuffer
{
    unsigned int bufferSize_;
    char* buffer_;
    unsigned int dataSize_;
    unsigned int pos_;
public:
    WriteBuffer(unsigned int size);
    ~WriteBuffer();
    unsigned int Write(const T& val)
    {

    }
};

}

#endif // WRITEBUFFER_H
