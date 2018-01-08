#include <stdio.h>
#include <stdlib.h>

void sortfive(int *arr, int n)
{
	if (n <= 5) {
		for (int i = 1; i < n; ++i) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = key;
		}
	}
}

void merge(int *arr, int low, int mid, int high)
{
	int *t_arr =
	    (int *)malloc((high - low + 1) * sizeof(int)); // mang tam de merge
	int t_index = 0;
	int left_index = low;      // chi so low..mid
	int right_index = mid + 1; // chi so mid+1..high

	// pre sortfive
	if (mid - low < 5)
		sortfive(arr + low, mid - low + 1);
	if (high - (mid + 1) < 5)
		sortfive(arr + mid + 1, high - mid);

	for (int i = low; i <= high; ++i) {
		if (left_index > mid) // nua dau da het
		{
			t_arr[t_index++] = arr[right_index++];
		} else if (right_index > high) // nua sau da het
		{
			t_arr[t_index++] = arr[left_index++];
		} else if (arr[left_index] < arr[right_index]) {
			t_arr[t_index++] = arr[left_index++];
		} else {
			t_arr[t_index++] = arr[right_index++];
		}
	}
	for (int i = low; i <= high; ++i) {
		arr[i] = t_arr[i - low];
	}
	free(t_arr);
}

void mergeSort(int *arr, int low, int high)
{
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
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
	int arr[] = {5, 4, 3, 2, 1, 7, 8, 9, 10, -1, -2, -3};
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, size - 1);
	print(arr, size);
	return 0;
}
