#include "Diem.h"
#include <iostream>
#include <math.h>

using namespace std;

void Diem::nhap()
{
    cout << "Nhap toa do diem x, y : ";
    cin >> this->m_x >> this->m_y;
}

void Diem::xuat() { cout << "(" << this->m_x << "," << this->m_y << ") "; }

float Diem::khoangcach(Diem p)
{
    float temp_x = this->m_x - p.m_x;
    float temp_y = this->m_y - p.m_y;
    return sqrt(temp_x * temp_x + temp_y * temp_y);
}
