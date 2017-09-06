//MSSV: 1612180
//Ho va ten: Nguyen Tran Hau
//Bai 03: Chia 2 so nguyen
#include <stdio.h>

int main(void)
{
	int a, b;
	printf("Chia 2 so nguyen\n");
	printf("Nhap lan luot so bi chia va so chia\n");
	scanf_s("%d %d", &a, &b);
	if (b == 0)
		printf("Phep chia khong thuc hien duoc\n");
	else
		printf("Thuong = %d\n", a / b);
	return 0;
}
