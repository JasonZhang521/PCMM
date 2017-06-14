#ifndef SINGLETON_H
#define SINGLETON_H
#include <memory>

template <typename T>
class Singleton
{
    static std::unique_ptr<T> instance;
public:
    static T& instance();
};

template <typename T>
static T& Singleton::instance()
{
    if (!instance)
    {
        instance = std::unique_ptr<T>(new T());
    }

    return *instance;
}

#endif // SINGLETON_H
