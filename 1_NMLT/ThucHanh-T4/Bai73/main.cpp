// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 73
#include <stdio.h>
int main(void)
{
	int n;
	float x;
	float S = -1;
	float x_tam, giaithua_tam;
	printf("Bai 73\n");
	do {
		printf("Nhap x = ");
		scanf_s("%f", &x);
	} while (x == 0);
	do {
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	x_tam = -1;
	giaithua_tam = 1;
	for (int i = 0; i < n; ++i) {
		x_tam = x_tam * x * x * (-1);
		giaithua_tam = giaithua_tam * (2 * i + 1) * (2 * i + 2);
		S = S + x_tam / giaithua_tam;
	}
	printf("S = %f\n", S);
	return 0;
}