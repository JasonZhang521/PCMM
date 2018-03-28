#ifndef MESSAGEBUFFER_H
#define MESSAGEBUFFER_H
#include <stdint.h>
#include <memory>
#include <ostream>

class MessageBuffer
{
    uint32_t len_;
    char* buffer_;
    std::shared_ptr<uint32_t> reference_;
public:
    MessageBuffer();
    MessageBuffer(uint32_t len, char* buffer);
    MessageBuffer(const MessageBuffer& messageBuffer);
    ~MessageBuffer();
    MessageBuffer& operator=(const MessageBuffer& messageBuffer);
    bool operator==(const MessageBuffer& messageBuffer);
    void print(std::ostream& os) const;

    uint32_t len() const;
    const char* buffer() const;
private:
    void deReference();
};

inline std::ostream& operator<< (std::ostream& os, const MessageBuffer& buffer)
{
    buffer.print(os);
    return os;
}

#endif // MESSAGEBUFFER_H
