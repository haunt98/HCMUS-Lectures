/* rotate matrix NxN
 * by 90 degree
 */
#include <stdio.h>
#include <stdlib.h>

enum direction { left, right };

void print(int **matrix, int row, int col);
void rotate(int **matrix, int row, int col, enum direction T);

int main()
{
	const int row = 3;
	const int col = 3;
	int **m;
	int val = 0;
	m = (int **)malloc(sizeof(int *) * row);
	for (int i = 0; i < row; ++i) {
		m[i] = (int *)malloc(sizeof(int) * col);
		for (int j = 0; j < col; ++j) {
			m[i][j] = ++val;
		}
	}

	rotate(m, 3, 3, left);
	print(m, 3, 3);

	for (int i = 0; i < row; ++i) {
		free(m[i]);
	}
	free(m);
	return 0;
}

void print(int **matrix, int row, int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void rotate(int **matrix, int row, int col, enum direction T)
{
	if (T == right) {
		/* 1 2 3    7 8 9
		 * 4 5 6 -> 4 5 6
		 * 7 8 9    1 2 3
		 */
		for (int i = 0, j = row - 1; i < j; ++i, --j) {
			for (int k = 0; k < col; ++k) {
				swap(&matrix[i][k], &matrix[j][k]);
			}
		}
	} else {
		/* 1 2 3    3 2 1
		 * 4 5 6 -> 6 5 4
		 * 7 8 9    9 8 7
		 */
		for (int i = 0, j = col - 1; i < j; ++i, --j) {
			for (int k = 0; k < row; ++k) {
				swap(&matrix[k][i], &matrix[k][j]);
			}
		}
	}
	// reverse by diagonal
	for (int i = 0; i < row; ++i) {
		for (int j = i + 1; j < col; ++j) {
			swap(&matrix[i][j], &matrix[j][i]);
		}
	}
}
