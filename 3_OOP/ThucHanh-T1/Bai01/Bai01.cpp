// 1612180
// Nguyen Tran Hau
// Bai01

#include "MangPhanSo.h"
#include "PhanSo.h"

int main()
{
	MangPhanSo A;
	A.nhap();
	A.sapxep(&MangPhanSo::duongGiamAmTang);
	A.xuat();
	A.xoa();
	return 0;
}