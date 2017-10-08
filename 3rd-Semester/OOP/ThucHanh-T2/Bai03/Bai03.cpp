// 1612180
// Nguyen Tran Hau
// Bai03

#include "Ngay.h"

int main()
{
    Ngay a; // 1/1/1
    a.Xuat();
    Ngay b(2013); // 1/1/2013
    b.Xuat();
    Ngay c(2013, 5); // 1/5/2013
    c.Xuat();
    Ngay d(2013, 2, 3); // 3/2/2013
    d.Xuat();
    Ngay e(2013, 2, -8); // 1/2/2013
    e.Xuat();
    Ngay f(b);
    f.Xuat();
    Ngay h = d;
    h.Xuat();
    return 0;
}