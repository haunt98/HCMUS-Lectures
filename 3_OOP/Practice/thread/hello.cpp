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
	explicit thread_guard(thread &t) : m_t(t)
	{
	}
	~thread_guard()
	{
		if (m_t.joinable()) // join() only call once
		{
			m_t.join();
		}
	}
	// ensure not provide by compiler
	thread_guard(thread_guard const &) = delete;
	thread_guard &operator=(thread_guard const &) = delete;
};

int main()
{
	thread t(hello);
	thread_guard g(t);
	return 0;
}
