#include "SoPhuc.h"
#include <iostream>

using namespace std;

SoPhuc::SoPhuc()
{
	this->m_thuc = 0;
	this->m_ao = 0;
}

SoPhuc::SoPhuc(int thuc)
{
	this->m_thuc = thuc;
	this->m_ao = 0;
}

SoPhuc::SoPhuc(int thuc, int ao)
{
	this->m_thuc = thuc;
	this->m_ao = ao;
}

SoPhuc::SoPhuc(const SoPhuc &p)
{
	this->m_thuc = p.m_thuc;
	this->m_ao = p.m_ao;
}

void SoPhuc::Xuat()
{
	cout << this->m_thuc << " + " << this->m_ao << "i" << endl;
}

//SoPhuc::~SoPhuc(){}