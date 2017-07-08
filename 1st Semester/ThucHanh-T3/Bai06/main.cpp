//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 06: Giai pt ax+b=0
#include <stdio.h>
int main(void)
{
	float a, b, x;
	printf("Giai phuong trinh ax+b=0\n");
	printf("Nhap a: ");
	scanf("%f", &a);
	printf("Nhap b: ");
	scanf("%f", &b);
	if (a == 0)
	{
		if (b == 0)
			printf("PT vo so nghiem\n");
		else
			printf("PT vo nghiem\n");
	}
	else
	{
		x = -b / a;
		printf("Nghiem x = %f\n", x);
	}
	return 0;
}