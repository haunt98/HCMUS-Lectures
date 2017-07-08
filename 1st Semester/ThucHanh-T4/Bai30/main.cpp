//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 30
#include <stdio.h>
int main(void)
{
	int n;
	printf("Bai 30\n");
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	int tong_uoc = 0;
	for (int i = 1; i < n; ++i)
	{
		if (n%i == 0)
			tong_uoc += i;
	}
	if (tong_uoc == n)
		printf("n la so hoan thien\n");
	else
		printf("n khong phai la so hoan thien\n");
	return 0;
}