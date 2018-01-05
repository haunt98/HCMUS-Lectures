#include "sort.h"

void myswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printArr(int *arr, int size)
{
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool isSorted(int *arr, int size)
{
	if (size == 1)
		return true;
	if (arr[size - 2] > arr[size - 1])
		return false;
	return isSorted(arr, size - 1);
}

// Thuat toan selection sort
// Moi lan chay tim so nho nhat dua len dau
// Thoi gian chay cho mang da sap va mang chua sap la nhu nhau
void interchangeSort(int *arr, int size)
{
	clock_t begin = clock();
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (arr[i] > arr[j])
				myswap(arr[i], arr[j]);
		}
	}
	clock_t end = clock();
	cout << "Interchange sort: " << (double)(end - begin) / CLOCKS_PER_SEC
	     << endl;
}

// Thuat toan chen (insertion sort)
// Bat dau tu arr[1]->arr[size-1]
// Chen arr[i] vao mang da sap xep o truoc
// nhu sap xep la bai
void insertionSort(int *arr, int size)
{
	clock_t begin = clock();
	for (int i = 1; i < size; ++i) {
		int key = arr[i];
		// chen arr[i] vao mang da sap xep arr[0..i-1]
		// 1 3 5 7 9 4 x=4
		// 1 3 5 7 9 9
		// 1 3 5 7 7 9
		// 1 3 5 5 7 9
		// 1 3 4 5 7 9
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
	clock_t end = clock();
	cout << "Insertion sort: " << (double)(end - begin) / CLOCKS_PER_SEC
	     << endl;
}