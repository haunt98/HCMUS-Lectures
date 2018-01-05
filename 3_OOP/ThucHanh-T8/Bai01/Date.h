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
	bool sameMonth(int month);
	friend istream &operator>>(istream &in, Date &ngay);
	friend ostream &operator<<(ostream &out, const Date &ngay);
};

#endif