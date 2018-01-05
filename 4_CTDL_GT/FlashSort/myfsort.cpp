#include "myfsort.h"
#include "random.h"
#include <iostream>

using namespace std;

void myFlashSort(int *arr, int size)
{
	// GIAI ÐO?N 1
	int min = arr[0];
	int iMax = 0; // V? trí c?a max
	for (int i = 1; i < size; ++i) {
		if (min > arr[i]) {
			min = arr[i];
		}
		if (arr[iMax] < arr[i]) {
			iMax = i;
		}
	}
	int max = arr[iMax];
	if (min == max) // Toàn b? ph?n t? b?ng nhau
		return;

	// Ch?n m: s? các l?p
	int m = 0.43 * size + 1;
	float c = (float)(m - 1) / (max - min);

	// T?o m?ng L luu v? trí các l?p
	int *L = new int[m + 1]; // Vì m?ng trong C b?t d?u b?ng 0
	for (int k = 0; k <= m; ++k) {
		L[k] = 0;
	}
	for (int i = 0; i < size; ++i) {
		int K = c * (arr[i] - min) + 1; // K là l?p c?a arr[i]
		++L[K];				// K ch?y t? 1 -> m
	}
	for (int k = 2; k <= m; ++k) // L[0] không s? d?ng
	{
		L[k] += L[k - 1];
	}

	// Di chuy?n s? l?n nh?t lên d?u m?ng
	int temp = arr[iMax];
	arr[iMax] = arr[0];
	arr[0] = temp;

	// GIAI ÐO?N 2
	int nMove = 0;		 // S? bu?c di chuy?n
	int j = 0;		 // V? trí d? b?t d?u hoán v?
				 // arr[j] sai v? trí
				 // ho?c j b?t d?u m?t l?p
	int K = m;		 // Bi?n v? trí biên trên c?a l?p
	while (nMove < size - 1) // Khi di chuy?n size - 1 bu?c thì d?ng
	{
		while (j >= L[K]) // arr[j] ? dúng v? trí l?p c?a nó
		{
			++j;
			K = c * (arr[j] - min) +
			    1; // C?p nh?p l?i v? trí biên c?a arr[j]
		}
		int flash =
		    arr[j]; // flash luu ph?n t? c?n di chuy?n vì sai v? trí
		while (j < L[K]) // d?ng l?i khi h?t m?t l?p
		{
			K = c * (flash - min) +
			    1;  // C?p nh?p l?i v? trí biên c?a flash
			--L[K]; // Gi?m v? trí biên
			swap(flash, arr[L[K]]); // Ðua flash vào v? trí dúng c?a
						// nó, d?ng th?i copy ph?n t? cu
						// vào flash
			++nMove;
		}
	}
	delete[] L;

	// GIAI ÐO?N 3
	// S? d?ng Insertion sort d? s?p x?p l?i t?ng ph?n t? trong l?p
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}