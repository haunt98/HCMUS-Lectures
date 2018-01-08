/* quick sort in
 * lock and keys problem
 * can compare lock and key
 * (right lock and right key)
 * can't compare lock and lock
 */
#include <stdio.h>

void myswap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int parition(int *arr, int low, int high, int pivot)
{
	int i = low - 1;		 // i chi den phan tu lon hon pivot
	for (int j = low; j < high; ++j) // j chi den phan tu be hon pivot
	{
		if (arr[j] < pivot) // don nho hon ve ben trai
		{
			myswap(&arr[++i], &arr[j]);
		} else if (arr[j] == pivot) {
			myswap(&arr[j], &arr[high]); // move actual pivot
			--j;
		}
	}
	myswap(&arr[++i], &arr[high]); // move pivot to mid again
	return i;
}

void quickSort(int *lock, int *key, int low, int high)
{
	if (low < high) {
		int pivot = parition(lock, low, high, key[high]);
		parition(key, low, high, lock[pivot]);
		quickSort(lock, key, low, pivot - 1);
		quickSort(lock, key, pivot + 1, high);
	}
}

void print(int *arr, int n)
{
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int lock[] = {1, 2, 3, 4, 5};
	int key[] = {1, 4, 2, 3, 5};
	quickSort(lock, key, 0, 4);
	print(key, 5);
	print(lock, 5);
	return 0;
}
