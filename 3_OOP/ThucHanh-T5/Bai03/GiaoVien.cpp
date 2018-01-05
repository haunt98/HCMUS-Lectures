#define _CRT_SECURE_NO_WARNINGS
#include "GiaoVien.h"
#include <iostream>
#include <string.h>

#define MAX 1000

using namespace std;

GiaoVien::GiaoVien()
{
	m_maGV = new char[1];
	m_maGV[0] = '\0';

	m_hoTen = new char[1];
	m_hoTen[0] = '\0';

	m_heSoLuong = 1;
	m_luongCoBan = 100000;
	m_soNgayNghi = 0;
}

GiaoVien::GiaoVien(const char *maGV, const char *hoTen, const float &heSoLuong,
		   const float &luongCoBan, const int &soNgayNghi)
{
	m_maGV = new char[strlen(maGV) + 1];
	strcpy(m_maGV, maGV);

	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);

	m_heSoLuong = heSoLuong;
	m_luongCoBan = luongCoBan;
	m_soNgayNghi = soNgayNghi;
}

GiaoVien::GiaoVien(const GiaoVien &gv)
{
	m_maGV = new char[strlen(gv.m_maGV) + 1];
	strcpy(m_maGV, gv.m_maGV);

	m_hoTen = new char[strlen(gv.m_hoTen) + 1];
	strcpy(m_hoTen, gv.m_hoTen);

	m_heSoLuong = gv.m_heSoLuong;
	m_luongCoBan = gv.m_luongCoBan;
	m_soNgayNghi = gv.m_soNgayNghi;
}

GiaoVien::GiaoVien(const char *maGV)
{
	m_maGV = new char[strlen(maGV) + 1];
	strcpy(m_maGV, maGV);

	m_hoTen = new char[1];
	m_hoTen[0] = '\0';

	m_heSoLuong = 1;
	m_luongCoBan = 100000;
	m_soNgayNghi = 0;
}

GiaoVien::GiaoVien(const char *maGV, const char *hoTen)
{
	m_maGV = new char[strlen(maGV) + 1];
	strcpy(m_maGV, maGV);

	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);

	m_heSoLuong = 1;
	m_luongCoBan = 100000;
	m_soNgayNghi = 0;
}

GiaoVien &GiaoVien::operator=(const GiaoVien &gv)
{
	delete[] m_maGV;
	m_maGV = new char[strlen(gv.m_maGV) + 1];
	strcpy(m_maGV, gv.m_maGV);

	delete[] m_hoTen;
	m_hoTen = new char[strlen(gv.m_hoTen) + 1];
	strcpy(m_hoTen, gv.m_hoTen);

	m_heSoLuong = gv.m_heSoLuong;
	m_luongCoBan = gv.m_luongCoBan;
	m_soNgayNghi = gv.m_soNgayNghi;

	return *this;
}

GiaoVien::~GiaoVien()
{
	delete[] m_maGV;
	delete[] m_hoTen;
}

void GiaoVien::nhap()
{
	cout << "Nhap ma giao vien: ";
	char *maGV = new char[MAX + 1];
	gets(maGV);
	delete[] m_maGV;
	m_maGV = new char[strlen(maGV) + 1];
	strcpy(m_maGV, maGV);
	delete[] maGV;

	cout << "Nhap ten giao vien: ";
	char *hoTen = new char[MAX + 1];
	gets(hoTen);
	delete[] m_hoTen;
	m_hoTen = new char[strlen(hoTen) + 1];
	strcpy(m_hoTen, hoTen);
	delete[] hoTen;

	cout << "Nhap he so luong: ";
	do {
		cin >> m_heSoLuong;
	} while (m_heSoLuong <= 0);

	cout << "Nhap luong co ban: ";
	do {
		cin >> m_luongCoBan;
	} while (m_luongCoBan <= 0);

	cout << "Nhap so ngay nghi: ";
	do {
		cin >> m_soNgayNghi;
	} while (m_soNgayNghi < 0);
	getchar();
}

void GiaoVien::xuat()
{
	cout << "Ma giao vien: " << m_maGV << endl;
	cout << "Ten giao vien: " << m_hoTen << endl;
	cout << "He so luong: " << m_heSoLuong << endl;
	cout << "Luong co ban: " << m_luongCoBan << endl;
	cout << "So ngay nghi: " << m_soNgayNghi << endl;
	cout << "Luong: " << tinhLuong() << endl;
}

float GiaoVien::tinhLuong()
{
	return m_heSoLuong * m_luongCoBan - m_soNgayNghi * GiaoVien::TIEN_NGHI;
}