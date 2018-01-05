#ifndef MANG_H
#define MANG_H

class MangNguyen
{
      private:
	int *m_arr;
	int m_size;

      public:
	void nhap();
	void xuat();
	int layKichThuoc();
	int layPhanTu(int i);
	void ganPhanTu(int i, int value);
	int timPhanTu(int value); // tra ve vi tri
	void sapxep(bool (*dieukien)(int, int));
	void xoa();
};

bool dkTang(int, int);
bool dkGiam(int, int);

#endif
