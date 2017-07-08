//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 42
#include <stdio.h>
int main(void)
{
	int n,k;
	float S;
	printf("Bai 42\n");
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	k = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i*(i + 1) / 2 < n)
			k = i;
	}
	printf("k = %d\n", k);
	return 0;
}

