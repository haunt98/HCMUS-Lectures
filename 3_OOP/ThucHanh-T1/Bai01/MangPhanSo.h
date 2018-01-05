#ifndef MANGPHANSO_H
#define MANGPHANSO_H

class PhanSo; // forward declaration

class MangPhanSo
{
      private:
	PhanSo *mang;
	int size;
	void swap(PhanSo &, PhanSo &);

      public:
	void nhap();
	void xuat();
	void xoa(); // xoa mang khoi bo nho
	PhanSo tong();
	PhanSo tich();
	PhanSo min();
	PhanSo max();
	void xuatAm(); // xuat phan so am trong mang
	int demDuong();
	bool tang(PhanSo, PhanSo);
	bool duongGiamAmTang(PhanSo, PhanSo);
	void sapxep(bool (MangPhanSo::*dieukien)(PhanSo, PhanSo));
};

#endif