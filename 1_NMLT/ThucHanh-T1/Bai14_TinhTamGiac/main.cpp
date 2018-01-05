// MSSV: 1612180
// Ho va ten: Nguyen Tran Hau
// Bai 14: Tinh chu vi va dien tich tam giac
#include <math.h>
#include <stdio.h>
int main(void)
{
	float a, b, c, chu_vi, dien_tich;
	printf("Nhap vao 3 canh tam giac\n");
	scanf_s("%f %f %f", &a, &b, &c);
	if ((a + b) <= c || (b + c) <= a || (c + a) <= b)
		printf("Day khong phai la so do 3 canh tam giac\n");
	else
		chu_vi = a + b + c;
	dien_tich = sqrt((chu_vi / 2) * (chu_vi / 2 - a) * (chu_vi / 2 - b) *
			 (chu_vi / 2 - c));
	printf("Tam giac co chu vi = %f\n", chu_vi);
	printf("Tam giac co dien tich = %f\n", dien_tich);
	return 0;
}