#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
      private:
	int m_day, m_month, m_year;

      public:
	Date();
	Date(int day, int month, int year);
	Date &operator=(const Date &ngkhac);
	friend istream &operator>>(istream &in, Date &ngay);
	friend ostream &operator<<(ostream &out, const Date &ngay);
};

#endif