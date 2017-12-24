// 1612180
// Nguyen Tran Hau
// Bai02
#include "SoPhuc.h"

int main()
{
    SoPhuc a; // 0 + 0i
    a.Xuat();
    SoPhuc b(2); // 2 + 0i
    b.Xuat();
    SoPhuc c(3, 4); // 3 + 4i
    c.Xuat();
    SoPhuc d(c); // 3 + 4i
    d.Xuat();
    SoPhuc e(-5, 6); // -5 + 6i
    e.Xuat();
    SoPhuc f(-7); // -7 + 0i
    f.Xuat();
    return 0;
}