#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
      private:
	int m_absDay; // day from 1/1/1
	bool laNamNhuan(int year) const;
	int calcAbsDate(int year, int month, int day) const;
	int calcAbsDate(int year, int absDayInYear) const;
	int calcAbsDate(int year) const;

      public:
	// nhom khoi tao
	Date() : m_absDay(1){};
	Date(int year, int month, int day);
	Date(int year, int absDayInYear);
	Date(const Date &anoDate);
	Date(int absDay);

	// truy xuat thong tin
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	enum weekDay {
		sun = 1,
		mon = 2,
		tue = 3,
		wed = 4,
		thu = 5,
		fri = 6,
		sat = 7
	};
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);

	weekDay getWeekDay() const; // sunday or monday or what ?

	// nghiep vu
	Date addYear(int year);
	Date addMonth(int month);
	Date addDay(int day);

	// toan tu
	bool operator>(const Date &anoDate);
	bool operator<(const Date &anoDate);
	bool operator==(const Date &anoDate);
	bool operator>=(const Date &anoDate);
	bool operator<=(const Date &anoDate);
	bool operator!=(const Date &anoDate);

	Date operator+(const int &day);
	Date operator-(const int &day);
	Date &operator++();
	Date operator++(int);
	Date &operator--();
	Date operator--(int);

	friend istream &operator>>(istream &in, Date &inDate);
	friend ostream &operator<<(ostream &out, const Date &outDate);
};

#endif
