/* if an element of matrix MxN is 0
 * its entire row and column is 0 too
 * problem is, you can't iterate the matrix,
 * case soon all value will be 0
 */
#include <stdio.h>
#include <stdlib.h>

void print(int **matrix, int row, int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void zero(int **matrix, int row, int col)
{
	// only keep track of row and col has 0
	int *zero_row = (int *)malloc(sizeof(int) * row);
	for (int i = 0; i < row; ++i)
		zero_row[i] = 0;
	int *zero_col = (int *)malloc(sizeof(int) * col);
	for (int j = 0; j < col; ++j)
		zero_col[j] = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (matrix[i][j] == 0) {
				zero_row[i] = 1;
				zero_col[j] = 1;
			}
		}
	}

	// zero-ing the matrix
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (zero_row[i] || zero_col[j]) {
				matrix[i][j] = 0;
			}
		}
	}

	free(zero_row);
	free(zero_col);
}

int main()
{
	const int row = 5;
	const int col = 5;
	int **m;
	m = (int **)malloc(sizeof(int *) * row);
	for (int i = 0; i < row; ++i) {
		m[i] = (int *)malloc(sizeof(int) * col);
		for (int j = 0; j < col; ++j) {
			m[i][j] = rand() % 3;
		}
	}

	printf("Before\n");
	print(m, 5, 5);
	zero(m, 5, 5);
	printf("After\n");
	print(m, 5, 5);

	for (int i = 0; i < row; ++i) {
		free(m[i]);
	}
	free(m);
	return 0;
}
