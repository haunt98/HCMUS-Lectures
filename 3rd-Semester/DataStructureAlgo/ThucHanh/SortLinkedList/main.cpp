#include "LinkedList.h"
#include "SortArr.h"
#include "SortLinkedList.h"
#include <iostream>
#include <time.h>

using namespace std;

void randTest(int *, int);
void calcTime(List &l, void (*SortList)(List &));
void calcTime(int *arr, int size, void (*SortArr)(int *arr, int size));

int main()
{
    const int size = 1000;
    int *arr = new int[size];
    int *arr_test = new int[size];
    randTest(arr_test, size);
    List l;
    initList(l);

    // Quick sort
    cout << "Quick sort" << endl;
    cout << "List: ";
    resetList(l, size, arr_test);
    calcTime(l, quickSort);

    cout << "Arr: ";
    resetArr(arr, size, arr_test);
    calcTime(arr, size, quickSort);

    // Merge sort
    cout << "Merge sort" << endl;
    cout << "List: ";
    resetList(l, size, arr_test);
    calcTime(l, mergeSort);

    cout << "Arr: ";
    resetArr(arr, size, arr_test);
    calcTime(arr, size, mergeSort);

    // Insertion sort
    cout << "Insertion sort" << endl;
    cout << "List: ";
    resetList(l, size, arr_test);
    calcTime(l, insertionSort);

    cout << "Arr: ";
    resetArr(arr, size, arr_test);
    calcTime(arr, size, insertionSort);

    // Selection sort
    cout << "Selection sort" << endl;
    cout << "List: ";
    resetList(l, size, arr_test);
    calcTime(l, selectionSort);

    cout << "Arr: ";
    resetArr(arr, size, arr_test);
    calcTime(arr, size, selectionSort);

    // Prevent memory leak
    delList(l);
    delete[] arr;
    delete[] arr_test;
    return 0;
}

void randTest(int *arr_test, int size)
{
    srand(time(NULL));
    const int RANDMAX = 10000;
    for (int i = 0; i < size; ++i)
    {
        arr_test[i] = rand() % RANDMAX;
    }
}

void calcTime(List &l, void (*SortList)(List &l))
{
    clock_t begin = clock();
    SortList(l);
    clock_t end = clock();
    cout << (double)(end - begin) / CLOCKS_PER_SEC << endl;
}

void calcTime(int *arr, int size, void (*SortArr)(int *arr, int size))
{
    clock_t begin = clock();
    SortArr(arr, size);
    clock_t end = clock();
    cout << (double)(end - begin) / CLOCKS_PER_SEC << endl;
}
