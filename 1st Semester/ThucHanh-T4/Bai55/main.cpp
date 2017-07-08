//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 55
#include <stdio.h>
#include <math.h>
int main(void)
{
	int n, n_tam, dem, chu_so_dau_tien;
	printf("Bai 55\n");
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	n_tam = n;
	while (n_tam > 0)
	{
		chu_so_dau_tien = n_tam % 10;
		n_tam = n_tam / 10;
	}
	n_tam = n;
	dem = 0;
	for (int i = 0; n_tam > 0; ++i)
	{
		if (n_tam % 10 == chu_so_dau_tien)
			++dem;
		n_tam = n_tam / 10;
	}
	printf("So luong chu so dau tien cua %d: %d\n", n, dem);
	return 0;
}