#include "print.h"
#include <stdio.h>

void print(int *arr, int n)
{
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void printMatrix(int **matrix, int row, int col)
{
	for (int i = 0; i < row; ++i) {
		print(matrix[i], col);
	}
}
