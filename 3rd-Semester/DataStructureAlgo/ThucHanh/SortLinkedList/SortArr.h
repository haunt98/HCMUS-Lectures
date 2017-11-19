#ifndef _SORTARR_H
#define _SORTARR_H

using namespace std;

// Test
void resetArr(int *arr, int size, int *arr_test);
bool isSort(int *arr, int size);
void printArr(int *arr, int size);

void quickSort(int *arr, int size);
void mergeSort(int *arr, int size);

void insertionSort(int *arr, int size);
void selectionSort(int *arr, int size);

#endif