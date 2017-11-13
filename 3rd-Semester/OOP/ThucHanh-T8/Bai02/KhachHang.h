#ifndef KHACHHANG_H
#define KHACHHANG_H

#include "GoiCuoc.h"
#include <string>

using namespace std;

class KhachHang
{
private:
    string m_Ten;
    string m_CMND;
    string m_DiaChi;
    GoiCuocBasic *m_cuoc;

public:
    KhachHang();
    KhachHang(string Ten, string CMND, string DiaChi, GoiCuocBasic *cuoc);
    KhachHang(const KhachHang &);
    ~KhachHang();
    KhachHang &operator=(const KhachHang &);

    void DangKy(GoiCuocBasic *cuoc);
    float TienCuoc();
};

#endif