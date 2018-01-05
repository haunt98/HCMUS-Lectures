#ifndef NVSANXUAT_H
#define NVSANXUAT_H

#include "NhanVien.h"

class NVSanXuat : public NhanVien
{
      private:
	int m_sanPham;

      public:
	NVSanXuat() : NhanVien(), m_sanPham(0)
	{
	}
	NVSanXuat(const char *maNhanVien, const char *hoTen, Date ngaySinh,
		  const char *diaChi, int sanPham)
	    : NhanVien(maNhanVien, hoTen, ngaySinh, diaChi), m_sanPham(sanPham)
	{
	}
	NVSanXuat(const NVSanXuat &nvsx)
	    : NhanVien(nvsx), m_sanPham(nvsx.m_sanPham)
	{
	}
	NVSanXuat(const char *maNhanVien) : NhanVien(maNhanVien), m_sanPham(0)
	{
	}
	NVSanXuat(const char *hoTen, Date ngaySinh)
	    : NhanVien(hoTen, ngaySinh), m_sanPham(0)
	{
	}

	int tinhLuong();
	void nhap();
	void xuat();
};

#endif