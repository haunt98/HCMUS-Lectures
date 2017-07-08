//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai tap: Chuyen cac bai tap tuan 4 thanh ham

#include "ham.h"

int main(void)
{
	int n;
	int a, b;
	float x;

	printf("Nhap so thu tu cua bai tap: ");
	scanf_s("%d", &n);
	if (n == 8)
	{
		printf("Nhap M: ");
		scanf_s("%d", &a);
		printf("Nhap N: ");
		scanf_s("%d", &b);
		Bai8(a, b);
	}
	else if (n == 17)
	{
		nhap_x_n(x, a);
		printf("S = %f\n", Bai17(x, a));
	}
	else if (n == 18)
	{
		nhap_x_n(x, a);
		printf("S = %f\n", Bai18(x, a));
	}
	else if (n == 19)
	{
		nhap_x_n(x, a);
		printf("S = %f\n", Bai19(x, a));
	}
	else if (n == 29)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		printf("Uoc le lon nhat: %d\n", Bai29_uoc(a));
	}
	else if (n == 30)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		Bai30_hoanthien(a);
	}
	else if (n == 31)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		Bai31_ngto(a);
	}
	else if (n == 32)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		Bai32_chphuong(a);
	}
	else if (n == 39)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		printf("S = %f\n", Bai39(a));
	}
	else if (n == 40)
	{
		nhap_x_n(x, a);
		printf("S = %f\n", Bai40(x, a));
	}
	else if (n == 41)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		printf("S = %f\n", Bai41(a));
	}
	else if (n == 42)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		printf("k = %d\n", Bai42(a));
	}
	else if (n == 51)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		printf("Chu so lon nhat: %d\n", Bai51(a));
	}
	else if (n == 53)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		printf("So chu so = chu so dau max: %d\n", Bai53(a));
	}
	else if (n == 55)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		printf("So chu so = chu so dau tien: %d\n", Bai55(a));
	}
	else if (n == 57)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		Bai57(a);
	}
	else if (n == 59)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		Bai59(a);
	}
	else if (n == 61)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		Bai61(a);
	}
	else if (n == 62)
	{
		printf("Nhap a: ");
		scanf_s("%d", &a);
		printf("Nhap b: ");
		scanf_s("%d", &b);
		printf("UCLN: %d", Bai62_uoc(a, b));
	}
	else if (n == 63)
	{
		printf("Nhap a: ");
		scanf_s("%d", &a);
		printf("Nhap b: ");
		scanf_s("%d", &b);
		printf("BCNN: %d", Bai63_boi(a, b));
	}
	else if (n == 67)
	{
		nhap_x_n(x, a);
		printf("S = %f\n", Bai67(x, a));
	}
	else if (n == 69)
	{
		nhap_x_n(x, a);
		printf("S = %f\n", Bai69(x, a));
	}
	else if (n == 71)
	{
		nhap_x_n(x, a);
		printf("S = %f\n", Bai71(x, a));
	}
	else if (n == 73)
	{
		nhap_x_n(x, a);
		printf("S = %f\n", Bai73(x, a));
	}
	else if (n == 75)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		Bai75(a);
	}
	else if (n == 76)
	{
		printf("Nhap n: ");
		scanf_s("%d", &a);
		Bai76(a);
	}
	else
		printf("Khong co bai tap nay\n");

	return 0;
}