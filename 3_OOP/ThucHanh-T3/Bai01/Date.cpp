#include "Date.h"

Date::Date(int year)
{
	m_year = year > 0 ? year : 1;
	m_month = 1;
	m_day = 1;
}

Date::Date(int year, int month)
{
	m_year = year > 0 ? year : 1;
	m_month = month > 0 && month <= 12 ? month : 1;
	m_day = 1;
}

Date::Date(int year, int month, int day)
{
	m_year = year > 0 ? year : 1;
	m_month = month > 0 && month <= 12 ? month : 1;
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	m_day = day > 0 && day <= day_arr[this->laNamNhuan()][m_month - 1] ? day
									   : 1;
}

Date::Date(const Date &ngay)
{
	m_year = ngay.m_year;
	m_month = ngay.m_month;
	m_day = ngay.m_day;
}

bool Date::laNamNhuan()
{
	return m_year % 4 == 0 && m_year % 100 != 0 || m_year % 400 == 0;
}

// tang ngay giam ngay
Date Date::Tomorrow()
{
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	// cuoi nam va cuoi thang
	Date ngayMai;
	if (m_month == 12 && m_day == 31) {
		ngayMai.m_year = m_year + 1;
		ngayMai.m_month = 1;
		ngayMai.m_day = 1;
	} else if (m_day == day_arr[this->laNamNhuan()][m_month - 1]) {
		ngayMai.m_year = m_year;
		ngayMai.m_month = m_month + 1;
		ngayMai.m_day = 1;
	} else {
		ngayMai.m_year = m_year;
		ngayMai.m_month = m_month;
		ngayMai.m_day = m_day + 1;
	}
	return ngayMai;
}
Date Date::Yesterday()
{
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	// dau nam va dau thang
	Date homQua;
	if (m_month == 1 && m_day == 1) {
		homQua.m_year = m_year - 1;
		homQua.m_month = 12;
		homQua.m_day = 31;
	} else if (m_day == 1) {
		homQua.m_year = m_year;
		homQua.m_month = m_month - 1;
		homQua.m_day = day_arr[this->laNamNhuan()][homQua.m_month - 1];
	} else {
		homQua.m_year = m_year;
		homQua.m_month = m_month;
		homQua.m_day = m_day - 1;
	}
	return homQua;
}

// so sanh
bool Date::operator==(const Date &ngay)
{
	return m_year == ngay.m_year && m_month == ngay.m_month &&
	       m_day == ngay.m_day;
}

bool Date::operator!=(const Date &ngay)
{
	return !((*this) == ngay);
}

bool Date::operator>=(const Date &ngay)
{
	if (m_year > ngay.m_year)
		return true;
	if (m_year == ngay.m_year) {
		if (m_month > ngay.m_month)
			return true;
		if (m_month == ngay.m_month) {
			if (m_day >= ngay.m_day)
				return true;
			return false;
		}
		return false;
	}
	return false;
}

bool Date::operator<=(const Date &ngay)
{
	if (m_year < ngay.m_year)
		return true;
	if (m_year == ngay.m_year) {
		if (m_month < ngay.m_month)
			return true;
		if (m_month == ngay.m_month) {
			if (m_day <= ngay.m_day)
				return true;
			return false;
		}
		return false;
	}
	return false;
}

bool Date::operator>(const Date &ngay)
{
	return !((*this) <= ngay);
}

bool Date::operator<(const Date &ngay)
{
	return !((*this) >= ngay);
}

// phep tinh
Date Date::operator+(const int &day)
{
	Date ketqua(*this);
	for (int i = 0; i < day; i++) {
		ketqua = ketqua.Tomorrow();
	}
	return ketqua;
}

Date Date::operator-(const int &day)
{
	Date ketqua(*this);
	for (int i = 0; i < day; i++) {
		ketqua = ketqua.Yesterday();
	}
	return ketqua;
}

Date &Date::operator++()
{
	(*this) = this->Tomorrow();
	return (*this);
}

Date Date::operator++(int)
{
	Date temp = (*this);
	++(*this);
	return temp;
}

Date &Date::operator--()
{
	(*this) = this->Yesterday();
	return (*this);
}

Date Date::operator--(int)
{
	Date temp = (*this);
	--(*this);
	return temp;
}

Date &Date::operator=(const Date &ngay)
{
	m_year = ngay.m_year;
	m_month = ngay.m_month;
	m_day = ngay.m_day;
	return (*this);
}

Date &Date::operator+=(const int &day)
{
	(*this) = (*this) + day;
	return (*this);
}

Date &Date::operator-=(const int &day)
{
	(*this) = (*this) - day;
	return (*this);
}

// ep kieu
Date::operator int()
{
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int soNgay = m_day;
	for (int i = 1; i < m_month; i++) {
		soNgay += day_arr[this->laNamNhuan()][i - 1];
	}
	return soNgay;
}

Date::operator long()
{
	long soNgay = (int)(*this);
	for (int i = 1; i < m_year; i++) {
		soNgay += this->laNamNhuan() ? 366 : 365;
	}
	return soNgay;
}

// nhap xuat
istream &operator>>(istream &in, Date &ngay)
{
	do {
		cout << "Nhap nam: ";
		in >> ngay.m_year;
	} while (ngay.m_year < 1);
	do {
		cout << "Nhap thang: ";
		in >> ngay.m_month;
	} while (ngay.m_month < 1 || ngay.m_month > 12);
	int day_arr[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	do {
		cout << "Nhap ngay: ";
		in >> ngay.m_day;
	} while (ngay.m_day < 1 ||
		 ngay.m_day > day_arr[ngay.laNamNhuan()][ngay.m_month - 1]);
	return in;
}

ostream &operator<<(ostream &out, const Date &ngay)
{
	out << ngay.m_day << "/" << ngay.m_month << "/" << ngay.m_year;
	return out;
}