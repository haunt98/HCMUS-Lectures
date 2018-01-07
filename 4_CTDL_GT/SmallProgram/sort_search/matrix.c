/* given matrix which
 * each row, each col is sorted
 * method to search
 */
#include "print.h"
#include <stdio.h>
#include <stdlib.h>

struct Pos {
	int row, col;
};

int searchArr(int *arr, int size, int x);
struct Pos searchMatrix(int **matrix, int row, int col, int x);

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

	printMatrix(m, row, col);
	struct Pos p = searchMatrix(m, row, col, 0);
	printf("%d %d\n", p.row, p.col);

	for (int i = 0; i < row; ++i) {
		free(m[i]);
	}
	free(m);
	return 0;
}

int searchArr(int *arr, int size, int x)
{
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
struct Pos searchMatrix(int **matrix, int row, int col, int x)
{
	struct Pos p = {-1, -1};
	for (int i = 0; i < row; ++i) {
		int found = searchArr(matrix[i], col, x);
		if (found != -1) {
			p.row = i;
			p.col = found;
		}
	}
	return p;
}
