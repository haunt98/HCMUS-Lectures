#ifndef NGAY_H
#define NGAY_H

class Ngay
{
      private:
	int m_day, m_month, m_year;

      public:
	Ngay();
	Ngay(int year);
	Ngay(int year, int month);
	Ngay(int year, int month, int day);
	Ngay(const Ngay &date);
	void Xuat();
	~Ngay();
};

#endif