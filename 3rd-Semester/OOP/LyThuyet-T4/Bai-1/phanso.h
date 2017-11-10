#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo
{
private:
    int m_tu, m_mau;

public:
    PhanSo() : m_tu(0), m_mau(0) {}
    PhanSo(int tu, int mau);
    PhanSo(const PhanSo &ps);
    ~PhanSo() {}

    // so hoc
    PhanSo operator+(const PhanSo &ps);
    PhanSo operator*(const PhanSo &ps);

    // so sanh
    bool operator>(const PhanSo &ps);
    bool operator<(const PhanSo &ps);
    bool operator==(const PhanSo &ps);
    bool operator>=(const PhanSo &ps);
    bool operator<=(const PhanSo &ps);
    bool operator!=(const PhanSo &ps);

    // gan
    PhanSo &operator=(const PhanSo &ps);
    PhanSo &operator+=(const PhanSo &ps);
    PhanSo &operator*=(const PhanSo &ps);

    // mot ngoi
    PhanSo &operator++();
    PhanSo operator++(int);
    PhanSo &operator--();
    PhanSo operator--(int);

    // ep kieu
    operator float();
    operator int();

    // nhap xuat
    friend istream &operator>>(istream &in, PhanSo &ps);
    friend ostream &operator<<(ostream &out, const PhanSo &ps);
};

#endif
