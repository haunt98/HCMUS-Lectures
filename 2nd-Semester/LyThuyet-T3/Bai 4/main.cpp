#include "ham.h"

int main(void)
{
	intc2 A; intc1 B; int M, N, L;
	nhapMatran(A, M, N);
	trichDanhsachNguyento(A, M, N, B, L);
	printf("Mang gom cac so nguyen to: ");
	xuatMang(B, L);

	delete[]B;
	for (int i = 0; i < M; ++i)
		delete[]A[i];
	return 0;
}