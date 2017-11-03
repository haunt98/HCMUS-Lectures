#include "hocsinh.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void HocSinh::xuat()
{
    cout << this->m_ten << " " << this->m_van << " " << this->m_toan << endl;
}

HocSinh::HocSinh(char *ten, double van, double toan)
{
    this->m_ten = strdup(ten);
    this->m_van = van;
    this->m_toan = toan;
}

HocSinh::HocSinh(char *ten)
{
    this->m_ten = strdup(ten);
    this->m_van = 0;
    this->m_toan = 0;
}

HocSinh::~HocSinh() { free(this->m_ten); }
