// MSSV: 1612180
// Ho va ten: Nguyen Tran Hau
// Bai 08: Tinh tan mot goc(do)
#include <math.h>
#include <stdio.h>
#define pi 3.1416
int main(void)
{
	float goc;
	printf("Nhap goc can tinh tan\n");
	scanf_s("%f", &goc);
	printf("Ket qua = %f\n", tan(pi * goc / 180));
	return 0;
}