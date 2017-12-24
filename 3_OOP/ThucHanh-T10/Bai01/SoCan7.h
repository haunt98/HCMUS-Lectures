#ifndef _SOCAN7_H
#define _SOCAN7_H

class SoCan7
{
private:
    int m_a, m_b;

public:
    SoCan7() : m_a(0), m_b(0) {}
    void nhap();
    void xuat();
    SoCan7 operator+(const SoCan7 &s);
    SoCan7 operator-(const SoCan7 &s);
    SoCan7 operator*(const SoCan7 &s);
    SoCan7 doiDau();
};

#endif