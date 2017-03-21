#include "ham.h"

int main(void)
{
	CONTROPHANSO LIST; int n;

	NhapMangPhanSo(LIST, n);

	printf("Mang phan so sau khi nhap:\n");
	XuatMangPhanSo(LIST, n);

	CONTROPHANSO A = new PHANSO{ 9, 10 };
	ChenMotPhanSo(LIST, n, A);
	printf("Mang phan so sau khi chen %d/%d:\n", A->tu_so, A->mau_so);
	XuatMangPhanSo(LIST, n);

	XoaMotPhanSo(LIST, n, A);
	printf("Mang phan so sau khi xoa %d/%d\n", A->tu_so, A->mau_so);
	XuatMangPhanSo(LIST, n);
	delete[]A;

	return 0;
}