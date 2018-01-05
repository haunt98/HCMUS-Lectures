#include "phanso.h"
#include <iostream>
#define MAX 2 // gioi han phan so duoc tao ra
using namespace std;

PhanSo::PhanSo()
{
	this->m_tu = 0;
	this->m_mau = 1;
}

PhanSo::PhanSo(int tu, int mau)
{
	this->m_tu = tu;
	this->m_mau = mau;
}

PhanSo::PhanSo(const PhanSo &ps)
{
	this->m_tu = ps.m_tu;
	this->m_mau = ps.m_mau;
}

PhanSo *PhanSo::tao(int tu, int mau)
{
	if (PhanSo::soluong < MAX) {
		cout << ++PhanSo::soluong << " New bae" << endl;
		return new PhanSo(tu, mau);
	}
	cout << "No more bae" << endl;
	return NULL;
}

void PhanSo::xuat()
{
	cout << this->m_tu << "/" << this->m_mau << endl;
}

PhanSo::~PhanSo()
{
	cout << "Garbage delete" << endl;
}

int PhanSo::soluong = 0;

int PhanSo::laySoluong()
{
	return PhanSo::soluong;
}
