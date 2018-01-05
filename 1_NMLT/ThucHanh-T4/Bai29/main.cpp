// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 29
#include <stdio.h>
int main(void)
{
	int n;
	printf("Bai 29\n");
	do {
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	int uoc_le;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0 && i % 2 != 0)
			uoc_le = i;
	}
	printf("Uoc nguyen duong le lon nhat cua n: %d\n", uoc_le);
	return 0;
}