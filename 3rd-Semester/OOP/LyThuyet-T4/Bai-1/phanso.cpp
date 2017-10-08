#include "phanso.h"

PhanSo::PhanSo(int tu, int mau)
{
    m_tu = tu;
    m_mau = mau != 0 ? mau : 1;
}

PhanSo::PhanSo(const PhanSo &ps)
{
    m_tu = ps.m_tu;
    m_mau = ps.m_mau;
}

// So hoc
PhanSo PhanSo::operator+(const PhanSo &ps)
{
    PhanSo tong;
    tong.m_tu = m_tu * ps.m_mau + m_mau * ps.m_tu;
    tong.m_mau = m_mau * ps.m_mau;
    return tong;
}

PhanSo PhanSo::operator*(const PhanSo &ps)
{
    PhanSo tich;
    tich.m_tu = m_tu * ps.m_tu;
    tich.m_mau = m_mau * ps.m_mau;
    return tich;
}

// So sanh
bool PhanSo::operator>(const PhanSo &ps)
{
    // tu, mau cua hieu
    int tu = m_tu * ps.m_mau - m_mau * ps.m_tu;
    int mau = m_mau * ps.m_mau;
    if (tu * mau > 0)
        return true;
    return false;
}

bool PhanSo::operator<(const PhanSo &ps)
{
    // tu, mau cua hieu
    int tu = m_tu * ps.m_mau - m_mau * ps.m_tu;
    int mau = m_mau * ps.m_mau;
    if (tu * mau < 0)
        return true;
    return false;
}

bool PhanSo::operator==(const PhanSo &ps)
{
    return m_tu * ps.m_mau == m_mau * ps.m_tu;
}

bool PhanSo::operator>=(const PhanSo &ps) { return !((*this) < ps); }
bool PhanSo::operator<=(const PhanSo &ps) { return !((*this) > ps); }
bool PhanSo::operator!=(const PhanSo &ps) { return !((*this) == ps); }

// gan
PhanSo &PhanSo::operator=(const PhanSo &ps)
{
    m_tu = ps.m_tu;
    m_mau = ps.m_mau;
    return (*this);
}

PhanSo &PhanSo::operator+=(const PhanSo &ps)
{
    (*this) = (*this) + ps;
    return (*this);
}

PhanSo &PhanSo::operator*=(const PhanSo &ps)
{
    (*this) = (*this) * ps;
    return (*this);
}

// Mot ngoi
PhanSo &PhanSo::operator++()
{
    PhanSo dvi(1, 1);
    (*this) += dvi;
    return (*this);
}

PhanSo PhanSo::operator++(int)
{
    PhanSo temp(*this);
    ++(*this);
    return temp;
}

PhanSo &PhanSo::operator--()
{
    PhanSo dvi(-1, 1);
    (*this) += dvi;
    return (*this);
}

PhanSo PhanSo::operator--(int)
{
    PhanSo temp(*this);
    --(*this);
    return temp;
}

// Ep kieu
PhanSo::operator float() { return (float)m_tu / m_mau; }
PhanSo::operator int() { return m_tu / m_mau; }

// Nhap xuat
istream &operator>>(istream &in, PhanSo &ps)
{
    in >> ps.m_tu;
    do
    {
        in >> ps.m_mau;
    } while (ps.m_mau == 0);
    return in;
}

ostream &operator<<(ostream &out, const PhanSo &ps)
{
    out << ps.m_tu << "/" << ps.m_mau;
    return out;
}
