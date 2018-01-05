// 1612180
// Nguyen Tran Hau
// Bai01

#include "PhanSo.h"

int main()
{
	PhanSo a; // 0/1
	a.Xuat();
	PhanSo b(1, -2); // -1/2
	b.Xuat();
	PhanSo c(3, 4); // 3/4
	c.Xuat();
	PhanSo d(3); // 3/1
	d.Xuat();
	PhanSo e(-5); // -5/1
	e.Xuat();
	PhanSo f(c); // 3/4
	f.Xuat();
	a = b.Cong(c);
	a.Xuat();
	return 0;
}