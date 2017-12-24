#include "ham.h"

void nhapMatran(intc2 &A, int &M, int &N)
{
	do{
		printf("Hang: ");
		scanf("%d", &M);
	} while (M < 1);
	do{
		printf("Cot: ");
		scanf("%d", &N);
	} while (N < 1);
	A = new int *[M];
	int i, j;
	for (i = 0; i < M; ++i)
	{
		A[i] = new int[N];
		for (j = 0; j < N; ++j)
		{
			printf("A[%d][%d]: ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
}

void xuatMatran(intc2 A, int M, int N)
{
	int i, j;
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

bool laNguyento(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0)
			return false;
	return true;
}

void trichDanhsachNguyento(intc2 A, int M, int N, intc1 &B, int &L)
{
	L = 0; int i, j;
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
			if (laNguyento(A[i][j]))
				++L;
	B = new int[L];
	intc1 p = B;
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
			if (laNguyento(A[i][j]))
				*p++ = A[i][j];
}

void xuatMang(intc1 B, int L)
{
	intc1 p;
	for (p = B; p < B + L; ++p)
		printf("%d ", *p);
	printf("\n");
}