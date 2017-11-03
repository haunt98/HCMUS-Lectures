//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 59
#include <stdio.h>
int main(void)
{
	printf("Bai 59\n");
	int n, n_tam, n_nguoc;
	do{
		printf("Nhap n: ");
		scanf_s("%d", &n);
	} while (n < 1);
	n_tam = n;
	n_nguoc = 0;
	for (int i = 0; n_tam > 0; ++i)
	{
		n_nguoc = n_nguoc * 10 + n_tam % 10;
		n_tam = n_tam / 10;
	}
	if (n_nguoc == n)
		printf("%d la so doi xung\n", n);
	else
		printf("%d khong phai la so doi xung\n", n);
	return 0;
}