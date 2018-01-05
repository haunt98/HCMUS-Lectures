#include <iostream>
using namespace std;

// Dat cto trong private
// m_exist la con tro chi den obj duy nhat cua Singleton
// nho su dung static va con tro

class Singleton
{
      private:
	Singleton()
	{
		cout << "create" << endl;
	}
	static Singleton *m_exist;

      public:
	static Singleton *init()
	{
		if (!m_exist) {
			m_exist = new Singleton();
		}
		return m_exist;
	}
	~Singleton()
	{
		m_exist = NULL;
		cout << "del" << endl;
	}
};

Singleton *Singleton::m_exist = NULL;

int main()
{
	Singleton *a = Singleton::init();
	delete a;
	Singleton *b = Singleton::init();
	delete b;
	return 0;
}
