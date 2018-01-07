#include <stdio.h>

void merge(int A[], int n, int B[], int m);

int main()
{
	int A[20] = {1, 3, 5, 7, 9, 11};
	int B[] = {2, 6};

	merge(A, 6, B, 2);
	for (int i = 0; i < 8; ++i) {
		printf("%d\n", A[i]);
	}
	return 0;
}

// A has enough buffer for B
void merge(int A[], int n, int B[], int m)
{
	// assume A[0..m+n-1]
	int x = n - 1;
	int y = m - 1;

	// stop when done copy B
	for (int i = m + n - 1; i >= 0 && y >= 0; --i) {
		if (A[x] > B[y])
			A[i] = A[x--];
		else
			A[i] = B[y--];
	}
}
