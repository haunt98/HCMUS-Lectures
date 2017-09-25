#include "TamGiac.h"
#include "Diem.h"
#include <iostream>
#include <math.h>

#define EPSILON 0.00001

using namespace std;

void TamGiac::nhap()
{
    cout << "Nhap tam giac : " << endl;
    this->m_diem = new Diem[3];
    for (int i = 0; i < 3; i++)
    {
        this->m_diem[i].nhap();
    }
}

void TamGiac::xuat()
{
    cout << "Tam giac : ";
    for (int i = 0; i < 3; i++)
    {
        this->m_diem[i].xuat();
    }
    cout << endl;
}

void TamGiac::xoa() { delete[] this->m_diem; }

double TamGiac::chuvi()
{
    float sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += this->m_diem[i % 3].khoangcach(this->m_diem[(i + 1) % 3]);
    }
    return sum;
}

double TamGiac::dientich()
{
    double S = this->chuvi() / 2;
    for (int i = 0; i < 3; i++)
    {
        S *= (this->chuvi() / 2 -
              this->m_diem[i % 3].khoangcach(this->m_diem[(i + 1) % 3]));
    }
    return sqrt(S);
}

bool TamGiac::laTamGiac()
{
    for (int i = 0; i < 3; i++)
    {
        if (this->m_diem[i % 3].khoangcach(this->m_diem[(i + 1) % 3]) +
                this->m_diem[(i + 1) % 3].khoangcach(
                    this->m_diem[(i + 2) % 3]) <=
            this->m_diem[(i + 2) % 3].khoangcach(this->m_diem[i % 3]))
            return false;
    }
    return true;
}

bool isEqual(const double &a, const double &b) // so sanh bang hai so thuc
{
    if (abs(a - b) <= EPSILON)
        return true;
    return false;
}

bool TamGiac::laTamGiacDeu()
{
    if (!this->laTamGiac())
        return false;
    for (int i = 0; i < 3; i++)
    {
        if (!isEqual(this->m_diem[i % 3].khoangcach(this->m_diem[(i + 1) % 3]),
                     this->m_diem[(i + 1) % 3].khoangcach(
                         this->m_diem[(i + 2) % 3])))
            return false;
    }
    return true;
}

bool TamGiac::laTamGiacCan()
{
    if (!this->laTamGiac())
        return false;
    for (int i = 0; i < 3; i++)
    {
        if (isEqual(this->m_diem[i % 3].khoangcach(this->m_diem[(i + 1) % 3]),
                    this->m_diem[(i + 1) % 3].khoangcach(
                        this->m_diem[(i + 2) % 3])))
            return true;
    }
    return false;
}

bool TamGiac::laTamGiacVuong()
{
    if (!this->laTamGiac())
        return false;
    float canh[3];
    for (int i = 0; i < 3; i++)
    {
        canh[i] = this->m_diem[i % 3].khoangcach(this->m_diem[(i + 1) % 3]);
    }
    for (int i = 0; i < 3; i++)
    {
        if (isEqual(canh[i % 3] * canh[i % 3] +
                        canh[(i + 1) % 3] * canh[(i + 1) % 3],
                    canh[(i + 2) % 3] * canh[(i + 2) % 3]))
            return true;
    }
    return false;
}

bool TamGiac::laTamGiacVuongCan()
{
    if (this->laTamGiacCan() && this->laTamGiacVuong())
        return true;
    return false;
}

void TamGiac::loai()
{
    if (!this->laTamGiac())
        cout << "Khong phai la tam giac" << endl;
    else if (this->laTamGiacVuongCan())
        cout << "Tam giac vuong can" << endl;
    else if (this->laTamGiacVuong())
        cout << "Tam giac vuong" << endl;
    else if (this->laTamGiacDeu())
        cout << "Tam giac deu" << endl;
    else if (this->laTamGiacCan())
        cout << "Tam giac can" << endl;
    else
        cout << "Tam giac thuong" << endl;
}

void TamGiac::swap(TamGiac &tg)
{
    for (int i = 0; i < 3; i++)
    {
        Diem temp = this->m_diem[i];
        this->m_diem[i] = tg.m_diem[i];
        tg.m_diem[i] = temp;
    }
}
