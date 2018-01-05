#include "Date.h"

Date::Date() : m_day(1), m_month(1), m_year(1)
{
}

bool Date::sameMonth(int month)
{
	return m_month == month;
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