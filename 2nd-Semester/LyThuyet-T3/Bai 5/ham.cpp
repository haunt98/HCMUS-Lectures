#include "ham.h"

void tang_dan(int *a, int *b)
{
	if (*a > *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

void giam_dan(int *a, int *b)
{
	if (*a < *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

void sap_xep(int *A, int so_luong, so_sanh T)
{
	int i, j;
	for (i = 0; i < so_luong; ++i)
		for (j = i + 1; j < so_luong; ++j)
			T(&A[i], &A[j]);
}