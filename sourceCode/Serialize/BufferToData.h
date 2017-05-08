#ifndef _SERIALIZE_BUFFERTODATA_H_
#define _SERIALIZE_BUFFERTODATA_H_

namespace Serialize {

class BufferToData
{
public:
    template <typename T>
    static inline T Read(char* buffer)
    {
        return *(reinterpret_cast<T*>(buffer));
    }

    static inline void Read(char* buffer, char* newBuffer, unsigned int readSize)
    {
        for (unsigned int i = 0; i < readSize; ++i)
        {
            newBuffer[i] = buffer[i];
        }
    }
};

}

#endif // _SERIALIZE_BUFFERTODATA_H_
