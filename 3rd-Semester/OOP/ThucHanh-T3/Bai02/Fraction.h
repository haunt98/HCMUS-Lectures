#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class Fraction{
private:
	int m_tu, m_mau;
public:
	Fraction() :m_tu(0), m_mau(1){}
	Fraction(int tu, int mau);
	Fraction(const Fraction &ps);
	~Fraction(){}
	
	// so hoc
	Fraction &operator=(const Fraction &ps);
	Fraction operator+(const Fraction &ps) const;
	Fraction operator-(const Fraction &ps) const;
	Fraction operator*(const Fraction &ps) const;
	Fraction operator/(const Fraction &ps) const;
	Fraction &operator+=(const Fraction &ps);
	Fraction &operator-=(const Fraction &ps);
	Fraction &operator*=(const Fraction &ps);
	Fraction &operator/=(const Fraction &ps);

	// tien to hau to
	Fraction &operator++(); // prefix
	Fraction operator++(int); // postfix
	Fraction &operator--(); 
	Fraction operator--(int); 

	// so sanh
	bool operator==(const Fraction &ps);
	bool operator!=(const Fraction &ps);
	bool operator>=(const Fraction &ps);
	bool operator>(const Fraction &ps);
	bool operator<=(const Fraction &ps);
	bool operator<(const Fraction &ps);

	// qua tai
	friend Fraction operator+(const Fraction &ps, const int &m);
	friend Fraction operator+(const int &m, const Fraction &ps);
	friend Fraction operator*(const Fraction &ps, const int &m);
	friend Fraction operator*(const int &m, const Fraction &ps);
	friend Fraction operator-(const Fraction &ps, const int &m);

	// nhap xuat
	friend istream &operator>>(istream &in, Fraction &ps);
	friend ostream &operator<<(ostream &out, const Fraction &ps);

	// ep kieu
	operator float();
	
};

#endif