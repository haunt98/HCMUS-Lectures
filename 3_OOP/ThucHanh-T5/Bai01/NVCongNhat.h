#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H

#include "NhanVien.h"

class NVCongNhat : public NhanVien
{
      private:
	int m_soNgay;

      public:
	NVCongNhat() : NhanVien(), m_soNgay(0)
	{
	}
	NVCongNhat(const char *maNhanVien, const char *hoTen, Date ngaySinh,
		   const char *diaChi, int soNgay)
	    : NhanVien(maNhanVien, hoTen, ngaySinh, diaChi), m_soNgay(soNgay)
	{
	}
	NVCongNhat(const NVCongNhat &nvcn)
	    : NhanVien(nvcn), m_soNgay(nvcn.m_soNgay)
	{
	}
	NVCongNhat(const char *maNhanVien) : NhanVien(maNhanVien), m_soNgay(0)
	{
	}
	NVCongNhat(const char *hoTen, Date ngaySinh)
	    : NhanVien(hoTen, ngaySinh), m_soNgay(0)
	{
	}

	int tinhLuong();
	void nhap();
	void xuat();
};

#endif