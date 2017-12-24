#ifndef CONGTY_H
#define CONGTY_H

#include "NhanVien.h"
#include <vector>

using namespace std;

class CongTy
{
private:
    vector<NhanVien *> m_vecNhanVien;
    int m_slNVSanXuat;

public:
    CongTy() {}
    ~CongTy();

    // Nhap xuat danh sach nhan vien
    void nhap();
    void xuat();

    // So luong
    int slNVSanXuat();
    int slNVCongNhat();

    // Lien quan den luong
    float tongLuong();
    NhanVien *nvLuongCaoNhat();
    float tbLuong();

    // Liet ke
    void lietkeLuongThapHon(float chanTrenLuong);
    void lietkeSinhThang(int thang);

    // Tim nhan vien
    NhanVien *timMaNV(string maNV);
    NhanVien *timTen(string ten);
};

#endif