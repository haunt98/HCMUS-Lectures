// 1612180
// Nguyen Tran Hau
// Bai06

#include "MangSoNguyen.h"

int main()
{
    // Mang a co 0 phan tu
    MangSoNguyen a;
    a.Xuat();
    // Mang b co 7 so 0
    MangSoNguyen b(7);
    b.Xuat();
    int x[8];
    for (int i = 0; i < 8; i++)
        x[i] = i;
    MangSoNguyen c(x, 8);
    c.Xuat();
    MangSoNguyen d(b);
    d.Xuat();
    return 0;
}