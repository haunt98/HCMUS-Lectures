#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

class PhanSo
{
      private:
	int m_tu, m_mau;

      public:
	void nhap();
	void xuat();
	int layTu();
	int layMau();
	void ganTu(int tu);
	void ganMau(int mau);
	PhanSo nghichdao(bool &flagNgichDao); // flag true neu nghich dao duoc
	PhanSo rutgon();
	PhanSo cong(PhanSo p);
	PhanSo nhan(PhanSo p);
	int sosanh(PhanSo p); // 0 bang nhau 1 lon hon -1 nho hon
};

#endif
