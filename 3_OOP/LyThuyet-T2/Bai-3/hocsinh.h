#ifndef HOCSINH_H
#define HOCSINH_H

#define MAXTEN 100

enum xeploai { gioi, kha, tb, yeu };

class HocSinh {
   private:
    char m_Ten[MAXTEN];
    float m_DiemVan, m_DiemToan;

   public:
    void nhap();
    void xuat();
    char *layTen();
    float layDiemVan();
    float layDiemToan();
    float layDiemTB();
    xeploai layXepLoai();
};

#endif
