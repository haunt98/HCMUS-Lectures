#include "IntArray.h"

IntArray::IntArray(int size)
{
	m_size = size >= 0 ? size : 0;

	delete[] m_arr;
	m_arr = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_arr[i] = 0;
	}
}

IntArray::IntArray(int *arr, const int &size)
{
	m_size = size >= 0 ? size : 0;

	delete[] m_arr;
	m_arr = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_arr[i] = arr[i];
	}
}

IntArray::IntArray(const IntArray &mang)
{
	m_size = mang.m_size;

	delete[] m_arr;
	m_arr = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_arr[i] = mang.m_arr[i];
	}
}

IntArray::~IntArray()
{
	m_size = 0;
	delete[] m_arr;
}

// toan tu
IntArray &IntArray::operator=(const IntArray &mang)
{
	m_size = mang.m_size;

	delete[] m_arr;
	m_arr = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_arr[i] = mang.m_arr[i];
	}
	return (*this);
}

int &IntArray::operator[](int i)
{
	if (i < 0 || i >= m_size)
		cout << "chi so i khong thuoc mang" << endl;
	return m_arr[i];
}

IntArray::operator int()
{
	return m_size;
}

// nhap xuat
istream &operator>>(istream &in, IntArray &mang)
{
	do {
		in >> mang.m_size;
	} while (mang.m_size < 0);

	delete[] mang.m_arr;
	mang.m_arr = new int[mang.m_size];
	for (int i = 0; i < mang.m_size; i++) {
		in >> mang.m_arr[i];
	}
	return in;
}

ostream &operator<<(ostream &out, const IntArray &mang)
{
	out << "[" << mang.m_size << "] ";
	for (int i = 0; i < mang.m_size; i++) {
		out << mang.m_arr[i] << " ";
	}
	out << endl;
	return out;
}