//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 09: Kiem tra nam nhuan
#include <stdio.h>
int main(void)
{
	int nam;
	printf("Nhap nam can kiem tra: ");
	scanf("%d", &nam);
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		printf("Day la nam nhuan.\n");
	else
		printf("Day khong phai la nam nhuan.\n");
	return 0;
}