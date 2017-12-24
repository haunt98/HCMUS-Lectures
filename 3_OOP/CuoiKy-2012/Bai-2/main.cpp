#include <iostream>
using namespace std;

// da hinh (polymorphism) nghia la cac lop ke thua tu lop base
// co ham co cung chu ky voi lop base
// bang cac su dung ham ao (virtual)
// y nghia: khong viet lai code nhieu

class P_base
{
public:
    virtual void dosth() { cout << "Base do sth" << endl; }
    virtual ~P_base() {}
};

class P_derived : public P_base
{
public:
    void dosth() { cout << "Derived do sth" << endl; }
    ~P_derived() {}
};

// Lop thuan ao (pure virtual) co ham virtual .. = 0
// khong the tao object tu lop nay

int main()
{
    // Vi du da hinh
    P_base *a = new P_derived;
    a->dosth();
    delete a;
    return 0;
}
