#include "ham.h"

void NhapMotPhanSo(CONTROPHANSO A)
{
	printf("Tu so: ");
	scanf("%d", &A->tu_so);
	do {
		printf("Mau so: ");
		scanf("%d", &A->mau_so);
	} while (A->mau_so == 0);
}

void ChenMotPhanSo(CONTROPHANSO &LIST, int &n, CONTROPHANSO A)
{
	CONTROPHANSO LIST_NEW =
	    (CONTROPHANSO)realloc(LIST, (n + 1) * sizeof(PHANSO));
	if (LIST_NEW != NULL) {
		LIST_NEW[n] = *A;
		++n;
		LIST = LIST_NEW;
	}
}

void NhapMangPhanSo(CONTROPHANSO &LIST, int &n)
{
	PHANSO A;
	LIST = NULL;
	printf("Nhap so luong: ");
	do {
		scanf("%d", &n);
	} while (n < 1);
	for (int i = 0; i < n;) {
		printf("Nhap phan so %dth: \n", i);
		NhapMotPhanSo(&A);
		ChenMotPhanSo(LIST, i, &A);
	}
}

void XuatMangPhanSo(CONTROPHANSO LIST, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%dth: %d/%d\n", i, LIST[i].tu_so, LIST[i].mau_so);
}

void XoaMotPhanSo(CONTROPHANSO &LIST, int &n, CONTROPHANSO A)
{
	CONTROPHANSO P, Q;
	for (P = LIST; P < LIST + n; ++P) {
		if (P->tu_so == A->tu_so && P->mau_so == A->mau_so) {
			for (Q = P; Q < LIST + n - 1; ++Q)
				*Q = *(Q + 1);
			break;
		}
	}
	--n;
}