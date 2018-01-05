#define _CRT_SECURE_NO_WARNINGS
#include "NhanVien.h"
#include <string.h>

#define MAX 1000

// constructor
NhanVien::NhanVien()
{
	m_maNhanVien = new char[1];
	m_maNhanVien[0] = '\0';

	m_hoTen = new char[1];
	m_hoTen[0] = '\0';

	m_ngaySinh = Date(1, 1, 1998);

	m_diaChi = new char[1];
	m_diaChi[0] = '\0';
}

NhanVien::NhanVien(const char *maNhanVien, const char *hoTen, Date ngaySinh,
		   const char *diaChi)
{
	m_maNhanVien = new char[strlen(maNhanVien) + 1];
	strcpy(m_maNhanVien, maNhanVien);

	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);

	m_ngaySinh = ngaySinh;

	m_diaChi = new char[strlen(diaChi) + 1];
	strcpy(m_diaChi, diaChi);
}

NhanVien::NhanVien(const NhanVien &nv)
{
	m_maNhanVien = new char[strlen(nv.m_maNhanVien) + 1];
	strcpy(m_maNhanVien, nv.m_maNhanVien);

	m_hoTen = new char[strlen(nv.m_hoTen) + 1];
	strcpy(m_hoTen, nv.m_hoTen);

	m_ngaySinh = nv.m_ngaySinh;

	m_diaChi = new char[strlen(nv.m_diaChi) + 1];
	strcpy(m_diaChi, nv.m_diaChi);
}

NhanVien::NhanVien(const char *maNhanVien)
{
	m_maNhanVien = new char[strlen(maNhanVien) + 1];
	strcpy(m_maNhanVien, maNhanVien);

	m_hoTen = new char[1];
	m_hoTen[0] = '\0';

	m_ngaySinh = Date(1, 1, 1998);

	m_diaChi = new char[1];
	m_diaChi[0] = '\0';
}

NhanVien::NhanVien(const char *hoTen, Date ngaySinh)
{
	m_maNhanVien = new char[1];
	m_maNhanVien[0] = '\0';

	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);

	m_ngaySinh = ngaySinh;

	m_diaChi = new char[1];
	m_diaChi[0] = '\0';
}

NhanVien &NhanVien::operator=(const NhanVien &nv)
{
	delete[] m_maNhanVien;
	m_maNhanVien = new char[strlen(nv.m_maNhanVien) + 1];
	strcpy(m_maNhanVien, nv.m_maNhanVien);

	delete[] m_hoTen;
	m_hoTen = new char[strlen(nv.m_hoTen) + 1];
	strcpy(m_hoTen, nv.m_hoTen);

	m_ngaySinh = nv.m_ngaySinh;

	delete[] m_diaChi;
	m_diaChi = new char[strlen(nv.m_diaChi) + 1];
	strcpy(m_diaChi, nv.m_diaChi);
	return *this;
}

NhanVien::~NhanVien()
{
	delete[] m_maNhanVien;
	delete[] m_hoTen;
	delete[] m_diaChi;
}

void NhanVien::nhap()
{
	cout << "Nhap ma nhan vien: ";
	char maNhanVien[MAX];
	gets(maNhanVien);
	delete[] m_maNhanVien;
	m_maNhanVien = new char[strlen(maNhanVien) + 1];
	strcpy(m_maNhanVien, maNhanVien);

	cout << "Nhap ho ten: ";
	char hoTen[MAX];
	gets(hoTen);
	delete[] m_hoTen;
	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);

	cout << "Nhap ngay sinh: ";
	cin >> m_ngaySinh;
	getchar();

	cout << "Nhap dia chi: ";
	char diaChi[MAX];
	gets(diaChi);
	delete[] m_diaChi;
	m_diaChi = new char[strlen(diaChi) + 1];
	strcpy(m_diaChi, diaChi);
}

void NhanVien::xuat()
{
	cout << "Ma nhan vien: " << m_maNhanVien << endl;
	cout << "Ho ten: " << m_hoTen << endl;
	cout << "Ngay sinh: " << m_ngaySinh << endl;
	cout << "Dia chi: " << m_diaChi << endl;
}