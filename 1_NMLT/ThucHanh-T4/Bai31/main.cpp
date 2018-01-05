// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 31
#include <math.h>
#include <stdio.h>
int main(void)
{
	int n, state;
	printf("Bai 31\n");
	do {
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	state = 1;
	if (n == 1)
		state = 0;
	for (int i = 2; i <= sqrt((double)n); ++i) {
		if (n % i == 0) {
			state = 0;
			break;
		}
	}
	if (state == 1)
		printf("%d la so nguyen to\n", n);
	else
		printf("%d khong phai la so nguyen to\n", n);
	return 0;
}