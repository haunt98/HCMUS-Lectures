#ifndef _SAP_H
#define _SAP_H

#include <iostream>
using namespace std;

class SAP
{
private:
    int mThuTu;
    float mDienTich;
    float mDoanhThu;
    float mThue;
    static float DON_GIA; // dv kVND

public:
    SAP() { mThuTu = mDienTich = mDoanhThu = mThue = 0; }
    SAP(int ThuTu, float DienTich, float DoanhThu)
    {
        mThuTu = ThuTu;
        mDienTich = DienTich;
        mDoanhThu = DoanhThu;
        mThue = 0;
    }
    float tienThueSap() const { return DON_GIA * mDienTich; }
    float tienCuoiNam() const { return tienThueSap() + mThue * mDoanhThu; }
    void updateThue(float Thue) { mThue = Thue; }
    friend istream &operator>>(istream &in, SAP &sap);
    friend ostream &operator<<(ostream &out, const SAP &sap);
};

class SThucPham : public SAP
{
private:
    static const float THUE_THUC_PHAM;

public:
    SThucPham() : SAP() { updateThue(THUE_THUC_PHAM); }
    SThucPham(int ThuTu, float DienTich, float DoanhThu)
        : SAP(ThuTu, DienTich, DoanhThu)
    {
        updateThue(THUE_THUC_PHAM);
    }
};

class SQuanAo : public SAP
{
private:
    static const float THUE_QUAN_AO;

public:
    SQuanAo() : SAP() { updateThue(THUE_QUAN_AO); }
    SQuanAo(int ThuTu, float DienTich, float DoanhThu)
        : SAP(ThuTu, DienTich, DoanhThu)
    {
        updateThue(THUE_QUAN_AO);
    }
};

class STrangSuc : public SAP
{
private:
    static const float THUE_TRANG_SUC_Small;
    static const float THUE_TRANG_SUC_Big;

public:
    STrangSuc() : SAP() { updateThue(THUE_TRANG_SUC_Small); }
    STrangSuc(int ThuTu, float DienTich, float DoanhThu)
        : SAP(ThuTu, DienTich, DoanhThu)
    {
        if (DoanhThu < 100000)
        {
            updateThue(THUE_TRANG_SUC_Small);
        }
        else
        {
            updateThue(THUE_TRANG_SUC_Big);
        }
    }
};

#endif
