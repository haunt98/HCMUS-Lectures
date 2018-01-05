#ifndef MANG_H
#define MANG_H

#include <iostream>

using namespace std;

template <class T> class Mang
{
      private:
	T m_size;
	T *m_arr;

      public:
	Mang();
	~Mang();
	// gan = can tra ve vi tri (pass by reference)
	Mang &operator=(const Mang<T> &mg);
	// truy xuat phan tu, tra ve kieu T
	T &operator[](int i);
	// ep kieu tra ve con tro
	operator T *();
	// nhap xuat voi ham friend can mot template khac T
	template <class F> friend istream &operator>>(istream &in, Mang<F> &mg);
	template <class F>
	friend ostream &operator<<(ostream &out, const Mang<F> &mg);
};

template <class T> Mang<T>::Mang()
{
	m_size = 0;
	m_arr = NULL;
}

template <class T> Mang<T>::~Mang()
{
	m_size = 0;
	if (m_arr != NULL) {
		delete[] m_arr;
	}
}

// gan =
template <class T> Mang<T> &Mang<T>::operator=(const Mang<T> &mg)
{
	m_size = mg.m_size;
	if (m_arr != NULL)
		delete[] m_arr;
	m_arr = new T[m_size];
	for (int i = 0; i < m_size; i++) {
		m_arr[i] = mg.m_arr[i];
	}
	return *this;
}

template <class T> T &Mang<T>::operator[](int i)
{
	if (i < 0 || i >= m_size) {
		cout << "Error : i khong thuoc mang" << endl;
	}
	return m_arr[i];
}

// ep kieu
template <class T> Mang<T>::operator T *()
{
	return (T *)this;
}

// nhap xuat
template <class T> istream &operator>>(istream &in, Mang<T> &mg)
{
	in >> mg.m_size;
	if (mg.m_arr == NULL) {
		mg.m_arr = new T[mg.m_size];
		for (int i = 0; i < mg.m_size; i++) {
			in >> mg.m_arr[i];
		}
	}
	return in;
}

template <class T> ostream &operator<<(ostream &out, const Mang<T> &mg)
{
	out << "[" << mg.m_size << "] ";
	for (int i = 0; i < mg.m_size; i++) {
		out << mg.m_arr[i] << " ";
	}
	return out;
}

#endif
