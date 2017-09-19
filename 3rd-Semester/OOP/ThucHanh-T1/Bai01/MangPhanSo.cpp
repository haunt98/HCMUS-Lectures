#include "PhanSo.h"
#include "MangPhanSo.h"
#include <iostream>

using namespace std;

void MangPhanSo::nhap()
{
    do {
        cout << "Nhap kich thuoc mang phan so : ";
        cin >> this->size;
    } while (this->size < 1);
    this->mang = new PhanSo[size];
    for (int i = 0; i < size; i++) {
        this->mang[i].nhap();
    }
}

void MangPhanSo::xuat()
{
    for (int i = 0; i < size; i++) {
        this->mang[i].xuat();
    }
}

void MangPhanSo::xoa()
{
    delete[] this->mang;
}

PhanSo MangPhanSo::tong()
{
    PhanSo temp;
    temp.gan(0, 1);
    for (int i = 0; i < size; i++) {
        temp = temp.cong(this->mang[i]);
    }
    return temp;
}

PhanSo MangPhanSo::tich()
{
    PhanSo temp;
    temp.gan(1, 1);
    for (int i = 0; i < size; i++) {
        temp = temp.nhan(this->mang[i]);
    }
    return temp;
}

PhanSo MangPhanSo::min()
{
    PhanSo temp = this->mang[0];
    for (int i = 1; i < size; i++) {
        if (temp.sosanh(this->mang[i]) > 0) {
            temp = this->mang[i];
        }
    }
    return temp;
}

PhanSo MangPhanSo::max()
{
    PhanSo temp = this->mang[0];
    for (int i = 1; i < size; i++) {
        if (temp.sosanh(this->mang[i]) < 0) {
            temp = this->mang[i];
        }
    }
    return temp;
}

void MangPhanSo::xuatAm()
{
    for (int i = 0; i < size; i++) {
        if (this->mang[i].xetdau() < 0)
            this->mang[i].xuat();
    }
}

int MangPhanSo::demDuong()
{
    int dem = 0;
    for (int i = 0; i < size; i++) {
        if (this->mang[i].xetdau() > 0)
            dem++;
    }
    return dem;
}

bool MangPhanSo::tang(PhanSo a, PhanSo b)
{
    return a.sosanh(b) < 0;
}

bool MangPhanSo::duongGiamAmTang(PhanSo a, PhanSo b)
{
    if (a.xetdau() > 0 && b.xetdau() > 0)
        return a.sosanh(b) > 0;
    else if (a.xetdau() < 0 && b.xetdau() < 0)
        return a.sosanh(b) < 0;
    return true;
}

void MangPhanSo::swap(PhanSo& a, PhanSo& b)
{
    PhanSo temp = a;
    a = b;
    b = temp;
}

void MangPhanSo::sapxep(bool (MangPhanSo::*dieukien)(PhanSo, PhanSo))
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!(this->*dieukien)(this->mang[i], this->mang[j]))
                swap(this->mang[i], this->mang[j]);
        }
    }
}