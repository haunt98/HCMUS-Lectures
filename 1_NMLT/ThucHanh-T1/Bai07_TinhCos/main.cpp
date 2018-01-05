// MSSV: 1612180
// Ho va ten: Nguyen Tran Hau
// Bai 07: Tinh cos 1 goc(do)
#include <math.h>
#include <stdio.h>
#define pi 3.1416
int main(void)
{
	float goc;
	printf("Nhap goc can tinh cos\n");
	scanf_s("%f", &goc);
	printf("Ket qua = %f\n", cos(pi * goc / 180));
	return 0;
}