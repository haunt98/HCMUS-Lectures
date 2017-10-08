#include "Diem.h"
#include <iostream>

using namespace std;

Diem::Diem()
{
    this->m_x = 0;
    this->m_y = 0;
}

Diem::Diem(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

void Diem::Xuat() { cout << "(" << this->m_x << "," << this->m_y << ") "; }

Diem::~Diem() {}