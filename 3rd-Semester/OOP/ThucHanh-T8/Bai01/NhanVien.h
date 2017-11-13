#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "Date.h"
#include <string>

using namespace std;

class NhanVien
{
private:
    string m_maNV;
    string m_Ten;
    Date m_NgaySinh;
    string m_DiaChi;

public:
    // Khoi tao
    NhanVien();

    // Tra ve gia tri
    string layMaNV();
    string layTen();
    Date layNgaySinh();

    // Nhap xuat
    virtual void nhap();
    virtual void xuat();

    // Tinh luong
    virtual float tinhLuong() = 0;

    // Static
    static float MONEY_PER_OBJ;
    static float MONEY_PER_DAY;
};

class NVSanXuat : public NhanVien
{
private:
    int m_SanPham;

public:
    void nhap();
    void xuat();
    float tinhLuong();
};

class NVCongNhat : public NhanVien
{
private:
    int m_Ngay;

public:
    void nhap();
    void xuat();
    float tinhLuong();
};

#endif