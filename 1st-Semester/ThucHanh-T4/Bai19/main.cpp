//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 19
#include <stdio.h>
int main(void)
{
	float x;
	float S;
	float tam;
	int n;
	printf("Bai 19\n");
	do{
		printf("Nhap x = ");
		scanf_s("%f", &x);
	} while (x == 0);
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	tam = x;
	S = 1 + x;
	for (int i = 0; i < n; ++i)
	{
		tam = tam*x*x / ((2 * i + 2)*(2 * i + 3));
		S += tam;
	}
	printf("S = %f\n", S);
	return 0;
}
