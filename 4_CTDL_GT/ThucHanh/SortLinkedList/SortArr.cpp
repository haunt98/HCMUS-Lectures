#include "SortArr.h"
#include <iostream>

// Test
void resetArr(int *arr, int size, int *arr_test)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = arr_test[i];
    }
}

bool isSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Thuat toan quick sort
// * Buoc dau tien la paritioning, chon mot gia tri lam pivot
// Chia mang thanh 2 nua
// Nua ben trai < pivot, nua ben phai > pivot
// * Sau do de quy nua ben trai va nua ben phai
int parition(int *arr, int low, int high)
{
    int pivot = high;                 // chon pivot cuoi mang
    int i = low - 1;                  // i chi den phan tu lon hon pivot
    for (int j = low; j < pivot; j++) // j chi den phan tu be hon pivot
    {
        if (arr[j] < arr[pivot]) // don nho hon ve ben trai
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivot]); // chuyen pivot den giua mang
    pivot = i + 1;                // vi tri pivot hien tai
    return pivot;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = parition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void quickSort(int *arr, int size)
{
    quickSort(arr, 0, size - 1);
}

// Thuat toan merge sort
// * Co 2 mang da cho, merge hai mang da cho
// Chia mang lam 2 nua, merge sort 2 nua roi merge chung lai
// merge arr[low..mid] va arr[mid..high]
void merge(int *arr, int low, int mid, int high)
{
    int *t_arr = new int[high - low + 1]; // mang tam de merge
    int t_index = 0;
    int left_index = low;      // chi so low..mid
    int right_index = mid + 1; // chi so mid+1..high
    for (int i = low; i <= high; ++i)
    {
        if (left_index > mid) // nua dau da het
        {
            t_arr[t_index++] = arr[right_index++];
        }
        else if (right_index > high) // nua sau da het
        {
            t_arr[t_index++] = arr[left_index++];
        }
        else if (arr[left_index] < arr[right_index])
        {
            t_arr[t_index++] = arr[left_index++];
        }
        else
        {
            t_arr[t_index++] = arr[right_index++];
        }
    }
    for (int i = low; i <= high; ++i)
    {
        arr[i] = t_arr[i - low];
    }
    delete[] t_arr;
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2; // sua loi low, high overflow
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void mergeSort(int *arr, int size)
{
    mergeSort(arr, 0, size - 1);
}

// Insertion sort
void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Selection sort
void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}