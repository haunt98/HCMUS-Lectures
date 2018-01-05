#include "TaiKhoan.h"
#include <iostream>

using namespace std;

int main()
{
	TaiKhoan a;
	a.napTien(1000);
	a.rutTien(500);
	cout << a.baoSoDu() << endl;
	TaiKhoanTietKiem b;
	b.napTien(100);
	b.rutTien(20);
	cout << b.baoSoDu() << endl;
	return 0;
}
