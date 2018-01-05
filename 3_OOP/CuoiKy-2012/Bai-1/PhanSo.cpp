#include "PhanSo.h"

PhanSo::PhanSo()
{
	m_tu = 0;
	m_mau = 1;
}

PhanSo::PhanSo(int tu, int mau)
{
	m_tu = tu;
	if (mau == 0) {
		cout << "Mau = 0, tra ve mau = 1" << endl;
		m_mau = 1;
	} else {
		m_mau = mau;
	}
}

PhanSo::PhanSo(int n)
{
	m_tu = n;
	m_mau = 1;
}

// Operator
PhanSo &PhanSo::operator=(const PhanSo ps)
{
	m_tu = ps.m_tu;
	m_mau = ps.m_mau;
	return *this;
}

PhanSo PhanSo::operator+(const PhanSo ps)
{
	int tu_moi = m_tu * ps.m_mau + m_mau * ps.m_tu;
	int mau_moi = m_mau * ps.m_mau;
	return PhanSo(tu_moi, mau_moi);
}

PhanSo &PhanSo::operator+=(const PhanSo ps)
{
	*this = *this + ps;
	return *this;
}

PhanSo &PhanSo::operator++()
{
	*this = *this + PhanSo(1);
	return *this;
}

ostream &operator<<(ostream &out, const PhanSo ps)
{
	out << ps.m_tu << "/" << ps.m_mau;
	return out;
}

PhanSo::operator int()
{
	return m_tu / m_mau;
}
