#include "ham.h"

int main(void)
{
	int A[] = { 1, 4, 2, 5, 3, 6, 7, 8, 9, 10 };
	so_sanh T = tang_dan;
	sap_xep(A, 10, T);
	for (int i = 0; i < 10; ++i)
		printf("%d ", A[i]);
	return 0;
}