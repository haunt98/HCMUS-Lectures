#include "CongTy.h"
#include <iostream>

using namespace std;

// Nhap xuat danh sach nhan vien
void CongTy::nhap()
{
    m_slNVSanXuat = 0;
    while (true)
    {
        cout << "1: NVSanXuat, 2: NVCongNhat, anykey: Exit ";
        int input;
        cin >> input;
        if (input == 1)
        {
            NVSanXuat *temp_sx = new NVSanXuat;
            temp_sx->nhap();
            m_vecNhanVien.push_back(temp_sx);
            ++m_slNVSanXuat;
        }
        else if (input == 2)
        {
            NVCongNhat *temp_cn = new NVCongNhat;
            temp_cn->nhap();
            m_vecNhanVien.push_back(temp_cn);
        }
        else
        {
            break;
        }
    }
}

CongTy::~CongTy()
{
    for (int i = 0; i < m_vecNhanVien.size(); ++i)
    {
        delete m_vecNhanVien[i];
    }
    m_vecNhanVien.clear();
}

void CongTy::xuat()
{
    for (int i = 0; i < m_vecNhanVien.size(); ++i)
    {
        m_vecNhanVien[i]->xuat();
    }
}

// So luong
int CongTy::slNVSanXuat()
{
    return m_slNVSanXuat;
}

int CongTy::slNVCongNhat()
{
    return m_vecNhanVien.size() - m_slNVSanXuat;
}

// Lien quan den luong
float CongTy::tongLuong()
{
    float sum = 0;
    for (int i = 0; i < m_vecNhanVien.size(); ++i)
    {
        sum += m_vecNhanVien[i]->tinhLuong();
    }
    return sum;
}

NhanVien *CongTy::nvLuongCaoNhat()
{
    if (m_vecNhanVien.size() == 0)
    {
        return nullptr;
    }
    NhanVien *max = m_vecNhanVien[0];
    for (int i = 1; i < m_vecNhanVien.size(); ++i)
    {
        if (max->tinhLuong() < m_vecNhanVien[i]->tinhLuong())
        {
            max = m_vecNhanVien[i];
        }
    }
    return max;
}

float CongTy::tbLuong()
{
    return tongLuong() / (m_vecNhanVien.size());
}

// Liet ke
void CongTy::lietkeLuongThapHon(float chanTrenLuong)
{
    for (int i = 0; i < m_vecNhanVien.size(); ++i)
    {
        if (m_vecNhanVien[i]->tinhLuong() < chanTrenLuong)
        {
            m_vecNhanVien[i]->xuat();
        }
    }
}

void CongTy::lietkeSinhThang(int thang)
{
    for (int i = 0; i < m_vecNhanVien.size(); ++i)
    {
        if (m_vecNhanVien[i]->layNgaySinh().sameMonth(thang))
        {
            m_vecNhanVien[i]->xuat();
        }
    }
}

// Tim nhan vien
NhanVien *CongTy::timMaNV(string maNV)
{
    for (int i = 0; i < m_vecNhanVien.size(); ++i)
    {
        if (m_vecNhanVien[i]->layMaNV() == maNV)
        {
            return m_vecNhanVien[i];
        }
    }
    return nullptr;
}

NhanVien *CongTy::timTen(string ten)
{
    for (int i = 0; i < m_vecNhanVien.size(); ++i)
    {
        if (m_vecNhanVien[i]->layTen() == ten)
        {
            return m_vecNhanVien[i];
        }
    }
    return nullptr;
}