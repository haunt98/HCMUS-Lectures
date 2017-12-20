#include "PhanSo.h"

int main()
{
    PhanSo a(1, 3), c;
    int b = 8;
    c = a + (PhanSo)b;
    cout << "c = " << a << " + " << b << " = " << c << endl;
    cout << "++c: ";
    cout << "c = " << ++c << endl;
    cout << "a = " << a << " + " << c << endl;
    a += c;
    cout << "a = " << a << endl;
    b = a;
    cout << "b = " << b << endl;
    return 0;
}
