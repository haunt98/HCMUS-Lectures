#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        a = new int[3];
        for (int i = 0; i < 3; ++i)
        {
            a[i] = i + 1;
        }
    }
    A &operator=(const A &ano_A)
    {
        delete[] a;
        a = new int[3];
        for (int i = 0; i < 3; ++i)
        {
            a[i] = ano_A.a[i] * 2;
        }
        return *this;
    }
    ~A() { delete[] a; }
    void test()
    {
        for (int i = 0; i < 3; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

private:
    int *a;
};

void init(A &a)
{
    A b;
    a = b;
}

int main()
{
    A obj;
    obj.test();
    init(obj);
    obj.test();
    return 0;
}
