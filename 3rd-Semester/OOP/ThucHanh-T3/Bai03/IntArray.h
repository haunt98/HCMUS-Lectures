#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
using namespace std;

class IntArray
{
private:
    int m_size;
    int *m_arr;

public:
    IntArray() : m_size(0), m_arr(NULL) {}
    IntArray(int size);
    IntArray(int *arr, const int &size);
    IntArray(const IntArray &mang);
    ~IntArray();

    // toan tu
    IntArray &operator=(const IntArray &mang);
    int &operator[](int i);
    operator int();

    // nhap xuat
    friend istream &operator>>(istream &in, IntArray &mang);
    friend ostream &operator<<(ostream &out, const IntArray &mang);
};

#endif