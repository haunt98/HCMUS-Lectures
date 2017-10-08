#include "NgaySinh.h"
#include <iostream>

using namespace std;

NgaySinh::NgaySinh()
{
    this->m_year = 1;
    this->m_month = 1;
    this->m_day = 1;
}

NgaySinh::NgaySinh(int year, int month, int day)
{
    this->m_year = year > 0 ? year : 1;
    this->m_month = month > 0 && month <= 12 ? month : 1;
    int arrMonth[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                           {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    if (year % 4 == 0 && year % 100 != 0 || year % 400) // nam nhuan
    {
        this->m_day =
            day > 0 && day <= arrMonth[0][this->m_month - 1] ? day : 1;
    }
    else
    {
        this->m_day =
            day > 0 && day <= arrMonth[1][this->m_month - 1] ? day : 1;
    }
}

NgaySinh::NgaySinh(const NgaySinh &ns)
{
    this->m_year = ns.m_year;
    this->m_month = ns.m_month;
    this->m_day = ns.m_day;
}

void NgaySinh::Xuat()
{
    cout << this->m_day << "/" << this->m_month << "/" << this->m_year;
}

NgaySinh::~NgaySinh() {}