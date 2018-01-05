#include "MangSoNguyen.h"
#include <iostream>

using namespace std;

void MangSoNguyen::Xuat()
{
	for (int i = 0; i < this->m_size; i++) {
		cout << this->m_arr[i] << " ";
	}
	cout << endl;
}

MangSoNguyen::MangSoNguyen()
{
	this->m_size = 0;
	this->m_arr = NULL;
}

MangSoNguyen::MangSoNguyen(int size)
{
	this->m_size = size;
	if (this->m_arr == NULL) {
		this->m_arr = new int[this->m_size];
		for (int i = 0; i < this->m_size; i++) {
			this->m_arr[i] = 0;
		}
	}
}

MangSoNguyen::~MangSoNguyen()
{
	if (this->m_arr != NULL) {
		delete[] this->m_arr;
		this->m_arr = NULL;
	}
}

MangSoNguyen::MangSoNguyen(int *arr, int size)
{
	this->m_size = size;
	if (this->m_arr == NULL) {
		this->m_arr = new int[this->m_size];
		for (int i = 0; i < this->m_size; i++) {
			this->m_arr[i] = arr[i];
		}
	}
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen &mang)
{
	this->m_size = mang.m_size;
	if (this->m_arr == NULL) {
		this->m_arr = new int[this->m_size];
		for (int i = 0; i < this->m_size; i++) {
			this->m_arr[i] = mang.m_arr[i];
		}
	}
}