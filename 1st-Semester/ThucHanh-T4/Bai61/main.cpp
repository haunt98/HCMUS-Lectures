//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 61
#include <stdio.h>
int main(void)
{
	printf("Bai 61\n");
	int n, n_tam, state;
	do{
		printf("Nhap n: ");
		scanf_s("%d", &n);
	} while (n < 1);
	state = 1;
	n_tam = n;
	for (int i = 0; n_tam > 9; ++i)
	{
		if (n_tam % 10 >= (n_tam / 10) % 10)
		{
			state = 0;
			break;
		}
		n_tam = n_tam / 10;
	}
	if (state == 1)
		printf("Cac chu so cua %d giam dan tu trai qua phai\n", n);
	else
		printf("Cac chu so cua %d khong giam dan tu trai qua phai\n", n);
	return 0;
}