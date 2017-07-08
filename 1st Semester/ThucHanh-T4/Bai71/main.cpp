//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 71
#include <stdio.h>
int main(void)
{
	float x;
	float S = 0;
	float tam_x = 1;
	float tam_tong = 0;
	int n;
	printf("Bai 71\n");
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
		tam_x = tam_x*x*(-1);
		tam_tong += (i + 1);
		S = S + tam_x / tam_tong;
	}
	printf("S = %f\n", S);
	return 0;
}