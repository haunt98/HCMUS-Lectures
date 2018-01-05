// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 03
#include <math.h>
#include <stdio.h>
int main(void)
{
	float diem_tb;
	printf("Nhap diem trung binh thang diem 10 cua SV: ");
	scanf("%f", &diem_tb);
	diem_tb = roundf(diem_tb * 10) / 10;
	// lam tron 1 chu so thap phan
	printf("Thang diem ABCDF cua SV: ");
	if (diem_tb >= 8.5 && diem_tb <= 10)
		printf("A\n");
	else if (diem_tb >= 7.0 && diem_tb <= 8.4)
		printf("B\n");
	else if (diem_tb >= 5.5 && diem_tb <= 6.9)
		printf("C\n");
	else if (diem_tb >= 4.0 && diem_tb <= 5.4)
		printf("D\n");
	else
		printf("F\n");
	return 0;
}