#include "sort.h"

// Thuat toan heap sort
// 5 2 8 3 4 1 7 6
//         - - - -
// 5 2 8 6 4 1 7 3
//       - - - - -
// 5 2 8 6 4 1 7 3
//     - - - - - -
// 5 6 8 3 4 1 7 2
//   - - - - - - -
// 8 6 7 3 4 1 5 2
// * Dau tien tu mang da cho -> mang heap (heapShift)
// mang A[0..n-1] cat ra mot nua A[0..n/2] va A[n/2+1..n-1]
// nua sau khong dung vao
// bat dau dua A[n/2]->A[0] vao nua sau theo heap
// * A[i] muon dua vao A[i+1..n-1] theo heap
// so sanh A[i] va A[j]=max(A[i*2+1],A[i*2+2])
// neu A[i] lon hon, stop va chuyen qua A[i-1]
// neu A[i] be hon, swap(A[i],A[j])
// i thay bang j, A[j] lai la max nhu tren
// tiep tuc cho toi i=0
// * Muon dua ve mang sap xep tu mang heap
// buoc 1, swap A[0] va A[cuoi] -> so lon nhat o cuoi day
// buoc 2, bo di A[cuoi], dua A[0] vao mang con lai theo heap
void heapShift(int *arr, int index, int size)
{
    // dat arr[index] vao arr[index+1..size-1] theo heap
    int i = index;
    int j = 2 * i + 1; // vi i co the = 0
    while (j < size)
    {
        if (j != size - 1) // j chua di den cuoi mang
        {
            if (arr[j + 1] > arr[j]) // chon so lon hon arr[j], arr[j+1]
                j++;
        }
        if (arr[i] > arr[j]) // so can sap lon hon thi stop
            break;
        swap(arr[i], arr[j]);
        // di chuyen i,j
        i = j;
        j = i * 2 + 1;
    }
}

void heapSort(int *arr, int size)
{
    clock_t begin = clock();
    // tao thanh mang heap O(nlogn)
    int low = size / 2;
    while (low >= 0)
    {
        heapShift(arr, low, size);
        low--;
    }
    // bat dau sap xep O(nlogn)
    int high = size - 1;
    while (high >= 0)
    {
        swap(arr[0], arr[high]); // dua so lon nhat ve cuoi cung
        heapShift(arr, 0, high);
        high--;
    }
    clock_t end = clock();
    cout << "Heap sort: " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
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

void quickSortTime(int *arr, int size)
{
    clock_t begin = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();
    cout << "Quick sort: " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
}