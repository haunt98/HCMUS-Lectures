// 1612180
// Nguyen Tran Hau
// Bai05

#include "NgaySinh.h"
#include "SinhVien.h"

int main()
{
	SinhVien a;
	a.Xuat();
	SinhVien b("1212001");
	b.Xuat();
	SinhVien c("1212001", "Nguyen Truong An");
	c.Xuat();
	SinhVien d("1212001", "Nguyen Truong An", 7, 8);
	d.Xuat(); // 7 DLT; 8 DTH
	NgaySinh ns(1990, 4, 1);
	SinhVien e("1212001", "Nguyen Truong An", ns);
	e.Xuat();
	SinhVien f("1212001", "Nguyen Truong An", ns, 7, 8);
	f.Xuat();
	SinhVien g("1212001", "Nguyen Truong An", 1900, 4, 1, 7, 8);
	g.Xuat();
	SinhVien h(g);
	h.Xuat();
	return 0;
}