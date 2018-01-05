// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 69
#include <stdio.h>
int main(void)
{
	float x, tam, S;
	int n;
	printf("Bai 69\n");
	do {
		printf("Nhap x = ");
		scanf_s("%f", &x);
	} while (x == 0);
	do {
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	S = 0;
	tam = -1 / x;
	for (int i = 0; i < n + 1; ++i) {
		tam = tam * x * x * (-1);
		S += tam;
	}
	printf("S= %f\n", S);
	return 0;
}