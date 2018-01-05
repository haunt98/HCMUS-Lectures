// MSSV: 1612180
// Ho va ten: Nguyen Tran Hau
// Bai 13: Diem thi THPT
#include <stdio.h>
int main(void)
{
	int a, b, c, diem_thpt;
	printf("Diem mon Toan = ");
	scanf_s("%d", &a);
	printf("Diem mon Ly = ");
	scanf_s("%d", &b);
	printf("Diem mon Hoa = ");
	scanf_s("%d", &c);
	diem_thpt = a + b + c;
	printf("Diem thi THPT = %d\n", diem_thpt);
	return 0;
}