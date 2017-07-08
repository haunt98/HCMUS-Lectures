//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 32
#include <stdio.h>
int main(void)
{
	int n,state;
	printf("Bai 32\n");
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	state = 0;
	for (int i = 0; i <= n/2+1; ++i)
	{
		if (i*i == n)
		{
			state = 1;
			break;
		}
	}
	if (state == 0)
		printf("%d khong phai la so chinh phuong\n", n);
	else
		printf("%d la so chinh phuong\n", n);
	return 0;
}