#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
      private:
	int m_year, m_month, m_day;

      public:
	Date() : m_year(2012), m_month(1), m_day(1)
	{
	}
	Date(int year);
	Date(int year, int month);
	Date(int year, int month, int day);
	Date(const Date &ngay);
	~Date()
	{
	}

	bool laNamNhuan();
	// tang ngay giam ngay
	Date Tomorrow();
	Date Yesterday();

	// so sanh
	bool operator==(const Date &ngay);
	bool operator!=(const Date &ngay);
	bool operator>=(const Date &ngay);
	bool operator<=(const Date &ngay);
	bool operator>(const Date &ngay);
	bool operator<(const Date &ngay);

	// phep tinh
	Date operator+(const int &day);
	Date operator-(const int &day);
	Date &operator++();
	Date operator++(int);
	Date &operator--();
	Date operator--(int);
	Date &operator=(const Date &ngay);
	Date &operator+=(const int &day);
	Date &operator-=(const int &day);

	// ep kieu
	operator int();
	operator long();

	// nhap xuat
	friend istream &operator>>(istream &in, Date &ngay);
	friend ostream &operator<<(ostream &out, const Date &ngay);
};

#endif