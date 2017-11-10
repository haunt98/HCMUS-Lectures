#ifndef GIAOVIEN_H
#define GIAOVIEN_H

class GiaoVien
{
private:
    char *m_maGV;
    char *m_hoTen;
    float m_heSoLuong;
    float m_luongCoBan;
    int m_soNgayNghi;

public:
    GiaoVien();
    GiaoVien(const char *maGV, const char *hoTen, const float &heSoLuong,
             const float &luongCoBan, const int &soNgayNghi);
    GiaoVien(const GiaoVien &gv);
    GiaoVien(const char *maGV);
    GiaoVien(const char *maGV, const char *hoTen);
    GiaoVien &operator=(const GiaoVien &gv);
    ~GiaoVien();

    void nhap();
    void xuat();
    static float TIEN_NGHI;
    static float PHU_CAP_CN;
    float tinhLuong();
};

#endif