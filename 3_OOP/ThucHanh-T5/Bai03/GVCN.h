#ifndef GVCN_H
#define GVCN_H

#include "GiaoVien.h"

class GVCN : public GiaoVien
{
      private:
	char *m_lopChuNhiem;

      public:
	GVCN();
	GVCN(const char *maGV, const char *hoTen, const float &heSoLuong,
	     const float &luongCoBan, const int &soNgayNghi,
	     const char *lopChuNhiem);
	GVCN(const GVCN &gvcn);
	GVCN(const char *maGV);
	GVCN(const char *maGV, const char *hoTen);
	GVCN &operator=(const GVCN &gvcn);
	~GVCN();

	void nhap();
	void xuat();
	float tinhLuong();
};

#endif