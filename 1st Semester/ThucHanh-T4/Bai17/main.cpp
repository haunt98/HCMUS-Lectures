//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 17
#include <stdio.h>
int main(void)
{
	float x;
	float S = 0;
	float tam = 1;
	int n;
	printf("Bai 17\n");
	do{
		printf("Nhap x = ");
		scanf_s("%f", &x);
	} while (x == 0);
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	for (int i = 0; i < n; ++i)
	{
		tam = tam*x / (i + 1);
		S += tam;
	}
	printf("S = %f\n", S);
	return 0;
}