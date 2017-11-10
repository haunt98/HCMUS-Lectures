#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <time.h>

using namespace std;

void myswap(int &a, int &b);
void printArr(int *arr, int size);
bool isSorted(int *arr, int size);

// low O(n^2)
void interchangeSort(int *arr, int size);
void insertionSort(int *arr, int size);

// high O(nlogn)
void heapSort(int *arr, int size);
void quickSortTime(int *arr, int size);
void mergeSortTime(int *arr, int size);

// hard O(n)
void countSort(int *arr, int size);
void radixSort(int *arr, int size);
void flashSort(int *arr, int size);

#endif
