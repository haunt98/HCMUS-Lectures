#include <math.h>
#include <stdio.h>
// Bt tinh tong S 4.4d
int main()
{
	int n, s = 0;
	printf("Nhap n\n");
	scanf("%d", &n);
	for (int i = 0; i < (int)sqrt(n); ++i) {
		s += (i + 1) * (i + 1);
	}
	printf("Tong S = %d\n", s);
	return 0;
}