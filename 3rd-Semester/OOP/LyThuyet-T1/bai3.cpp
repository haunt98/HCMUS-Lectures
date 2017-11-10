#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
};

// ham dieu kien so sanh
template <class T>
bool beHon(T a, T b) {
    return a < b;
}

bool beHon(PhanSo a, PhanSo b) { return a.tu * b.mau < b.tu * a.mau; }

template <class T>
bool lonHon(T a, T b) {
    return a > b;
}

bool lonHon(PhanSo a, PhanSo b) { return a.tu * b.mau > b.tu * a.mau; }

// ham hoan doi
template <class T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

// ham sap xep mang voi thuat toan Interchange Sort
template <class T>
void sxepMang(T *arr, int size, bool (*dieuKien)(T, T)) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!dieuKien(arr[i], arr[j]))  // khong dung dieu kien thi swap
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// ham print tuy theo int hay PhanSo
template <class T>
void printType(T a) {
    cout << a << " ";
}

void printType(PhanSo a) { printf("%d/%d ", a.tu, a.mau); }

template <class T>
void inMang(T *arr, int size) {
    for (int i = 0; i < size; i++) {
        printType(arr[i]);
    }
    cout << endl;
}

int main() {
    cout << "int" << endl;
    int A[] = {9, 8, 7, 6, 5, 4, 3, 1, 2};
    int size_A = sizeof(A) / sizeof(A[0]);
    cout << "be hon : " << endl;
    sxepMang(A, size_A, beHon);
    inMang(A, size_A);
    cout << "lon hon : " << endl;
    sxepMang(A, size_A, lonHon);
    inMang(A, size_A);

    cout << "PhanSo" << endl;
    PhanSo B[] = {{1, 2}, {-1, 3}, {4, 5}, {7, 2}, {10, 19}};
    int size_B = sizeof(B) / sizeof(B[0]);
    cout << "be hon : " << endl;
    sxepMang(B, size_B, beHon);
    inMang(B, size_B);
    cout << "lon hon : " << endl;
    sxepMang(B, size_B, lonHon);
    inMang(B, size_B);
    return 0;
}
