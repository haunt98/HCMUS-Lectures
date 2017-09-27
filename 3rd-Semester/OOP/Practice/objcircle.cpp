#include <iostream>
using namespace std;

// Phuong thuc khoi tao cho class

class PhanSo {
private:
    int m_tu, m_mau;
    int* sth;

public:
    PhanSo();
    PhanSo(const PhanSo& p);
    PhanSo(int tu, int mau);
    void xuat();
    ~PhanSo();
};

PhanSo::PhanSo()
{
    this->m_tu = 0;
    this->m_mau = 1;
}

PhanSo::PhanSo(const PhanSo& p)
{
    this->m_tu = p.m_tu;
    this->m_mau = p.m_mau;
}

PhanSo::PhanSo(int tu, int mau)
{
    this->m_tu = tu;
    if (mau == 0)
        this->m_mau = 1;
    else
        this->m_mau = mau;
}

void PhanSo::xuat()
{
    cout << this->m_tu << "/" << this->m_mau << endl;
}

PhanSo::~PhanSo()
{
    delete[] new;
}

int main()
{
    PhanSo p1(1, 2);
    p1.xuat();
    return 0;
}
