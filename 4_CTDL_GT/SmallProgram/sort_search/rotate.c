#include <stdio.h>

int searchRotate(int *arr, int left, int right, int x);

int main()
{
	int A[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
	int size = sizeof(A) / sizeof(A[0]);
	for (int i = 1; i <= 9; ++i)
		printf("%d\n", searchRotate(A, 0, size - 1, i));
	return 0;
}

/* rotated sorted arr : 6 7 8 9 1 2 3
 * find 3 - is arr[6]
 */
int searchRotate(int *arr, int left, int right, int x)
{
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x)
			return mid;
		// left..mid is sorted
		if (arr[left] <= arr[mid]) {
			if (x > arr[mid] || x < arr[left])
				left = mid + 1;
			else
				right = mid - 1;
		}
		// mid..right is sorted
		else {
			if (x > arr[right] || x < arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return -1;
}
