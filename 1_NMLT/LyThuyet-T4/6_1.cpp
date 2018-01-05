#include "6_1.h"
#include "ktra_SNT.h"
#include <stdio.h>
// in ra cac so nguyen to <= N
void baitap_6_1()
{
	int N;
	do {
		printf("Nhap N: ");
		scanf("%d", &N);
	} while (N < 0);
	printf("Cac so nguyen to <= %d: ", N);
	for (int i = 1; i <= N; ++i) {
		if (ktra_SNT(i) == 1)
			printf("%d ", i);
	}
	printf("\n");
}