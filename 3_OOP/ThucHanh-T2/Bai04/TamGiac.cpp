#include "TamGiac.h"
#include <iostream>

using namespace std;

TamGiac::TamGiac()
{
	this->m_dinh[0] = Diem(0, 0);
	this->m_dinh[1] = Diem(1, 0);
	this->m_dinh[2] = Diem(0, 1);
}

TamGiac::TamGiac(Diem A, Diem B, Diem C)
{
	this->m_dinh[0] = A;
	this->m_dinh[1] = B;
	this->m_dinh[2] = C;
}

TamGiac::TamGiac(int A_x, int A_y, int B_x, int B_y, int C_x, int C_y)
{
	this->m_dinh[0] = Diem(A_x, A_y);
	this->m_dinh[1] = Diem(B_x, B_y);
	this->m_dinh[2] = Diem(C_x, C_y);
}

TamGiac::TamGiac(const TamGiac &tg)
{
	for (int i = 0; i < 3; i++) {
		this->m_dinh[i] = tg.m_dinh[i];
	}
}

void TamGiac::Xuat()
{
	for (int i = 0; i < 3; i++) {
		this->m_dinh[i].Xuat();
	}
	cout << endl;
}

TamGiac::~TamGiac()
{
}
