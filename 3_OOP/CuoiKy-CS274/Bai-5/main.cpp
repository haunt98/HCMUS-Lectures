#include <iostream>
using namespace std;

class A
{
      public:
	int f()
	{
		return 1;
	}
	virtual int g()
	{
		return 2;
	}
};

class B : public A
{
      public:
	int f()
	{
		return 3;
	}
	virtual int g()
	{
		return 4;
	}
};

class C : public A
{
      public:
	virtual int g()
	{
		return 5;
	}
};

int main()
{
	A *pa;
	A a;
	B b;
	C c;
	pa = &a;
	cout << pa->f() << endl;
	cout << pa->g() << endl;
	pa = &b;
	cout << pa->f() + pa->g() << endl;
	pa = &c;
	cout << pa->f() << endl;
	cout << pa->g() << endl;
	return 0;
}