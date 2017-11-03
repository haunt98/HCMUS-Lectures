//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 51
#include <stdio.h>
int main(void)
{
	int n, max_chu_so;
	printf("Bai 51\n");
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	max_chu_so = n % 10;
	for (int i = 0; n > 0; ++i)
	{
		n = n / 10;
		if (n % 10 > max_chu_so)
			max_chu_so = n % 10;
	}
	printf("Chu so lon nhat cua n: %d\n", max_chu_so);
	return 0;
}