//MSSV: 1612180
//Ho va ten: Nguyen Tran Hau
//Bai 11: Tinh tuoi
#include <stdio.h>
#define nam_hientai 2016
int main(void)
{
	int nam_sinh;
	printf("Nhap nam sinh = ");
	scanf_s("%d", &nam_sinh);
	printf("Tuoi = %d\n", nam_hientai - nam_sinh);
	return 0;
}