#include "phanso.h"

using namespace std;

void PhanSo::nhap() {
	cout << "Tu so : ";
	cin >> this->m_tu;
	do {
		cout << "Mau so : ";
		cin >> this->m_mau;
	} while (this->m_mau == 0);
}

void PhanSo::xuat() { cout << this->m_tu << "/" << this->m_mau << endl; }

int PhanSo::layTu() { return this->m_tu; }

int PhanSo::layMau() { return this->m_mau; }

void PhanSo::ganTu(int tu) { this->m_tu = tu; }

void PhanSo::ganMau(int mau) { this->m_mau = mau; }

PhanSo PhanSo::nghichdao(bool &flagNgichDao) {
	if (this->m_tu == 0)
		flagNgichDao = false;
	else
		flagNgichDao = true;
	PhanSo p;
	p.m_tu = this->m_tu;
	p.m_mau = this->m_mau;
	return p;
}

int gcd(int a, int b){
	a = abs(a); b = abs(b);
	while (a%b != 0 && b%a != 0)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return a < b ? a : b;
}

PhanSo PhanSo::rutgon(){
	PhanSo p;
	int i = this->m_tu*this->m_mau > 0 ? 1 : -1;
	int d = gcd(this->m_tu, this->m_mau);
	p.m_tu = abs(this->m_tu)*i / d;
	p.m_mau = abs(this->m_mau) / d;
	return p;
}

PhanSo PhanSo::cong(PhanSo p)
{
	PhanSo tong;
	tong.m_tu = this->m_tu*p.m_mau + this->m_mau*p.m_tu;
	tong.m_mau = this->m_mau*p.m_mau;
	return tong;
}

PhanSo PhanSo::nhan(PhanSo p)
{
	PhanSo tich;
	tich.m_tu = this->m_tu*p.m_tu;
	tich.m_mau = this->m_mau*p.m_mau;
	return tich;
}

int PhanSo::sosanh(PhanSo p)
{
	PhanSo hieu;
	hieu.m_tu = this->m_tu*p.m_mau - this->m_mau*p.m_tu;
	hieu.m_mau = this->m_mau*p.m_mau;
	if (hieu.m_tu == 0)
		return 0;
	return hieu.m_tu*hieu.m_mau > 0 ? 1 : -1;
}