#ifndef IREADBUFFER_H
#define IREADBUFFER_H


class IReadBuffer
{
public:
    IReadBuffer();
    virtual ~IReadBuffer();
    template <typename T> virtual bool read(T& val) {};
};

#endif // IREADBUFFER_H
