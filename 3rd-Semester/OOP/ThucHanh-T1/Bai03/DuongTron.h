#ifndef DUONGTRON_H
#define DUONGTRON_H

struct ToaDo
{
    double x, y;
};

class DuongTron
{
private:
    ToaDo m_tam;
    double m_r;

public:
    void nhap();
    void xuat();
    double chuvi();
    double dientich();
};

#endif