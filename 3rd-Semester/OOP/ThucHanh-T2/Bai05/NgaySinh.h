#ifndef NGAYSINH_H
#define NGAYSINH_H

class NgaySinh
{
private:
    int m_year, m_month, m_day;

public:
    NgaySinh();
    NgaySinh(int year, int month, int day);
    NgaySinh(const NgaySinh &ns);
    void Xuat();
    ~NgaySinh();
};

#endif