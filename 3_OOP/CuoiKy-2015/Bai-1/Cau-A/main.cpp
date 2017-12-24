#include <iostream>
using namespace std;

class A
{
public:
    virtual void f(int x) { cout << x << " " ; }
};

class B : public A
{
public:
    void f(int y) { A::f(y + 1); }
};

void doSomething(A a, B b)
{
    a.f(3);
    b.f(3);
}

int main()
{
    B x, y;
    doSomething(x, y); // output 3 4
}
