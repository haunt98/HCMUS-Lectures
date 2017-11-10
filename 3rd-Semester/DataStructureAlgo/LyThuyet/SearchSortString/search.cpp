#include "search.h"

// thuat toan tim kiem tuan tu
int timTuanTu(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// thuat toan tim kiem nhi phan (binary search)
// gia su mang da duoc sap xep
int timNhiPhan(int *arr, int low, int high, int value)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == value)
        return mid;
    else if (arr[mid] > value)
        return timNhiPhan(arr, low, mid - 1, value);
    return timNhiPhan(arr, mid + 1, high, value);
}

// thuat toan tim kiem noi suy (interpolation search)
int timNoiSuy(int *arr, int low, int high, int value)
{
    if (low > high || value < arr[low] || value > arr[high])
    {
        return -1;
    }
    int mid = low + (high - low) * (value - arr[low]) / (arr[high] - arr[low]);
    if (arr[mid] == value)
        return mid;
    else if (arr[mid] > value)
        return timNoiSuy(arr, low, mid - 1, value);
    return timNoiSuy(arr, mid + 1, high, value);
}
