#include "Ngay.h"
#include <iostream>

using namespace std;

Ngay::Ngay()
{
	this->m_year = 1;
	this->m_month = 1;
	this->m_day = 1;
}

Ngay::Ngay(int year)
{
	this->m_year = year > 0 ? year : 1;
	this->m_month = 1;
	this->m_day = 1;
}

Ngay::Ngay(int year, int month)
{
	this->m_year = year > 0 ? year : 1;
	this->m_month = month > 0 && month <= 12 ? month : 1;
	this->m_day = 1;
}

Ngay::Ngay(int year, int month, int day)
{
	this->m_year = year > 0 ? year : 1;
	this->m_month = month > 0 && month <= 12 ? month : 1;
	int arrMonth[2][12] = {
	    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	if (year % 4 == 0 && year % 100 != 0 || year % 400) // nam nhuan
	{
		this->m_day =
		    day > 0 && day <= arrMonth[0][this->m_month - 1] ? day : 1;
	} else {
		this->m_day =
		    day > 0 && day <= arrMonth[1][this->m_month - 1] ? day : 1;
	}
}

Ngay::Ngay(const Ngay &date)
{
	this->m_year = date.m_year;
	this->m_month = date.m_month;
	this->m_day = date.m_day;
}

void Ngay::Xuat()
{
	cout << this->m_day << "/" << this->m_month << "/" << this->m_year
	     << endl;
}

Ngay::~Ngay()
{
}
