#ifndef TAMGIAC_H
#define TAMGIAC_H

class Diem;

class TamGiac
{
private:
    Diem *m_diem;

public:
    void nhap();
    void xuat();
    void xoa();
    double chuvi();
    double dientich();
    bool laTamGiac();
    bool laTamGiacDeu();
    bool laTamGiacVuong();
    bool laTamGiacCan();
    bool laTamGiacVuongCan();
    void loai(); // xet loai tam giac
    void swap(TamGiac &tg);
};

#endif