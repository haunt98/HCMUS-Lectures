#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "Date.h"

class NhanVien
{
private:
    char *m_maNhanVien;
    char *m_hoTen;
    Date m_ngaySinh;
    char *m_diaChi;

public:
    NhanVien();
    NhanVien(const char *, const char *, Date, const char *);
    NhanVien(const NhanVien &nv);
    NhanVien(const char *maNhanVien);
    NhanVien(const char *hoTen, Date ngaySinh);
    NhanVien &operator=(const NhanVien &nv);
    ~NhanVien();

    static int GiaSP;
    static int LuongNgay;
    int tinhLuong();
    void nhap();
    void xuat();
};

#endif