#define _CRT_SECURE_NO_WARNINGS
#include "GVCN.h"
#include <iostream>
#include <string.h>

#define MAX 1000

using namespace std;

GVCN::GVCN() : GiaoVien()
{
    m_lopChuNhiem = new char[1];
    m_lopChuNhiem[0] = '\0';
}

GVCN::GVCN(const char *maGV, const char *hoTen, const float &heSoLuong,
           const float &luongCoBan, const int &soNgayNghi,
           const char *lopChuNhiem)
    : GiaoVien(maGV, hoTen, heSoLuong, luongCoBan, soNgayNghi)
{
    m_lopChuNhiem = new char[strlen(lopChuNhiem) + 1];
    strcpy(m_lopChuNhiem, lopChuNhiem);
}

GVCN::GVCN(const GVCN &gvcn) : GiaoVien(gvcn)
{
    m_lopChuNhiem = new char[strlen(gvcn.m_lopChuNhiem) + 1];
    strcpy(m_lopChuNhiem, gvcn.m_lopChuNhiem);
}

GVCN::GVCN(const char *maGV) : GiaoVien(maGV)
{
    m_lopChuNhiem = new char[1];
    m_lopChuNhiem[0] = '\0';
}

GVCN::GVCN(const char *maGV, const char *hoTen) : GiaoVien(maGV, hoTen)
{
    m_lopChuNhiem = new char[1];
    m_lopChuNhiem[0] = '\0';
}

GVCN &GVCN::operator=(const GVCN &gvcn)
{
    GiaoVien::operator=(gvcn);
    m_lopChuNhiem = new char[strlen(gvcn.m_lopChuNhiem) + 1];
    strcpy(m_lopChuNhiem, gvcn.m_lopChuNhiem);
    return *this;
}

GVCN::~GVCN()
{
    delete[] m_lopChuNhiem;
}

void GVCN::nhap()
{
    GiaoVien::nhap();
    cout << "Nhap lop chu nhiem: ";
    char *lopChuNhiem = new char[MAX + 1];
    gets(lopChuNhiem);
    delete[] m_lopChuNhiem;
    m_lopChuNhiem = new char[strlen(lopChuNhiem) + 1];
    strcpy(m_lopChuNhiem, lopChuNhiem);
    delete[] lopChuNhiem;
}

void GVCN::xuat()
{
    GiaoVien::xuat();
    cout << "Lop chu nhiem: " << m_lopChuNhiem << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

float GVCN::tinhLuong()
{
    return GiaoVien::tinhLuong() + GiaoVien::PHU_CAP_CN;
}