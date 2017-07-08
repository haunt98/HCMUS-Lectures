//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 57
#include <stdio.h>
int main(void)
{
	int n,n_tam, state;
	printf("Bai 57\n");
	do{
		printf("Nhap n: ");
		scanf_s("%d", &n);
	} while (n < 1);
	state = 1;
	n_tam = n;
	for (int i = 0; n_tam > 0; ++i)
	{
		if ((n_tam % 10) % 2 != 0)
		{
			state = 0;
			break;
		}
		n_tam = n_tam / 10;
	}
	if (state == 1)
		printf("%d chua toan chu so chan\n", n);
	else
		printf("%d khong chua toan chu so chan\n", n);
	return 0;
}