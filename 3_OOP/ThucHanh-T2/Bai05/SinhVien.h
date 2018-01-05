#ifndef SINHVIEN_H
#define SINHVIEN_H

#include "NgaySinh.h"

class SinhVien
{
      private:
	char m_mssv[8];
	char *m_ten;
	double m_dlt, m_dth; // diem ly thuyet, diem thuc hanh
	NgaySinh m_born;

      public:
	void Xuat();
	SinhVien();
	SinhVien(const char *mssv);
	SinhVien(const char *mssv, char *ten);
	SinhVien(const char *mssv, char *ten, double dlt, double dth);
	SinhVien(const char *mssv, char *ten, NgaySinh ns);
	SinhVien(const char *mssv, char *ten, NgaySinh ns, double dlt,
		 double dth);
	SinhVien(const char *mssv, char *ten, int year, int month, int day,
		 double dlt, double dth);
	SinhVien(const SinhVien &sv);
	~SinhVien();
};

#endif