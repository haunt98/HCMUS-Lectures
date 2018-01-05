// 1612180
// Nguyen Tran Hau
// Bai 2

#include "KhachHang.h"
#include <iostream>

using namespace std;

float GoiCuocBasic::MONEY_PER_MINUTE = 1;
float GoiCuocBasic::MONEY_PER_MB = 0.2;

int main()
{
	KhachHang a;
	a.DangKy(&GoiCuocBasic(10, 15));
	cout << a.TienCuoc() << "k" << endl;

	KhachHang b;
	b.DangKy(&GoiCuocDataFree(10, 15, 20, 10.0));
	cout << b.TienCuoc() << "k" << endl;

	KhachHang c;
	c.DangKy(&GoiCuocDataFix(10, 15));
	cout << c.TienCuoc() << "k" << endl;

	return 0;
}