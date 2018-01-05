// MSSV: 1612180
// Ho va ten: Nguyen Tran Hau
// Bai 15: Tinh chu vi, dien tich duong tron
#include <math.h>
#include <stdio.h>
#define pi 3.1416

int main(void)
{
	float ban_kinh;
	printf("Ban kinh duong tron = ");
	scanf_s("%f", &ban_kinh);
	float chu_vi = 2.0 * pi * ban_kinh;
	float dien_tich = pi * ban_kinh * ban_kinh;
	printf("Chu vi hinh tron = %f\n", chu_vi);
	printf("Dien tich hinh tron = %f\n", dien_tich);
	return 0;
}
