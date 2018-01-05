#include "NVSanXuat.h"

int NVSanXuat::tinhLuong()
{
	return m_sanPham * NhanVien::GiaSP;
}

void NVSanXuat::nhap()
{
	NhanVien::nhap();
	cout << "Nhap so san pham: ";
	cin >> m_sanPham;
	getchar();
}

void NVSanXuat::xuat()
{
	NhanVien::xuat();
	cout << "So san pham: " << m_sanPham << endl;
	cout << "Luong: " << tinhLuong() << endl;
}
