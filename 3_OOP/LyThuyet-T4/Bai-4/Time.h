#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time
{
      private:
	int m_absSecond;

      public:
	// khoi tao
	Time() : m_absSecond(0)
	{
	}
	Time(int hour, int minute, int second);
	Time(int absSecond);
	Time(const Time &clock);

	// lay gio, phut giay tuong doi
	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	// nghiep vu
	int khoangCach(const Time &clock);
	Time addHour(int hour);
	Time addMinute(int minute);
	Time addSecond(int minute);

	// toan tu
	bool operator>(const Time &clock);
	bool operator<(const Time &clock);
	bool operator==(const Time &clock);
	bool operator>=(const Time &clock);
	bool operator<=(const Time &clock);
	bool operator!=(const Time &clock);

	// cong tru giay
	Time operator+(const int &second);
	Time operator-(const int &second);
	Time &operator++();
	Time operator++(int);
	Time &operator--();
	Time operator--(int);

	friend istream &operator>>(istream &in, Time &clock);
	friend ostream &operator<<(ostream &out, const Time &clock);
};

#endif
