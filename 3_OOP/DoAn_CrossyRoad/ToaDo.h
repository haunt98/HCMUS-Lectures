#ifndef TOADO_H
#define TOADO_H

#include <Windows.h>
#include <fstream>
#include <iostream>

using namespace std;

struct ToaDo {
	int X, Y;

	ToaDo();
	ToaDo(int x, int y);
	ToaDo(const ToaDo &);

	// Operator
	ToaDo &operator=(const ToaDo &);
	ToaDo operator+(const ToaDo &) const;
	ToaDo &operator+=(const ToaDo &);
	ToaDo operator-(const ToaDo &) const;
	ToaDo &operator-=(const ToaDo &);
	bool operator==(const ToaDo &) const;
	bool operator!=(const ToaDo &) const;

	// Action
	void GotoXY();
	void Draw(int ch);

	// Move
	ToaDo Up();
	ToaDo Down();
	ToaDo Left();
	ToaDo Right();

	// I/O
	friend ostream &operator<<(ostream &out, const ToaDo &);
	friend istream &operator>>(istream &in, ToaDo &);
	friend ofstream &operator<<(ofstream &out, const ToaDo &);
	friend ifstream &operator>>(ifstream &in, ToaDo &);
};

#endif