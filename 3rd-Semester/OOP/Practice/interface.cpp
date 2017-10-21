#include <iostream>

using namespace std;

class Animal
{
public:
    // if not use virtual, xuly(cat) act like animal not meow
    virtual void talk() const = 0;
};

class Cat : public Animal
{
public:
    void talk() const { cout << "Meow\n"; }
};

void xuly(const Animal *p)
{
    p->talk();
}

int main()
{
    Animal a;
    xuly(&a);

    Cat b;
    xuly(&b);

    Cat *c;
    c = &b;
    xuly(c);
    return 0;
}
