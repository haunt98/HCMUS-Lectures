// 1612180
// Nguyen Tran Hau
// Bai04

#include "TamGiac.h"

int main()
{
	TamGiac a; // 0, 0, 1, 0, 0, 1
	a.Xuat();
	Diem d1, d2(3, 0), d3(0, 4);
	TamGiac b(d1, d2, d3);
	b.Xuat();
	TamGiac c(0, 0, 3, 0, 0, 4);
	c.Xuat();
	TamGiac e(c);
	c.Xuat();
	return 0;
}