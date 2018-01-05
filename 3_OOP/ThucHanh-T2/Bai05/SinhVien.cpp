#include "SinhVien.h"
#include <iostream>
#include <string.h>

using namespace std;

void SinhVien::Xuat()
{
	cout << this->m_ten << " - " << this->m_mssv << " - ";
	this->m_born.Xuat();
	cout << " - " << this->m_dlt << " DLT " << this->m_dth << " DTH"
	     << endl;
}

SinhVien::SinhVien()
{
	strcpy_s(this->m_mssv, "");
	if (this->m_ten == NULL)
		this->m_ten = _strdup("");
	this->m_dlt = this->m_dth = 0;
	this->m_born = NgaySinh(1, 1, 1);
}

SinhVien::SinhVien(const char *mssv)
{
	strcpy_s(this->m_mssv, mssv);
	if (this->m_ten == NULL)
		this->m_ten = _strdup("");
	this->m_dlt = this->m_dth = 0;
	this->m_born = NgaySinh(1, 1, 1);
}
SinhVien::SinhVien(const char *mssv, char *ten)
{
	strcpy_s(this->m_mssv, mssv);
	if (this->m_ten == NULL)
		this->m_ten = _strdup(ten);
	this->m_dlt = this->m_dth = 0;
	this->m_born = NgaySinh(1, 1, 1);
}

SinhVien::SinhVien(const char *mssv, char *ten, double dlt, double dth)
{
	strcpy_s(this->m_mssv, mssv);
	if (this->m_ten == NULL)
		this->m_ten = _strdup(ten);
	this->m_dlt = dlt;
	this->m_dth = dth;
	this->m_born = NgaySinh(1, 1, 1);
}

SinhVien::SinhVien(const char *mssv, char *ten, NgaySinh ns)
{
	strcpy_s(this->m_mssv, mssv);
	if (this->m_ten == NULL)
		this->m_ten = _strdup(ten);
	this->m_dlt = this->m_dth = 0;
	this->m_born = NgaySinh(ns);
}

SinhVien::SinhVien(const char *mssv, char *ten, NgaySinh ns, double dlt,
		   double dth)
{
	strcpy_s(this->m_mssv, mssv);
	if (this->m_ten == NULL)
		this->m_ten = _strdup(ten);
	this->m_dlt = dlt;
	this->m_dth = dth;
	this->m_born = NgaySinh(ns);
}

SinhVien::SinhVien(const char *mssv, char *ten, int year, int month, int day,
		   double dlt, double dth)
{
	strcpy_s(this->m_mssv, mssv);
	if (this->m_ten == NULL)
		this->m_ten = _strdup(ten);
	this->m_dlt = dlt;
	this->m_dth = dth;
	this->m_born = NgaySinh(year, month, day);
}

SinhVien::SinhVien(const SinhVien &sv)
{
	strcpy_s(this->m_mssv, sv.m_mssv);
	if (this->m_ten == NULL)
		this->m_ten = _strdup(sv.m_ten);
	this->m_dlt = sv.m_dlt;
	this->m_dth = sv.m_dth;
	this->m_born = NgaySinh(sv.m_born);
}

SinhVien::~SinhVien()
{
	if (this->m_ten != NULL) {
		free(this->m_ten);
		this->m_ten = NULL;
	}
}