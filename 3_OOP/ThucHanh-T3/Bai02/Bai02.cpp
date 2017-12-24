// 1612180
// Nguyen Tran Hau
// Bai 2 phan so

#include "Fraction.h"

void main()
{
    Fraction f1; // 0/1
    Fraction f2(1, 1);
    Fraction f3(1, -7);  // -1/7
    Fraction f4(f3);     // Copy constructor
    Fraction f5 = f2;    // Copy constructor
    Fraction f6, f7, f8; // Default constructor
    f6 = f3;             // Operator =

    f7 = f1 + f5; // 1/1
    f8 = f2 - f4; // 8/7
    f3 = f1 * f7; // 0
    f5 = f6 / f2; // 0

    cout << (f2 == f3) << endl;
    cout << (f3 != f1) << endl;
    cout << (f2 >= f5) << endl;
    cout << (f2 > f5) << endl;
    cout << (f5 <= f3) << endl;
    cout << (f5 < f3) << endl;

    f1 = f2 + 3;
    f3 = -7 + f1;
    f5 = 7 * f3;
    f6 = f4 - 6;

    cout << f3 << endl;
    cout << f6 << endl;

    f1 += f5;
    f6 -= f7;
    f8 *= f1;
    f8 /= f2;

    cout << f8++ << endl;
    cout << ++f7 << endl;

    cout << f8-- << endl;
    cout << --f7 << endl;

    float f = (float)f3; // 3/2 => 1.5
    cout << f << endl;
}