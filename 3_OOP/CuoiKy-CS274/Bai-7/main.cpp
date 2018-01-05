#include <iostream>
using namespace std;

class A
{
      public:
	A();
	~A();
	static int numBorn;
	static int numLiving;
};

A::A()
{
	cout << "cto" << endl;
	++numBorn;
	++numLiving;
}

A::~A()
{
	cout << "dto" << endl;
	--numLiving;
}

int A::numBorn = 0;
int A::numLiving = 0;

int main()
{
	A a1;
	A a2;
	cout << a1.numBorn << endl;
	cout << a1.numLiving << endl;
	return 0;
}