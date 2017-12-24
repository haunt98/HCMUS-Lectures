#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

class TamGiac
{
private:
    Diem m_dinh[3];

public:
    TamGiac();
    TamGiac(Diem A, Diem B, Diem C);
    TamGiac(int A_x, int A_y, int B_x, int B_y, int C_x, int C_y);
    TamGiac(const TamGiac &tg);
    void Xuat();
    ~TamGiac();
};

#endif