#include "random.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define RANDMAX 10000

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArr(int *arr, int size, int *new_arr)
{
    for (int i = 0; i < size; ++i)
    {
        new_arr[i] = arr[i];
    }
}

void randArr(int *arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % RANDMAX;
    }
}

void calcTime(int *arr, int size, void (*sort)(int *, int))
{
    clock_t begin = clock();
    sort(arr, size);
    clock_t end = clock();
    cout << "Time: " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
}

void calcTime(int *arr, int left, int right, void (*sort)(int *, int, int))
{
    clock_t begin = clock();
    sort(arr, left, right);
    clock_t end = clock();
    cout << "Time: " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
}

bool isSorted(int *arr, int size)
{
    if (size == 1)
        return true;
    if (arr[size - 2] > arr[size - 1])
        return false;
    return isSorted(arr, size - 1);
}
