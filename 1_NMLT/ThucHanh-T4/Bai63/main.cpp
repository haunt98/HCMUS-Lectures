// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 63
#include <stdio.h>
int main(void)
{
	int a, b, bcnn;
	printf("Bai 63\n");
	do {
		printf("Nhap a: ");
		scanf_s("%d", &a);
	} while (a < 1);
	do {
		printf("Nhap b: ");
		scanf_s("%d", &b);
	} while (b < 1);
	for (int i = 1; i <= b; ++i) {
		if ((a * i) % b == 0) {
			bcnn = a * i;
			break;
		}
	}
	printf("BCNN: %d\n", bcnn);
	return 0;
}
