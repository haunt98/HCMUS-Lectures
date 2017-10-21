#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    cout << "Hello" << endl;
}

class thread_guard
{
private:
    thread &m_t; // use & because m_t depends on t

public:
    explicit thread_guard(thread &t) : m_t(t) {}
    ~thread_guard()
    {
        if (m_t.joinable())
        {
            m_t.join();
        }
    }
};

int main()
{
    thread t(hello);
    thread_guard g(t);
    return 0;
}
