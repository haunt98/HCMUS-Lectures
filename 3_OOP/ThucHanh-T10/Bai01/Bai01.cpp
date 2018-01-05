// 1612180
// Nguyễn Trần Hậu
// Bài 1

#include "SoCan7.h"

int main()
{
	SoCan7 s1;
	s1.nhap();
	s1.xuat();
	SoCan7 s2;
	s2.nhap();
	s2.xuat();
	(s1 + s2).xuat();
	(s1 - s2).xuat();
	(s1 * s2).xuat();
	s1.doiDau().xuat();
	return 0;
}