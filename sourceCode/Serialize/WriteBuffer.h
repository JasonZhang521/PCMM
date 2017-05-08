#ifndef WRITEBUFFER_H
#define WRITEBUFFER_H

namespace Serialize {

class WriteBuffer
{
    char* buffer_;
    unsigned int size_;
    unsigned int pos_;
public:
    WriteBuffer();
};

}

#endif // WRITEBUFFER_H
