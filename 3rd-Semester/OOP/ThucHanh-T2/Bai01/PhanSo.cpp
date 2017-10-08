#include "PhanSo.h"
#include <iostream>

using namespace std;

PhanSo::PhanSo()
{
	this->m_tu = 0;
	this->m_mau = 1;
}

PhanSo::PhanSo(int tu, int mau)
{
	int d = mau > 0 ? 1 : -1;
	this->m_tu = tu*d;
	this->m_mau = mau*d;
}

PhanSo::PhanSo(int tu)
{
	this->m_tu = tu;
	this->m_mau = 1;
}

PhanSo::PhanSo(const PhanSo &ps)
{
	this->m_mau = ps.m_mau;
	this->m_tu = ps.m_tu;
}

void PhanSo::Xuat()
{
	cout << this->m_tu << "/" << this->m_mau << endl;
}

PhanSo PhanSo::Cong(PhanSo ps)
{
	PhanSo tong;
	tong.m_tu = this->m_tu*ps.m_mau + this->m_mau*ps.m_tu;
	tong.m_mau = this->m_mau*ps.m_mau;
	return tong;
}

PhanSo::~PhanSo(){}