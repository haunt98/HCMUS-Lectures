#include "hocsinh.h"
#include <iostream>
#include <string.h>

using namespace std;

void HocSinh::nhap()
{
	cout << "Nhap ten : ";
	fgets(this->m_Ten, MAXTEN, stdin);
	this->m_Ten[strlen(this->m_Ten) - 1] = '\0'; // xoa new line
	cout << "Nhap diem van : ";
	cin >> this->m_DiemVan;
	cout << "Nhap diem toan : ";
	cin >> this->m_DiemToan;
}

void HocSinh::xuat()
{
	cout << "Ten : " << this->m_Ten << "!" << endl;
	cout << "Diem van : " << this->m_DiemVan << endl;
	cout << "Diem toan : " << this->m_DiemToan << endl;
}

char *HocSinh::layTen()
{
	return this->m_Ten;
}

float HocSinh::layDiemVan()
{
	return this->m_DiemVan;
}

float HocSinh::layDiemToan()
{
	return this->m_DiemToan;
}

float HocSinh::layDiemTB()
{
	return (this->m_DiemVan + this->m_DiemToan) / 2;
}

xeploai HocSinh::layXepLoai()
{
	if (this->layDiemTB() >= 8.0)
		return gioi;
	else if (this->layDiemTB() >= 7.0)
		return kha;
	else if (this->layDiemTB() >= 5.0)
		return tb;
	return yeu;
}
