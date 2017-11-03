//MSSV: 1612180
//Ho va ten: Nguyen Tran Hau
//Bai 11: Tinh tien
#include <stdio.h>
int main(void)
{
	int so_luong;
	float don_gia;
	printf("So luong don hang = ");
	scanf_s("%d", &so_luong);
	printf("Don gia = ");
	scanf_s("%f", &don_gia);
	float tien = so_luong*don_gia*1.1;
	printf("So tien phai tra = %f\n",tien);
	return 0;
}