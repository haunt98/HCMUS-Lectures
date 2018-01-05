#include "Fraction.h"

Fraction::Fraction(int tu, int mau)
{
	m_tu = tu;
	m_mau = mau != 0 ? mau : 1;
}

Fraction::Fraction(const Fraction &ps)
{
	m_tu = ps.m_tu;
	m_mau = ps.m_mau != 0 ? ps.m_mau : 1;
}

// so hoc
Fraction &Fraction::operator=(const Fraction &ps)
{
	m_tu = ps.m_tu;
	m_mau = ps.m_mau != 0 ? ps.m_mau : 1;
	return (*this);
}

Fraction Fraction::operator+(const Fraction &ps) const
{
	Fraction tong;
	tong.m_tu = m_tu * ps.m_mau + m_mau * ps.m_tu;
	tong.m_mau = m_mau * ps.m_mau;
	return tong;
}

Fraction Fraction::operator-(const Fraction &ps) const
{
	Fraction hieu;
	hieu.m_tu = m_tu * ps.m_mau - m_mau * ps.m_tu;
	hieu.m_mau = m_mau * ps.m_mau;
	return hieu;
}

Fraction Fraction::operator*(const Fraction &ps) const
{
	Fraction tich;
	tich.m_tu = m_tu * ps.m_tu;
	tich.m_mau = m_mau * ps.m_mau;
	return tich;
}

Fraction Fraction::operator/(const Fraction &ps) const
{
	if (ps.m_tu == 0)
		cout << "Loi chia cho 0" << endl;
	Fraction thuong;
	thuong.m_tu = m_tu * ps.m_mau;
	thuong.m_mau = m_mau * ps.m_tu;
	return thuong;
}

Fraction &Fraction::operator+=(const Fraction &ps)
{
	(*this) = (*this) + ps;
	return (*this);
}

Fraction &Fraction::operator-=(const Fraction &ps)
{
	(*this) = (*this) - ps;
	return (*this);
}

Fraction &Fraction::operator*=(const Fraction &ps)
{
	(*this) = (*this) * ps;
	return (*this);
}

Fraction &Fraction::operator/=(const Fraction &ps)
{
	(*this) = (*this) / ps;
	return (*this);
}

// tien to hau to
Fraction &Fraction::operator++()
{
	Fraction dvi(1, 1);
	(*this) += dvi;
	return (*this);
}

Fraction Fraction::operator++(int)
{
	Fraction temp = (*this);
	++(*this);
	return temp;
}

Fraction &Fraction::operator--()
{
	Fraction dvi(1, 1);
	(*this) -= dvi;
	return (*this);
}

Fraction Fraction::operator--(int)
{
	Fraction temp = (*this);
	--(*this);
	return temp;
}

// so sanh
bool Fraction::operator==(const Fraction &ps)
{
	return m_tu * ps.m_mau == m_mau * ps.m_tu;
}

bool Fraction::operator!=(const Fraction &ps)
{
	return !((*this) == ps);
}

bool Fraction::operator>=(const Fraction &ps)
{
	Fraction hieu = (*this) - ps;
	if (hieu.m_tu * hieu.m_mau < 0)
		return false;
	return true;
}

bool Fraction::operator>(const Fraction &ps)
{
	Fraction hieu = (*this) - ps;
	if (hieu.m_tu * hieu.m_mau > 0)
		return true;
	return false;
}

bool Fraction::operator<=(const Fraction &ps)
{
	Fraction hieu = (*this) - ps;
	if (hieu.m_tu * hieu.m_mau > 0)
		return false;
	return true;
}

bool Fraction::operator<(const Fraction &ps)
{
	Fraction hieu = (*this) - ps;
	if (hieu.m_tu * hieu.m_mau < 0)
		return true;
	return false;
}

// qua tai
Fraction operator+(const Fraction &ps, const int &m)
{
	Fraction temp(m, 1);
	return ps + temp;
}

Fraction operator+(const int &m, const Fraction &ps)
{
	return ps + m;
}

Fraction operator*(const Fraction &ps, const int &m)
{
	Fraction temp(m, 1);
	return ps * temp;
}

Fraction operator*(const int &m, const Fraction &ps)
{
	return ps * m;
}

Fraction operator-(const Fraction &ps, const int &m)
{
	Fraction temp(m, 1);
	return ps - temp;
}

// nhap xuat
istream &operator>>(istream &in, Fraction &ps)
{
	in >> ps.m_tu;
	do {
		in >> ps.m_mau;
	} while (ps.m_mau == 0);
	return in;
}

ostream &operator<<(ostream &out, const Fraction &ps)
{
	out << ps.m_tu << "/" << ps.m_mau;
	return out;
}

// ep kieu
Fraction::operator float()
{
	return (float)m_tu / m_mau;
}