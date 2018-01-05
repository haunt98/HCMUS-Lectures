#include "sort.h"

// Thuat toan radix sort
// Lan luot chay count sort cho hang don vi, hang chuc, tram ...
void countSortMod(int *arr, int size, int d);
void radixSort(int *arr, int size)
{
	clock_t begin = clock();
	// tim max
	int max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max)
			max = arr[i];
	}

	// d = 1, 10, 100, ... < max
	int d = 1;
	while (d < max) {
		countSortMod(arr, size, d);
		d *= 10;
	}
	clock_t end = clock();
	cout << "Radix sort: " << (double)(end - begin) / CLOCKS_PER_SEC
	     << endl;
}

void countSortMod(int *arr, int size, int d)
{
	// d = 1, 10, 100, ...
	// tao mang count chua so lan xuat hien cac chu so trong (arr/d) % 10
	int count[10] = {0}; // cac chu so 0..9
	for (int i = 0; i < size; ++i) {
		++count[(arr[i] / d) % 10]; // so lan xuat hien
	}
	for (int i = 1; i < 10; ++i)

	{
		count[i] +=
		    count[i - 1]; // count[i] the hien so cac chu so <= i
	}

	int *output = new int[size];
	for (int i = size - 1; i >= 0; i--) // di nguoc lai de bao toan ON DINH
	{
		output[--count[(arr[i] / d) % 10]] = arr[i];
	}
	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
	}
	delete[] output;
}

// Thuat toan flash sort
// Y tuong, min = 1, max = 100 => 50 co the nam o giua
void flashSort(int *arr, int size)
{
	clock_t begin = clock();
	int i_max = 0, min = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > arr[i_max]) {
			i_max = i;
		}
	}
	if (min == arr[i_max]) {
		return;
	}

	int m = 0.45 * size;
	int *L = new int[m];

	float c1 = (m - 1) / (arr[i_max] - min);

	for (int k = 0; k < m; k++) {
		L[k] = 0;
	}
	for (int j = 0; j < size; ++j) {
		int k = c1 * (arr[j] - min);
		++L[k];
	}

	for (int p = 1; p < m; ++p) {
		L[p] += L[p - 1];
	}

	myswap(arr[0], arr[i_max]);

	// permutation
	int move = 0;
	int j = 0;
	int k = m - 1;
	while (move < size - 1) {
		while (j > L[k] - 1) {
			++j;
			k = c1 * (arr[j] - min);
		}
		int flash = arr[j];
		while (j != L[k]) {
			k = c1 * (flash - min);
			int t = --L[k];
			myswap(arr[t], flash);
			++move;
		}
	}
	delete[] L;

	// insertion sort
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
	clock_t end = clock();
	cout << "Flash sort: " << (double)(end - begin) / CLOCKS_PER_SEC
	     << endl;
}
