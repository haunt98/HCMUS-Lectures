// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 75
#include <stdio.h>
int main(void)
{
	int n, flag;
	printf("Bai 75\n");
	do {
		printf("Nhap n: ");
		scanf_s("%d", &n);
	} while (n < 1);
	flag = 1;
	int n_tam = n;
	while (n_tam > 0) {
		if (n_tam % 2 == 0)
			n_tam = n_tam / 2;
		else if (n_tam == 1)
			break;
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		printf("%d co dang 2^k\n", n);
	else
		printf("%d khong co dang 2^k\n", n);
	return 0;
}