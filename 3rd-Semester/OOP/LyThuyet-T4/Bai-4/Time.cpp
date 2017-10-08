#include "Time.h"

// khoi tao
Time::Time(int hour, int minute, int second)
{
    m_absSecond = hour * 3600 + minute * 60 + second;
}

Time::Time(int absSecond) { m_absSecond = absSecond > 0 ? absSecond : 0; }

Time::Time(const Time &clock) { m_absSecond = clock.m_absSecond; }

// lay gio phut giay
int Time::getHour() const { return m_absSecond / 3600; }

int Time::getMinute() const { return (m_absSecond / 60) % 60; }

int Time::getSecond() const { return m_absSecond % 60; }

// nghiep vu
int Time::khoangCach(const Time &clock)
{
    int kcach = m_absSecond - clock.m_absSecond;
    return kcach > 0 ? kcach : -kcach;
}

Time Time::addHour(int hour)
{
    Time nextHour(m_absSecond + hour * 3600);
    return nextHour;
}

Time Time::addMinute(int minute)
{
    Time nextMinute(m_absSecond + minute * 60);
    return nextMinute;
}

Time Time::addSecond(int second)
{
    Time nextSecond(m_absSecond + second);
    return nextSecond;
}

// toan tu
bool Time::operator>(const Time &clock)
{
    return m_absSecond > clock.m_absSecond;
}

bool Time::operator<(const Time &clock)
{
    return m_absSecond < clock.m_absSecond;
}

bool Time::operator==(const Time &clock)
{
    return m_absSecond == clock.m_absSecond;
}

bool Time::operator>=(const Time &clock) { return !((*this) < clock); }

bool Time::operator<=(const Time &clock) { return !((*this) > clock); }

bool Time::operator!=(const Time &clock) { return !((*this) == clock); }

// cong tru giay
Time Time::operator+(const int &second)
{
    Time tong(m_absSecond + second);
    return tong;
}

Time Time::operator-(const int &second)
{
    Time hieu(m_absSecond - second);
    return hieu;
}

Time &Time::operator++()
{
    (*this) = (*this) + 1;
    return (*this);
}

Time Time::operator++(int)
{
    Time temp(*this);
    ++(*this);
    return temp;
}

Time &Time::operator--()
{
    (*this) = (*this) - 1;
    return (*this);
}

Time Time::operator--(int)
{
    Time temp(*this);
    --(*this);
    return temp;
}

istream &operator>>(istream &in, Time &clock)
{
    int hour;
    do
    {
        cout << "Hour: ";
        in >> hour;
    } while (hour < 0);
    int minute;
    do
    {
        cout << "Minute: ";
        in >> minute;
    } while (minute < 0);
    int second;
    do
    {
        cout << "Second: ";
        in >> second;
    } while (second < 0);
    clock.m_absSecond = hour * 3600 + minute * 60 + second;
    return in;
}

ostream &operator<<(ostream &out, const Time &clock)
{
    out << clock.getHour() << ":" << clock.getMinute() << ":"
        << clock.getSecond();
    return out;
}
