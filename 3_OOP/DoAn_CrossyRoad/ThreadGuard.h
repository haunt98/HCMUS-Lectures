// Auto join thread

#ifndef THREAD_GUARD_H
#define THREAD_GUARD_H

#include <thread>

using namespace std;

class ThreadGuard
{
private:
    thread &m_t;

public:
    explicit ThreadGuard(thread &t) : m_t(t) {}
    ~ThreadGuard()
    {
        if (m_t.joinable())
        {
            m_t.join();
        }
    }
    ThreadGuard() = delete;
    ThreadGuard(const ThreadGuard &) = delete;
    ThreadGuard &operator=(const ThreadGuard &) = delete;
};

#endif