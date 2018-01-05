#include "DonThuc.h"

DonThuc::DonThuc()
{
	m_heso = 0;
	m_mu = 0;
}

DonThuc::DonThuc(double heso, int mu)
{
	m_heso = heso;
	m_mu = mu;
}

// so hoc
DonThuc DonThuc::operator+(const DonThuc &dt)
{
	if (m_mu != dt.m_mu) {
		cout << "Error: khong cung so mu" << endl;
	}
	DonThuc tong;
	tong.m_heso = m_heso + dt.m_heso;
	tong.m_mu = m_mu;
	return tong;
}

DonThuc DonThuc::operator*(const DonThuc &dt)
{
	DonThuc tich;
	tich.m_heso = m_heso * dt.m_heso;
	tich.m_mu = m_mu + dt.m_mu;
	return tich;
}

// so sanh
bool DonThuc::operator>(const DonThuc &dt)
{
	// tra ve true neu co so mu lon hon
	return m_mu > dt.m_mu;
}

bool DonThuc::operator<(const DonThuc &dt)
{
	// tra ve true neu co so mu be hon
	return m_mu < dt.m_mu;
}

bool DonThuc::operator==(const DonThuc &dt)
{
	return m_heso == dt.m_heso && m_mu == dt.m_mu;
}

bool DonThuc::operator>=(const DonThuc &dt)
{
	return !(*this < dt);
}

bool DonThuc::operator<=(const DonThuc &dt)
{
	return !(*this > dt);
}

bool DonThuc::operator!=(const DonThuc &dt)
{
	return !(*this == dt);
}

// gan
DonThuc &DonThuc::operator=(const DonThuc &dt)
{
	m_heso = dt.m_heso;
	m_mu = dt.m_mu;
	return *this;
}

DonThuc &DonThuc::operator+=(const DonThuc &dt)
{
	*this = *this + dt;
	return *this;
}

DonThuc &DonThuc::operator*=(const DonThuc &dt)
{
	*this = *this * dt;
	return *this;
}

// mot ngoi
DonThuc &DonThuc::operator++()
{
	m_mu++;
	return *this;
}

DonThuc DonThuc::operator++(int)
{
	DonThuc temp = *this;
	++(*this);
	return temp;
}

DonThuc &DonThuc::operator--()
{
	m_mu--;
	return *this;
}

DonThuc DonThuc::operator--(int)
{
	DonThuc temp = *this;
	--(*this);
	return temp;
}

DonThuc DonThuc::operator!()
{
	DonThuc daoham;
	daoham.m_heso = m_heso * m_mu;
	daoham.m_mu = m_mu - 1;
	return daoham;
}

// nhap xuat
istream &operator>>(istream &in, DonThuc &dt)
{
	in >> dt.m_heso >> dt.m_mu;
	return in;
}

ostream &operator<<(ostream &out, const DonThuc &dt)
{
	out << dt.m_heso << "x^" << dt.m_mu;
	return out;
}
