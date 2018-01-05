#include "PhanSo.h"
#include <iostream>

using namespace std;

// Class Phan So
void PhanSo::nhap()
{
	cout << "Nhap tu so : ";
	cin >> this->m_tu;
	do {
		cout << "Nhap mau so : ";
		cin >> this->m_mau;
	} while (this->m_mau == 0);
}

void PhanSo::xuat()
{
	cout << this->m_tu << "/" << this->m_mau << endl;
}

PhanSo PhanSo::cong(PhanSo p)
{
	PhanSo tong;
	tong.m_tu = this->m_tu * p.m_mau + this->m_mau * p.m_tu;
	tong.m_mau = this->m_mau * p.m_mau;
	return tong;
}

PhanSo PhanSo::tru(PhanSo p)
{
	PhanSo p_doi = p;
	p_doi.m_tu = -p.m_tu; // p_doi la phan so doi cua p
	return this->cong(p_doi);
}

PhanSo PhanSo::nhan(PhanSo p)
{
	PhanSo tich;
	tich.m_tu = this->m_tu * p.m_tu;
	tich.m_mau = this->m_mau * p.m_mau;
	return tich;
}

PhanSo PhanSo::chia(PhanSo p, bool &flagChia)
{
	if (p.m_tu == 0)
		flagChia = false;
	else
		flagChia = true;
	PhanSo p_nghich; // nghich dao cua p
	p_nghich.m_tu = p.m_mau;
	p_nghich.m_mau = p.m_tu;
	return this->nhan(p_nghich);
}

int PhanSo::gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return 1;
	a = a > 0 ? a : -a;
	b = b > 0 ? b : -b;
	while (a % b != 0 && b % a != 0) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a < b ? a : b;
}

PhanSo PhanSo::rutgon()
{
	int ucln = gcd(this->m_tu, this->m_mau);
	int i = this->m_tu * this->m_mau > 0 ? 1 : -1; // dau cua tu
	PhanSo temp;
	temp.m_tu = abs(this->m_tu) / ucln * i;
	temp.m_mau = abs(this->m_mau) / ucln;
	return temp;
}

int PhanSo::sosanh(PhanSo p)
{
	PhanSo hieu = this->tru(p);
	if (hieu.m_tu == 0)
		return 0;
	else if (hieu.m_tu * hieu.m_mau < 0)
		return -1;
	return 1;
}

int PhanSo::xetdau()
{
	if (this->m_tu == 0)
		return 0;
	if (this->m_tu * this->m_mau < 0)
		return -1;
	return 1;
}

void PhanSo::gan(int tu, int mau)
{
	this->m_tu = tu;
	this->m_mau = mau;
}
