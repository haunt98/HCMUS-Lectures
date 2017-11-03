//MSSV: 1612180
//Ho va ten: Nguyen Tran Hau
//Bai 08: Tinh cotan mot goc(do)
#include <stdio.h>
#include <math.h>
#define pi 3.1416
int main(void)
{
	float goc;
	printf("Nhap goc can tinh cotan\n");
	scanf_s("%f", &goc);
	printf("Ket qua = %f\n", 1 / tan(pi*goc / 180));
	return 0;
}