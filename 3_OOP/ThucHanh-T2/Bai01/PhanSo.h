#ifndef PHANSO_H
#define PHANSO_H

class PhanSo
{
      private:
	int m_tu, m_mau;

      public:
	PhanSo();
	PhanSo(int tu, int mau);
	PhanSo(int tu);
	PhanSo(const PhanSo &);
	void Xuat();
	PhanSo Cong(PhanSo);
	~PhanSo();
};

#endif