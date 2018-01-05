// 1612180
// Nguyen Tran Hau
// Bai 3

#include "GVCN.h"
#include "GiaoVien.h"

float GiaoVien::TIEN_NGHI = 100000;
float GiaoVien::PHU_CAP_CN = 500000;

int main()
{
	GiaoVien a;
	a.nhap();
	a.xuat();

	GVCN b;
	b.nhap();
	b.xuat();

	GVCN c(b);
	c.xuat();
	return 0;
}