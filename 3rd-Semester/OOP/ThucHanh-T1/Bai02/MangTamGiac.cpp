#include "MangTamGiac.h"
#include "Diem.h"
#include "TamGiac.h"
#include <iostream>

using namespace std;

void MangTamGiac::nhap()
{
    cout << "Nhap kich thuoc mang tam giac : ";
    cin >> this->m_size;
    this->m_arr = new TamGiac[this->m_size];
    for (int i = 0; i < this->m_size; i++)
    {
        this->m_arr[i].nhap();
    }
}

void MangTamGiac::xuat()
{
    for (int i = 0; i < this->m_size; i++)
    {
        this->m_arr[i].xuat();
    }
}

void MangTamGiac::xoa()
{
    for (int i = 0; i < this->m_size; i++)
    {
        this->m_arr[i].xoa();
    }
    delete[] this->m_arr;
}

void MangTamGiac::lietke(bool (TamGiac::*dieukien)())
{
    for (int i = 0; i < this->m_size; i++)
    {
        if ((this->m_arr[i].*dieukien)())
        {
            this->m_arr[i].xuat();
        }
    }
}

bool MangTamGiac::nhohon(double a, double b) { return a <= b; }

bool MangTamGiac::lonhon(double a, double b) { return a >= b; }

TamGiac MangTamGiac::tim(double (TamGiac::*giatri)(),
                         bool (MangTamGiac::*thutu)(double, double))
{
    int tim_index = 0;
    for (int i = 1; i < this->m_size; i++)
    {
        if (!(this->*thutu)((this->m_arr[tim_index].*giatri)(),
                            (this->m_arr[i].*giatri)()))
        {
            tim_index = i;
        }
    }
    return this->m_arr[tim_index];
}

void MangTamGiac::sapxep(double (TamGiac::*giatri)(),
                         bool (MangTamGiac::*thutu)(double, double))
{
    for (int i = 0; i < this->m_size; i++)
    {
        for (int j = i + 1; j < this->m_size; j++)
        {
            if (!(this->*thutu)((this->m_arr[i].*giatri)(),
                                (this->m_arr[j].*giatri)()))
            {
                this->m_arr[i].swap(this->m_arr[j]);
            }
        }
    }
}
