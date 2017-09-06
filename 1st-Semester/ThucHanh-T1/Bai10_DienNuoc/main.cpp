//MSSV: 1612180
//Ho va ten: Nguyen Tran Hau
//Bai 10: Tinh so KWh dien da su dung trong thang
#include <stdio.h>
int main(void)
{
	int a, b;
	printf("Nhap chi so dien thang nay\n");
	scanf_s("%d", &a);
	printf("Nhap chi so dien thang truoc\n");
	scanf_s("%d", &b);
	printf("So kwh dien da su dung trong thang = %d\n", a - b);
	return 0;
}
