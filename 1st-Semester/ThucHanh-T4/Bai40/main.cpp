//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 40
#include <stdio.h>
#include <math.h>
int main(void)
{
	int n;
	float x, S, tam;
	printf("Bai 40\n");
	do{
		printf("Nhap x = ");
		scanf_s("%f", &x);
	} while (x == 0);
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	S = 0;
	tam = 1;
	for (int i = 0; i < n; ++i)
	{
		tam *= x;
		S = sqrt(S + tam);
	}
	printf("S = %f\n", S);
	return 0;
}