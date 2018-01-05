#include "DuongTron.h"
#include <iostream>

using namespace std;

#define PI 3.14

void DuongTron::nhap()
{
	cout << "Nhap toa do tam (x,y) : ";
	cin >> this->m_tam.x >> this->m_tam.y;
	do {
		cout << "Nhap ban kinh : ";
		cin >> this->m_r;
	} while (this->m_r < 0);
}

void DuongTron::xuat()
{
	cout << "(" << this->m_tam.x << "," << this->m_tam.y
	     << ") r = " << this->m_r << endl;
}

double DuongTron::chuvi()
{
	return this->m_r * 2 * PI;
}

double DuongTron::dientich()
{
	return this->m_r * this->m_r * PI;
}