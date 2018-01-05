// 1612180
// Nguyen Tran Hau
// Bai 1

#include "NVCongNhat.h"
#include "NVSanXuat.h"
#include "NhanVien.h"

int NhanVien::GiaSP = 20000;
int NhanVien::LuongNgay = 300000;

int main()
{
	NhanVien a;
	a.nhap();
	a.xuat();

	NVSanXuat b;
	b.nhap();
	b.xuat();

	NVCongNhat c;
	c.nhap();
	c.xuat();

	return 0;
}