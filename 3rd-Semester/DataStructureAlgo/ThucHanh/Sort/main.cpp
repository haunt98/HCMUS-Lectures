// So sanh thoi gian cac thuat toan tim kiem
// Interchange Sort
// Insertion Sort
// Quick Sort
// Heap Sort
// Radix Sort
// Flash Sort
#include "random.h"
#include "sort.h"

#define MAXSIZE 10000

int main()
{
    int *arr, size = MAXSIZE;
    randArr(arr, size);

    int *arr_cp1 = new int[MAXSIZE];
    copyArr(arr, size, arr_cp1);
    interchangeSort(arr_cp1, size);
    // cout << isSorted(arr_cp1, size) << endl;
    delete[] arr_cp1;

    int *arr_cp2 = new int[MAXSIZE];
    copyArr(arr, size, arr_cp2);
    insertionSort(arr_cp2, size);
    // cout << isSorted(arr_cp2, size) << endl;
    delete[] arr_cp2;

    int *arr_cp3 = new int[MAXSIZE];
    copyArr(arr, size, arr_cp3);
    quickSortTime(arr_cp3, size);
    // cout << isSorted(arr_cp3, size) << endl;
    delete[] arr_cp3;

    int *arr_cp4 = new int[MAXSIZE];
    copyArr(arr, size, arr_cp4);
    heapSort(arr_cp4, size);
    // cout << isSorted(arr_cp4, size) << endl;
    delete[] arr_cp4;

    int *arr_cp5 = new int[MAXSIZE];
    copyArr(arr, size, arr_cp5);
    radixSort(arr_cp5, size);
    // cout << isSorted(arr_cp5, size) << endl;
    delete[] arr_cp5;

    int *arr_cp6 = new int[MAXSIZE];
    copyArr(arr, size, arr_cp6);
    flashSort(arr_cp6, size);
    // cout << isSorted(arr_cp6, size) << endl;
    delete[] arr_cp6;

    delete[] arr;
    return 0;
}
