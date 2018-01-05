#include "Date.h"

// nhom private
bool Date::laNamNhuan(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::calcAbsDate(int year, int month, int day) const
{
	int absDay = 0;
	for (int i = 1; i < year; i++) {
		absDay += 365 + laNamNhuan(i);
	}
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	for (int i = 1; i < month; i++) {
		absDay += day_arr[laNamNhuan(year)][i - 1];
	}
	absDay += day;
	return absDay;
}

int Date::calcAbsDate(int year, int absDayInYear) const
{
	int absDay = 0;
	for (int i = 1; i < year; i++) {
		absDay += 365 + laNamNhuan(i);
	}
	absDay += absDayInYear;
	return absDay;
}

int Date::calcAbsDate(int year) const
{
	int absDay = 0;
	for (int i = 1; i < year; i++) {
		absDay += 365 + laNamNhuan(i);
	}
	return absDay;
}

// nhom khoi tao
Date::Date(int year, int month, int day)
{
	m_absDay = calcAbsDate(year, month, day);
}

Date::Date(int year, int absDayInYear)
{
	m_absDay = calcAbsDate(year, absDayInYear);
}

Date::Date(const Date &anoDate)
{
	m_absDay = anoDate.m_absDay;
}

Date::Date(int absDay)
{
	m_absDay = absDay > 0 ? absDay : 1;
}

// truy xuat thong tin
int Date::getYear() const
{
	int year = 1;
	int day = 0;
	while (day > m_absDay || day + 365 + laNamNhuan(year) < m_absDay) {
		day += 365 + laNamNhuan(year++);
	}
	return year;
}

int Date::getMonth() const
{
	int year = getYear();
	int absDayInYear = m_absDay - calcAbsDate(year);
	int month = 1;
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int day = 0;
	while (day > absDayInYear ||
	       day + day_arr[laNamNhuan(year)][month - 1] < absDayInYear) {
		day += day_arr[laNamNhuan(year)][month - 1];
		month++;
	}
	return month;
}

int Date::getDay() const
{
	int year = getYear();
	int day = m_absDay - calcAbsDate(year);
	int month = getMonth();
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	for (int i = 1; i < month; i++) {
		day -= day_arr[laNamNhuan(year)][i - 1];
	}
	return day;
}

Date::weekDay Date::getWeekDay() const
{
	Date sunday(2017, 10, 1); // chon mot ngay lam chu nhat
	int distance = m_absDay - sunday.m_absDay;
	distance = distance % 7 > 0 ? distance % 7 : distance % 7 + 7;
	weekDay typeDay;
	switch (distance % 7) {
	case 0:
		typeDay = sun;
		break;
	case 1:
		typeDay = mon;
		break;
	case 2:
		typeDay = tue;
		break;
	case 3:
		typeDay = wed;
		break;
	case 4:
		typeDay = thu;
		break;
	case 5:
		typeDay = fri;
		break;
	case 6:
		typeDay = sat;
		break;
	}
	return typeDay;
}

void Date::setYear(int year)
{
	int month = getMonth();
	int day = getDay();
	if (!laNamNhuan(year) && month == 2 && day == 29)
		day = 28;
	m_absDay = calcAbsDate(year, month, day);
}

void Date::setMonth(int month)
{
	month = month > 0 && month <= 12 ? month : 1;
	int year = getYear();
	int day = getDay();
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	day = day < day_arr[laNamNhuan(year)][month - 1]
		  ? day
		  : day_arr[laNamNhuan(year)][month - 1];
	m_absDay = calcAbsDate(year, month, day);
}

void Date::setDay(int day)
{
	int year = getYear();
	int month = getMonth();
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	day = day < day_arr[laNamNhuan(year)][month - 1]
		  ? day
		  : day_arr[laNamNhuan(year)][month - 1];
	m_absDay = calcAbsDate(year, month, day);
}

// nghiep vu
Date Date::addYear(int year)
{
	Date nextYear(*this);
	nextYear.setYear(nextYear.getYear() + year);
	return nextYear;
}

Date Date::addMonth(int month)
{
	Date nextMonth(*this);
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int nowYear = getYear();
	int nowMonth = getMonth();
	for (int i = 1; i <= month; i++) {
		int j = (nowMonth + i) / 12;
		int k = (nowMonth + i) % 12 - 1;
		if (k == -1)
			k = 11;
		nextMonth.m_absDay += day_arr[laNamNhuan(nowYear + j)][k];
	}
	return nextMonth;
}

Date Date::addDay(int day)
{
	Date nextDay(*this);
	nextDay.m_absDay += day;
	return nextDay;
}

// toan tu
bool Date::operator>(const Date &anoDate)
{
	return m_absDay > anoDate.m_absDay;
}

bool Date::operator<(const Date &anoDate)
{
	return m_absDay < anoDate.m_absDay;
}

bool Date::operator==(const Date &anoDate)
{
	return m_absDay == anoDate.m_absDay;
}

bool Date::operator>=(const Date &anoDate)
{
	return m_absDay >= anoDate.m_absDay;
}
bool Date::operator<=(const Date &anoDate)
{
	return m_absDay <= anoDate.m_absDay;
}
bool Date::operator!=(const Date &anoDate)
{
	return m_absDay != anoDate.m_absDay;
}

Date Date::operator+(const int &day)
{
	Date tong(m_absDay + day);
	return tong;
}

Date Date::operator-(const int &day)
{
	Date hieu(m_absDay - day);
	return hieu;
}

Date &Date::operator++()
{
	(*this) = (*this) + 1;
	return (*this);
}

Date Date::operator++(int)
{
	Date temp(*this);
	++(*this);
	return temp;
}

Date &Date::operator--()
{
	(*this) = (*this) - 1;
	return (*this);
}

Date Date::operator--(int)
{
	Date temp(*this);
	--(*this);
	return temp;
}

istream &operator>>(istream &in, Date &inDate)
{
	int year;
	do {
		cout << "Nhap nam: ";
		in >> year;

	} while (year < 1);
	int month;
	do {
		cout << "Nhap thang: ";
		in >> month;

	} while (month < 1 || month > 12);
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int day;
	do {
		cout << "Nhap ngay: ";
		in >> day;

	} while (day < 1 || day > day_arr[inDate.laNamNhuan(year)][month - 1]);
	inDate.m_absDay = inDate.calcAbsDate(year, month, day);
	return in;
}

ostream &operator<<(ostream &out, const Date &outDate)
{
	out << outDate.getDay() << "/" << outDate.getMonth() << "/"
	    << outDate.getYear();
	return out;
}
