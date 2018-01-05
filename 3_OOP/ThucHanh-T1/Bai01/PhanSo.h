#ifndef PHANSO_H
#define PHANSO_H

class PhanSo
{
      private:
	int m_tu, m_mau;
	int gcd(int, int); // uoc chung lon nhat
      public:
	void nhap();
	void xuat();
	PhanSo cong(PhanSo p);
	PhanSo tru(PhanSo p);
	PhanSo nhan(PhanSo p);
	PhanSo chia(PhanSo p, bool &flagChia); // flagChia true neu chia duoc
	PhanSo rutgon();
	int sosanh(PhanSo p); // 0 la bang nhau, -1 be hon, 1 lon hon
	int xetdau();
	void gan(int tu, int mau);
};

#endif