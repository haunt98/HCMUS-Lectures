// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 8: Bieu dien so N bang M bit
#include <stdio.h>
int main(void)
{
	int N, M;
	printf("Bai 8\n");
	do {
		printf("Nhap N: ");
		scanf_s("%d", &N);
	} while (N < 0);
	do {
		printf("Nhap M: ");
		scanf_s("%d", &M);
	} while (M < 0);
	printf("\n");
	for (int i = 0; i < M; ++i) {
		printf("%d\n", N & 1);
		N = N >> 1;
	}
	return 0;
}