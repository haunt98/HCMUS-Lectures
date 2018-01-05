#include <iostream>

using namespace std;

// Bai 1: Kiem tra chuoi co bat dau aa ket thuc bb
bool isAABB(const char *);

// Bai 2: Co ton tai DFA kiem dinh chuoi aa..abb..b
// so lan a xuat hien = so lan b xuat hien?
// Cau tra loi la khong the
// Neu gioi han chuoi co huu han cho truoc 2n ki tu,
// vi du nhu co 4 ky tu,
// ta co the thiet ke DFA voi 5 nodes
// Con chuoi da cho la chuoi bat ki, khong biet do dai,
// thi ta khong the thiet ke vi DFA khong the biet so luong ki tu da dem

int main()
{
	cout << isAABB("aaababbb") << endl;
	return 0;
}

bool isAABB(const char *P) // P la Pattern
{
	// cot: a b
	// hang: state -1 0 1 2 3 4
	// table[state i][char j] la state tiep theo
	// -1 la state bi loai
	const int table[5][2] = {{1, -1}, {2, -1}, {2, 3}, {2, 4}, {2, 4}};
	int state = 0; // state dau tien la 0
	for (int i = 0; P[i] != '\0'; ++i) {
		state = table[state][P[i] - 'a'];
		if (state == -1)
			return false;
	}
	if (state == 4)
		return true;
	return false;
}
