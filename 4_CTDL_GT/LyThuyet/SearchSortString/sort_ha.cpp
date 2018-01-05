#include "sort.h"
#include <stdlib.h>

// Thuat toan count sort, khong so sanh
// *Nhuoc diem:
// sap xep 3 so: 1 , 10..0, 2 can tao mang[0...10..0] ton bo nho
void countSort(int *arr, int size)
{
	// tim max de tao mang count[0..max]
	int max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	// Tao offset table
	int *count = new int[max + 1];
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}
	for (int i = 0; i < size; ++i) {
		count[arr[i]]++; // so lan xuat hien cua arr[i]
	}

	for (int i = 1; i <= max; ++i) {
		count[i] += count[i - 1]; // so cac so <= i la count[i]
	}

	int *output = new int[size];
	for (int i = size - 1; i >= 0; --i) // di tu phai qua trai de ON DINH
	{
		output[--count[arr[i]]] = arr[i];
	}
	delete[] count;
	for (int i = 0; i < size; ++i) // copy tro lai arr
	{
		arr[i] = output[i];
	}
	delete[] output;
}

// Count sort va radix sort la thuat toan sap xep on dinh
// vi du truoc khi sap xep 25 dung truoc 55
// sau khi sap xep 25 cung dung truoc 55

// Thuat toan radix sort
// Radix hay Base: nghia la co so
// ban chat la count sort voi tung chu so
// di tu LSD (least significant digit) vi du 123 la 3
// * Nhuoc diem: Radix sort chi phi O(n),
// nhung thuc te la k*n, k la so chu so cua max
// neu k > logn thi Radix sort cham hon
// mot so thuat toan O(nlogn)
// * Cai thien: khong xai co so 10 vi qua nho
// su dung co so 2^16 chang han
int digit(int n, int k);
int maxArr(int *arr, int size);
void radixSortLectK(int *arr, int size, int k) // count sort cho chu so thu k
{
	int count[10] = {0};
	for (int i = 0; i < size; ++i) {
		++count[digit(arr[i],
			      k)]; // so lan xuat hien chu so thu k cua tung so
	}
	for (int i = 1; i < 10; ++i) {
		count[i] += count[i - 1]; // so cac so co chu so thu k <= i
	}

	int *output = new int[size];
	for (int i = size - 1; i >= 0; --i) // phai qua trai de bao toan ON DINH
	{
		output[--count[digit(arr[i], k)]] = arr[i];
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = output[i]; // copy vao lai mang
	}
	delete[] output;
}

void radixSortLect(int *arr, int size)
{
	int max = maxArr(arr, size);
	int max_digit = 0; // so chu so cua max
	while (max > 0) {
		++max_digit;
		max /= 10;
	}
	// lan luot chay tu chu so hang don vi, chuc, tram ...
	for (int i = 1; i <= max_digit; ++i) {
		radixSortLectK(arr, size, i);
	}
}

int digit(int n, int k)
{
	for (int i = 1; i < k; ++i) // chia cho 10^(k-1)
	{
		n /= 10;
	}
	return n % 10;
}

int maxArr(int *arr, int size)
{
	int max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

// Thuat toan radix sort su dung con tro cap phat dong
void radixSortDA(int *arr, int size)
{
	// lay max va so chu so cua max
	int max = maxArr(arr, size);
	int max_digit = 0; // so chu so cua max
	while (max > 0) {
		++max_digit;
		max /= 10;
	}
	int **count;
	for (int d = 1; d <= max_digit;
	     ++d) // vong lap het so cac chu so cua max
	{
		// lap cac so vao 10 cot
		count = new int *[10]; // mang luu cac so duoc sap vao tung cot
		int size_count[10] = {0};      // kich thuoc count[10][i]
		for (int i = 0; i < size; ++i) // vong lap theo arr
		{
			int temp_digit = digit(arr[i], d);
			if (size_count[temp_digit] == 0)
				count[temp_digit] = new int[size];
			count[temp_digit][size_count[temp_digit]++] =
			    arr[i]; // them so vao cot
		}
		// dua cac so tu cot vao lai mang
		int index = 0; // index cho arr, chay tu 0->size-1;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < size_count[i]; ++j) {
				arr[index++] = count[i][j];
			}
		}
		// delete memory used
		for (int i = 0; i < 10; ++i) {
			if (size_count[i] > 0)
				delete[] count[i];
		}
		delete[] count;
	}
}

// Radix sort nhung bat dau tu MSD (chu so dau tien)
// Vi du 123 bat dau tu 1 -> 2 -> 3
// Moi lan chay phan hoach thanh 10 doan nho: cac so chu so dau =1, =2 , ..
// Sau do de quy tung doan nho nay thanh 10 doan nho hon nua
void radixSortMSDforK(int *arr, int low, int high, int k)
{
	if (low < high && k > 0) {
		int count[10] = {0}; // co so 10
		for (int i = low; i <= high; ++i) {
			++count[digit(arr[i], k)];
		}
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		int *output = new int[high - low + 1];
		for (int i = high; i >= low; --i) {
			output[--count[digit(arr[i], k)]] =
			    arr[i]; // vi arr[0..size-1] nen --prefix
		}
		for (int i = low; i <= high; ++i) {
			arr[i] = output[i - low];
		}
		delete[] output;

		// recursive step, chia thanh 10 doan nho
		radixSortMSDforK(arr, low, low + count[1] - 1, k - 1);
		for (int i = 1; i < 9; ++i)
			radixSortMSDforK(arr, low + count[i],
					 low + count[i + 1] - 1, k - 1);
		radixSortMSDforK(arr, low + count[9], high, k - 1);
	}
}

void radixSortMSD(int *arr, int size)
{
	// lay max va so chu so cua max
	int max = maxArr(arr, size);
	int max_digit = 0; // so chu so cua max
	while (max > 0) {
		++max_digit;
		max /= 10;
	}
	radixSortMSDforK(arr, 0, size - 1, max_digit);
}

void flashSortLect(int *arr, int size)
{
	// Giai doan 1
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	if (min == max)
		return;

	int m = 0.43 * size; // Chia lam m lop
	float c = (float)(m - 1) / (max - min);

	int *L = new int[m + 1];
	for (int k = 0; k <= m; ++k) {
		L[k] = 0;
	}
	for (int i = 0; i < size; ++i) {
		int k = c * (arr[i] - min) + 1;
		++L[k]; // L[k]: so phan tu cua lop k
	}
	for (int k = 2; k <= m; ++k) {
		L[k] += L[k - 1]; // L[k]: bien tren cua lop k
	}

	// Giai doan 2
	int move = 0; // so buoc di chuyen
	int j = 0;
	int k = m;
	while (move < size - 1) // Chi can di chuyen size - 1 phan tu
	{
		while (j >= L[k]) // arr[j] dúng l?p c?a nó
		{
			++j;
			k = c * (arr[j] - min) + 1;
		}
		int flash = arr[j];
		while (j < L[k]) // dung khi thay doi lai arr[j]
		{
			k = c * (flash - min) + 1;
			myswap(flash, arr[--L[k]]);
			++move;
		}
	}

	// Giai doan 3
	// Insertion sort cho tung phan lop
	// Bo qua phan lop m, vi chua toan max
	for (int k = 1; k < m; ++k) {
		for (int i = L[k] + 1; i < L[k + 1]; ++i) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = key;
		}
	}
	delete[] L;
}