#ifndef MANG_H
#define MANG_H

#include <iostream>

using namespace std;

template <class T> class Mang
{
      private:
	T *m_arr;
	int m_size;

      public:
	Mang();
	Mang(int size);
	Mang(T *arr, int size);
	Mang(const Mang<T> &other);
	~Mang();
	void xuat(); // de test
};

template <class T> Mang<T>::Mang()
{
	this->m_size = 0;
	this->m_arr = NULL;
}

template <class T> Mang<T>::Mang(int size)
{
	this->m_size = size;
	this->m_arr = new T[size];
	for (int i = 0; i < size; i++) {
		this->m_arr[i] = 0;
	}
}

template <class T> Mang<T>::Mang(T *arr, int size)
{
	this->m_size = size;
	this->m_arr = new T[size];
	for (int i = 0; i < size; i++) {
		this->m_arr[i] = arr[i];
	}
}

template <class T> Mang<T>::Mang(const Mang<T> &other)
{
	this->m_size = other.m_size;
	this->m_arr = new T[this->m_size];
	for (int i = 0; i < this->m_size; i++) {
		this->m_arr[i] = other.m_arr[i];
	}
}

template <class T> Mang<T>::~Mang()
{
	delete[] this->m_arr;
}

template <class T> void Mang<T>::xuat()
{
	for (int i = 0; i < this->m_size; i++) {
		cout << this->m_arr[i] << " ";
	}
	cout << endl;
}

#endif
