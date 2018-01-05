// MSSV: 1612180
// Ho va ten: Nguyen Tran Hau
// Bai 17: Tinh tham nien cua giang vien
#include <stdio.h>
#define nam_hientai 2016

int main(void)
{
	int nam_vaolam;
	printf("Nam vao lam cua giang vien: ");
	scanf_s("%d", &nam_vaolam);
	int tham_nien = nam_hientai - nam_vaolam;
	printf("Tham nien cua giang vien: %d\n", tham_nien);
	return 0;
}