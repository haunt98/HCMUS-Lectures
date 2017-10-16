#ifndef SORT_H
#define SORT_H

void myswap(int &a, int &b);
int maxArr(int *arr, int size);

// sap xep bac thap O(n^2)
void insertionSort(int *arr, int size);
void insertionSortBinary(int *arr, int size);
void bubbleSort(int *arr, int size);
void shakeSort(int *arr, int size);

// sap xep bac cao O(nlogn)
void heapSort(int *arr, int size);
void quickSort(int *arr, int low, int high);
void quickSortLect(int *arr, int low, int high); // Follow lecture of teacher
void mergeSort(int *arr, int low, int high);

// sap xep khong duoi tren so sanh
void countSort(int *arr, int size);
void radixSortLect(int *arr, int size); // Least significant digit
void radixSortDA(int *arr, int size);   // Dynamic array
void radixSortMSD(int *arr, int size);  // Most significant digit
void flashSortLect(int *arr, int size); // Follow teacher

// Chinh sua
void radixSortBase(int *arr, int size, int base); // Su dung co so bat ki

#endif
