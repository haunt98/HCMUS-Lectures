// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 67
#include <stdio.h>
int main(void)
{
	float x, tam, S;
	int n;
	printf("Bai 67\n");
	do {
		printf("Nhap x = ");
		scanf_s("%f", &x);
	} while (x == 0);
	do {
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	S = 0;
	tam = -1;
	for (int i = 0; i < n; ++i) {
		tam = tam * x * (-1);
		S += tam;
	}
	printf("S= %f\n", S);
	return 0;
}