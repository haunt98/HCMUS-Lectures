#ifndef PHANSO_H
#define PHANSO_H

class PhanSo {
private:
    int m_tu, m_mau;
    static int soluong;
    PhanSo();
    PhanSo(const PhanSo& ps);
    PhanSo(int tu, int mau);

public:
    static PhanSo* tao(int tu, int mau);
    void xuat();
    int laySoluong();
    ~PhanSo();
};

#endif
