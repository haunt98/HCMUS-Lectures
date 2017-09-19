#include "mang.h"

#include <iostream>
using namespace std;

void MangNguyen::nhap() {
    cout << "Nhap kich thuoc mang : ";
    cin >> this->m_size;
    this->m_arr = new int[this->m_size + 1];
    for (int i = 0; i < this->m_size; i++) {
        cout << "Nhap phan tu thu " << i << " : ";
        cin >> this->m_arr[i];
    }
}

void MangNguyen::xuat() {
    for (int i = 0; i < this->m_size; i++) {
        cout << this->m_arr[i] << " ";
    }
    cout << endl;
}

int MangNguyen::layKichThuoc() { return this->m_size; }

int MangNguyen::layPhanTu(int i) { return this->m_arr[i]; }

void MangNguyen::ganPhanTu(int i, int value) { this->m_arr[i] = value; }

int MangNguyen::timPhanTu(int value) {
    this->m_arr[m_size] = value;  // dat linh canh
    int i = 0;
    while (this->m_arr[i] != value) {
        i++;
    }
    return i;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void MangNguyen::sapxep(bool (*dieukien)(int, int)) {
    for (int i = 0; i < this->m_size; i++) {
        for (int j = i + 1; j < this->m_size; j++) {
            if (!dieukien(this->m_arr[i], this->m_arr[j]))
                swap(this->m_arr[i], this->m_arr[j]);
        }
    }
}

bool dkTang(int a, int b) { return a < b; }

bool dkGiam(int a, int b) { return a > b; }

void MangNguyen::xoa() { delete[] this->m_arr; }
