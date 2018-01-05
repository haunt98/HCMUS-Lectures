#include "TaiKhoan.h"

float TaiKhoanTietKiem::napTien(float soTien)
{
	// nap tien, tinh lai, so thang tinh la tu dau
	m_thangDaGui = 0;
	TaiKhoan::napTien(soTien);
	return baoSoDu() * m_laiSuat;
}

float TaiKhoanTietKiem::rutTien(float soTien)
{
	m_thangDaGui = 0;
	TaiKhoan::rutTien(soTien);
	return baoSoDu() * m_laiSuat;
}

void TaiKhoanTietKiem::tangThangDaGui(int thang)
{
	m_thangDaGui += thang;
}
