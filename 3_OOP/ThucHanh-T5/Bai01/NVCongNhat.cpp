#include "NVCongNhat.h"

int NVCongNhat::tinhLuong()
{
	return m_soNgay * NhanVien::LuongNgay;
}

void NVCongNhat::nhap()
{
	NhanVien::nhap();
	cout << "Nhap so ngay: ";
	cin >> m_soNgay;
	getchar();
}

void NVCongNhat::xuat()
{
	NhanVien::xuat();
	cout << "So ngay: " << m_soNgay << endl;
	cout << "Luong: " << tinhLuong() << endl;
}
