#include "MangDuongTron.h"
#include "DuongTron.h"
#include <iostream>

using namespace std;

void MangDuongTron::nhap()
{
	cout << "Nhap so luong mang duong tron : ";
	cin >> this->m_size;
	this->m_arr = new DuongTron[this->m_size];
	for (int i = 0; i < this->m_size; i++) {
		this->m_arr[i].nhap();
	}
}

void MangDuongTron::xuat()
{
	for (int i = 0; i < this->m_size; i++) {
		this->m_arr[i].xuat();
	}
}

MangDuongTron::~MangDuongTron()
{
	delete[] this->m_arr;
}

bool MangDuongTron::nhohon(double a, double b)
{
	return a <= b;
}

bool MangDuongTron::lonhon(double a, double b)
{
	return a >= b;
}

DuongTron MangDuongTron::tim(double (DuongTron::*giatri)(),
			     bool (MangDuongTron::*sosanh)(double, double))
{
	int tim_index = 0;
	for (int i = 1; i < this->m_size; i++) {
		if (!(this->*sosanh)((this->m_arr[tim_index].*giatri)(),
				     (this->m_arr[i].*giatri)())) {
			tim_index = i;
		}
	}
	return this->m_arr[tim_index];
}

void MangDuongTron::sapxep(double (DuongTron::*giatri)(),
			   bool (MangDuongTron::*sosanh)(double, double))
{
	for (int i = 0; i < this->m_size; i++) {
		for (int j = i + 1; j < this->m_size; j++) {

			if (!(this->*sosanh)((this->m_arr[i].*giatri)(),
					     (this->m_arr[j].*giatri)())) {
				DuongTron temp = this->m_arr[i];
				this->m_arr[i] = this->m_arr[j];
				this->m_arr[j] = temp;
			}
		}
	}
}