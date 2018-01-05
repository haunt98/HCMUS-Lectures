#include "SoCan7.h"
#include <iostream>

using namespace std;

void SoCan7::nhap()
{
	cout << "Nhap a: ";
	cin >> m_a;
	cout << "Nhap b: ";
	cin >> m_b;
}

void SoCan7::xuat()
{
	cout << m_a << " + " << m_b << " * can7" << endl;
}

SoCan7 SoCan7::operator+(const SoCan7 &s)
{
	SoCan7 tong;
	tong.m_a = m_a + s.m_a;
	tong.m_b = m_b + s.m_b;
	return tong;
}

SoCan7 SoCan7::operator-(const SoCan7 &s)
{
	SoCan7 hieu;
	hieu.m_a = m_a - s.m_a;
	hieu.m_b = m_b - s.m_b;
	return hieu;
}

SoCan7 SoCan7::operator*(const SoCan7 &s)
{
	SoCan7 tich;
	tich.m_a = m_a * s.m_a + m_b * s.m_b * 7;
	tich.m_b = m_a * s.m_b + m_b * s.m_a;
	return tich;
}

SoCan7 SoCan7::doiDau()
{
	SoCan7 temp;
	temp.m_a = -m_a;
	temp.m_b = -m_b;
	return temp;
}
