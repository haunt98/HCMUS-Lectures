#include "random.h"
#include "sort.h"
#include <iostream>
#include <time.h>

using namespace std;

// Cai thien radix sort cho co so bat ki
int digitBaseK(int n, int base, int k);
void radixSortBaseK(int *arr, int size, int base, int k);
void radixSortBase(int *arr, int size, int base)
{
	int max = maxArr(arr, size);
	int maxDigit = 0; // so chu so cua max theo co so
	while (max > 0) {
		++maxDigit;
		max /= base;
	}

	// Least Significant Digit
	for (int k = 1; k <= maxDigit; ++k) {
		radixSortBaseK(arr, size, base, k);
	}
}

int digitBaseK(int n, int base, int k)
{
	for (int i = 1; i < k; ++i) {
		n /= base;
	}
	return n % base;
}

void radixSortBaseK(int *arr, int size, int base, int k)
{
	// offset table
	int *count = new int[base];
	for (int i = 0; i < base; ++i) {
		count[i] = 0;
	}
	for (int i = 0; i < size; ++i) {
		++count[digitBaseK(arr[i], base, k)];
	}
	for (int i = 1; i < base; ++i) {
		count[i] += count[i - 1];
	}

	int *output = new int[size];
	for (int i = size - 1; i >= 0; --i) {
		output[--count[digitBaseK(arr[i], base, k)]] = arr[i];
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = output[i];
	}
	delete[] output;
	delete[] count;
}