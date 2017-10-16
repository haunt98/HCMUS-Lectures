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
                ++j;
        }
        if (arr[i] > arr[j]) // so can sap lon hon thi stop
            break;
        myswap(arr[i], arr[j]);
        // di chuyen i,j
        i = j;
        j = i * 2 + 1;
    }
}

void heapSort(int *arr, int size)
{
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
        myswap(arr[0], arr[high]); // dua so lon nhat ve cuoi cung
        heapShift(arr, 0, high);
        high--;
    }
}

// Thuat toan quick sort
// * Buoc dau tien la paritioning, chon mot gia tri lam pivot
// Chia mang thanh 2 nua
// Nua ben trai < pivot, nua ben phai > pivot
// * Sau do de quy nua ben trai va nua ben phai
int parition(int *arr, int low, int high)
{
    int pivot = high; // chon pivot cuoi mang
    int i = low - 1;  // i chi den phan tu lon hon pivot
    int count = 0;
    for (int j = low; j < pivot; ++j) // j chi den phan tu be hon pivot
    {
        if (arr[j] <= arr[pivot]) // don nho hon ve ben trai
        {
            if (arr[j] == arr[pivot])
                ++count;
            myswap(arr[++i], arr[j]);
        }
    }
    if (count == high - low + 1) // arr[low]==arr[low+1]==...arr[high]
        return low + (high - low) / 2;
    else
    {
        myswap(arr[i + 1], arr[pivot]); // chuyen pivot den giua mang
        pivot = i + 1;                  // vi tri pivot hien tai
        return pivot;
    }
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

// Quick sort viet dua theo bai giang cua thay
int paritionLect(int *arr, int low, int high)
{
    int pivot = arr[low]; // truong hop pivot la max arr[low..high], fix o duoi
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot && i < j) // '<=' fix loi cac so bang nhau
            ++i;                         // 'i<j' fix pivot = max
        while (arr[j] > pivot)
            --j;
        myswap(arr[i], arr[j]);
    } while (i < j);
    myswap(arr[i], arr[j]); // trong lan chay cuoi cung vi tri bi sai
    myswap(arr[j], arr[low]);
    return j;
}

void quickSortLect(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = paritionLect(arr, low, high);
        quickSortLect(arr, low, pivot - 1);
        quickSortLect(arr, pivot + 1, high);
    }
}