// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 62
#include <stdio.h>
int main(void)
{
	int a, b;
	printf("Bai 62\n");
	do {
		printf("Nhap a: ");
		scanf_s("%d", &a);
	} while (a < 1);
	do {
		printf("Nhap b: ");
		scanf_s("%d", &b);
	} while (b < 1);
	while (a > 0 && b > 0) {
		if (a >= b)
			a = a - b;
		else
			b = b - a;
	}
	if (a == 0)
		printf("UCLN: %d\n", b);
	else
		printf("UCLN: %d\n", a);
	return 0;
}