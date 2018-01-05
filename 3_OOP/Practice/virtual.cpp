#include <iostream>

using namespace std;

class A
{
      public:
	virtual void f1()
	{
		cout << "A::f1" << endl;
		f2();
	}
	virtual void f2()
	{
		cout << "A::f2" << endl;
	}
	virtual ~A()
	{
	}
};

class B : public A
{
      public:
	void f1()
	{
		cout << "B::f1" << endl;
		f2();
	}
	void f2()
	{
		cout << "B::f2" << endl;
	}
};

int main()
{
	A *p = new B;
	// p kieu A nhung giu dia chi cua B
	p->f1();
	delete p;
	return 0;
}
