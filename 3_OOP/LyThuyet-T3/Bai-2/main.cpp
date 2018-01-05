#include "hocsinh.h"
#include <iostream>

using namespace std;

int main()
{
	char ten1[] = "tran hau";
	HocSinh hs1(ten1, 8, 8);
	hs1.xuat();
	char ten2[] = "quoc khanh";
	HocSinh hs2(ten2);
	hs2.xuat();
	return 0;
}
