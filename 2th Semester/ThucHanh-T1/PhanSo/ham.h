#include <stdio.h>
#include <stdlib.h>

struct phan_so{
	int tu_so, mau_so;
};

typedef struct phan_so PHANSO;
typedef PHANSO * CONTROPHANSO;

void NhapMotPhanSo(CONTROPHANSO A);

void ChenMotPhanSo(CONTROPHANSO &LIST, int &n, CONTROPHANSO A);

void NhapMangPhanSo(CONTROPHANSO &LIST, int &n);

void XuatMangPhanSo(CONTROPHANSO LIST, int n);

void XoaMotPhanSo(CONTROPHANSO &LIST, int &n, CONTROPHANSO A);