//MSSV: 1612180
//Ho va ten: Nguyen Tran Hau
//Bai 16: Tinh y1 va y2
#include <stdio.h>
#include <math.h>
#define pi 3.1416
int main(void)
{
	float x;
	printf("Nhap x\n");
	scanf_s("%f", &x);
	float y1 = 4 * (x*x + 10 * x*sqrt(x) + 3 * x + 1);
	float y2 = (sin(pi*x*x) + sqrt(x * x + 1)) / (exp(2 * x) + cos(pi/4*x));
	printf("y1 = %0.2f\n", y1);
	printf("y2 = %0.2f\n", y2);
	return 0;

}