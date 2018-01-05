#include "Date.h"

Date::Date()
{
	m_day = m_month = m_year = 1;
}

Date::Date(int day, int month, int year)
{
	m_day = day;
	m_month = month;
	m_year = year;
}

Date &Date::operator=(const Date &ngkhac)
{
	m_day = ngkhac.m_day;
	m_month = ngkhac.m_month;
	m_year = ngkhac.m_year;
	return *this;
}

istream &operator>>(istream &in, Date &ngay)
{
	in >> ngay.m_day >> ngay.m_month >> ngay.m_year;
	return in;
}

ostream &operator<<(ostream &out, const Date &ngay)
{
	out << ngay.m_day << "/" << ngay.m_month << "/" << ngay.m_year;
	return out;
}