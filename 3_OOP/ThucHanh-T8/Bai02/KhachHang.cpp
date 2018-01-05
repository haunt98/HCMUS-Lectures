#include "KhachHang.h"
#include <iostream>

using namespace std;

KhachHang::KhachHang() : m_Ten(""), m_CMND(""), m_DiaChi(""), m_cuoc(NULL)
{
}

KhachHang::KhachHang(string Ten, string CMND, string DiaChi, GoiCuocBasic *cuoc)
    : m_Ten(Ten), m_CMND(CMND), m_DiaChi(DiaChi)
{
	m_cuoc = cuoc->clone();
	*m_cuoc = *cuoc;
}

KhachHang::KhachHang(const KhachHang &guest)
    : KhachHang(guest.m_Ten, guest.m_CMND, guest.m_DiaChi, guest.m_cuoc)
{
}

KhachHang::~KhachHang()
{
	if (m_cuoc) {
		delete m_cuoc;
	}
}

KhachHang &KhachHang::operator=(const KhachHang &guest)
{
	m_Ten = guest.m_Ten;
	m_CMND = guest.m_CMND;
	m_DiaChi = guest.m_DiaChi;
	if (m_cuoc) {
		delete m_cuoc;
	}
	m_cuoc = guest.m_cuoc->clone();
	return *this;
}

void KhachHang::DangKy(GoiCuocBasic *cuoc)
{
	if (m_cuoc) {
		cout << "Khach hang da dang ki cuoc, khong dang ki lai\n"
		     << endl;
		return;
	}
	m_cuoc = cuoc->clone();
}

float KhachHang::TienCuoc()
{
	return m_cuoc->cuocTong();
}