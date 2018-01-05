// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 53
#include <stdio.h>
int main(void)
{
	int n, n_tam, dem, max_chu_so;
	printf("Bai 53\n");
	do {
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	n_tam = n;
	max_chu_so = n_tam % 10;
	for (int i = 0; n_tam > 0; ++i) {
		n_tam = n_tam / 10;
		if (n_tam % 10 > max_chu_so)
			max_chu_so = n_tam % 10;
	}
	dem = 0;
	n_tam = n;
	for (int i = 0; n_tam > 0; ++i) {
		if (n_tam % 10 == max_chu_so)
			++dem;
		n_tam = n_tam / 10;
	}
	printf("So luong chu so lon nhat cua %d: %d\n", n, dem);
	return 0;
}