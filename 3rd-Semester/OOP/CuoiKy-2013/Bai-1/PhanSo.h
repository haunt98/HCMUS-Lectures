#ifndef _PHAN_SO_H
#define _PHAN_SO_H

#include <iostream>
using namespace std;

class PhanSo
{
private:
    int m_tu, m_mau;

public:
    PhanSo();
    PhanSo(int tu, int mau);
    PhanSo(int n);
    PhanSo &operator=(const PhanSo ps);
    PhanSo operator+(const PhanSo ps);
    PhanSo &operator+=(const PhanSo ps);
    PhanSo &operator++();
    friend ostream &operator<<(ostream &out, const PhanSo ps);
    // ep kieu
    operator int();
};

#endif
