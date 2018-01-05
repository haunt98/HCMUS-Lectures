#include "NhanVien.h"
#include <iostream>

using namespace std;

// Nhan vien
NhanVien::NhanVien() : m_NgaySinh()
{
	m_maNV = "";
	m_Ten = "";
	m_DiaChi = "";
}

void NhanVien::nhap()
{
	cout << "Nhap ma nhan vien: ";
	getline(cin >> ws, m_maNV);
	cout << "Nhap ten: ";
	getline(cin >> ws, m_Ten);
	cout << "Nhap ngay sinh: ";
	cin >> m_NgaySinh;
	cout << "Nhap dia chi: ";
	getline(cin >> ws, m_DiaChi);
}

// Tra ve gia tri
string NhanVien::layMaNV()
{
	return m_maNV;
}

string NhanVien::layTen()
{
	return m_Ten;
}

Date NhanVien::layNgaySinh()
{
	return m_NgaySinh;
}

void NhanVien::xuat()
{
	cout << "Ma nhan vien: " << m_maNV << endl;
	cout << "Ten: " << m_Ten << endl;
	cout << "Ngay sinh: " << m_NgaySinh << endl;
	cout << "Dia chi: " << m_DiaChi << endl;
	cout << "Luong: " << tinhLuong() << "k" << endl;
}

// Nhan vien san xuat
void NVSanXuat::nhap()
{
	NhanVien::nhap();
	cout << "Nhap so san pham: ";
	cin >> m_SanPham;
}

void NVSanXuat::xuat()
{
	NhanVien::xuat();
	cout << "So san pham: " << m_SanPham << endl;
}

float NVSanXuat::tinhLuong()
{
	return NhanVien::MONEY_PER_OBJ * m_SanPham;
}

// Nhan vien cong nhat
void NVCongNhat::nhap()
{
	NhanVien::nhap();
	cout << "Nhap so ngay: ";
	cin >> m_Ngay;
}

void NVCongNhat::xuat()
{
	NhanVien::xuat();
	cout << "So ngay: " << m_Ngay << endl;
}

float NVCongNhat::tinhLuong()
{
	return NhanVien::MONEY_PER_DAY * m_Ngay;
}