//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 39
#include <stdio.h>
#include <math.h>
int main(void)
{
	int n, giai_thua;
	float S;
	printf("Bai 39\n");
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	S = 0;
	giai_thua = 1;
	for (int i = 1; i <= n; ++i)
	{
		giai_thua = giai_thua * i;
		S = pow(S + giai_thua, (float)1 / (i + 1));
	}
	printf("S = %f\n", S);
	return 0;
}