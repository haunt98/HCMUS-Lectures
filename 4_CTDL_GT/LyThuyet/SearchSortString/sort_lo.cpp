#include "sort.h"

void myswap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Thuat toan chen (insertion sort)
// Bat dau tu arr[1]->arr[size-1]
// Chen arr[i] vao mang da sap xep o truoc
// nhu sap xep la bai
void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        // chen arr[i] vao mang da sap xep arr[0..i-1]
        // 1 3 5 7 9 4 x=4
        // 1 3 5 7 9 9
        // 1 3 5 7 7 9
        // 1 3 5 5 7 9
        // 1 3 4 5 7 9
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Tim i, arr[i] > x && arr[i - 1] < x
// de chen x vao giua trong insertion sort
int binarySearch(int *arr, int low, int high, int x)
{
    if (low > high)
    {
        return low; // ca mang deu < x, tra ve vi tri cua x
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] > x)
    {
        if (mid == 0 || arr[mid - 1] < x)
            return mid;
        else
            return binarySearch(arr, low, mid - 1, x);
    }

    return binarySearch(arr, mid + 1, high, x);
}

// cai tien insertion sort bang cach tim nhi phan
void insertionSortBinary(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        // chen key vao mang da sap xep arr[0..i-1]
        int j = binarySearch(arr, 0, i - 1, key); // tra ve i neu khong thay
        // dich mang sang phai de tao khoang trong cho key
        for (int k = i - 1; k >= j; --k)
        {
            arr[k + 1] = arr[k];
        }
        arr[j] = key;
    }
}

// Thuat toan sap xep noi bop (bubble sort)
// i: 1 -> size-1
// j: size-1 -> i
// swap cac cap ngich the (j,j-1)
// Sau moi lan so nho nhat se noi len tren
// lan tiep la so nho thu hai
void bubbleSort(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        for (int j = size - 1; j >= i; --j)
        {
            if (arr[j - 1] > arr[j])
                myswap(arr[j - 1], arr[j]);
        }
    }
}

// Cai tien tu bubble sort la shake sort
// * Sau mot lan duyet, neu khong swap thi mang sap xep xong
// * Bat dau duyet tu swap cuoi cung
// vi sau do la da sap xep xog
// * Dan xen duoi len, tren xuong,
// vi duoi len so nho nhat len dau ngay,
// con tren xuong so lon nhat xuong duoi cung
bool shakeTop(int *arr, int &low, int &high);
bool shakeBot(int *arr, int &low, int &high);
void shakeSort(int *arr, int size)
{
    for (int low = 0, high = size - 1; low < high;)
    {
        bool flag; // kiem tra su xuat hien cap nghich the
        // thay phien: tren xuong duoi len
        flag = shakeTop(arr, low, high); // so lon nhat xuong cuoi cung
        if (!flag)
            break;
        flag = shakeBot(arr, low, high); // so nho nhat len dau tien
        if (!flag)
            break;
    }
}

bool shakeTop(int *arr, int &low, int &high)
{
    bool flag = false; // kiem tra cap nghich the
    int last_swap = high - 1;
    for (int i = low; i < high; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            myswap(arr[i], arr[i + 1]);
            flag = true; // phat hien cap nghich the
            last_swap = i;
        }
    }
    high = last_swap; // shake tiep theo bat dau tu swap cuoi cung
    return flag;
}

bool shakeBot(int *arr, int &low, int &high)
{
    bool flag = false; // kiem tra cap nghich the
    int last_swap = low + 1;
    for (int i = high; i > low; --i)
    {
        if (arr[i - 1] > arr[i])
        {
            myswap(arr[i - 1], arr[i]);
            flag = true; // phat hien cap nghich the
            last_swap = i;
        }
    }
    low = last_swap; // shake tiep theo bat dau tu swap cuoi cung
    return flag;
}

// Giong bubble sort nhung thay doi moi lan duyet,
// Tu tren xuong va duoi len
void shakerSort(int *arr, int size)
{
    for (int i = 0; i < size;)
    {
        // tu tren xuong
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j - 1] > arr[j])
                myswap(arr[j - 1], arr[j]);
        }
        // max -> cuoi mang nen bo di
        --size;

        // tu duoi len
        for (int j = size - 1; j > i; --j)
        {
            if (arr[j - 1] > arr[j])
                myswap(arr[j - 1], arr[j]);
        }
        // min -> dau mang nen bo di
        ++i;
    }
}