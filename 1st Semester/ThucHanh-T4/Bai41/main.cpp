//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 41
#include <stdio.h>
int main(void)
{
	int n;
	float S;
	printf("Bai 41\n");
	do{
		printf("Nhap n = ");
		scanf_s("%d", &n);
	} while (n < 1);
	S = 2;
	for (int i = 0; i < n; ++i)
	{
		S = 1 + 1.0 / S;
	}
	S = S - 1;
	printf("S = %f\n", S);
	return 0;
}