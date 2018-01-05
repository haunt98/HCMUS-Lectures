#include "RapCaoCap.h"
#include "RapThuong.h"
#include <iostream>

using namespace std;

float RapThuong::VE_GIAM = 3000;
float RapThuong::VE_THUONG_TT = 80000;
float RapCaoCap::VE_VIP_TT = 120000;

int main()
{
	RapThuong a(3, 3);
	cout << a.datVe(ViTri{1, 1}) << endl;
	cout << a.datVe(ViTri{1, 1}) << endl;
	cout << a.datVe(ViTri{0, 1}) << endl;
	cout << a.tongTien(RapThuong::VE_THUONG_TT) << endl;

	RapCaoCap b(3, 3, nam);
	cout << b.conTrong(ViTri{1, 1}) << endl;
	cout << b.datVe(ViTri{1, 1}) << endl;
	cout << b.datVe(ViTri{1, 1}) << endl;
	b.datVe(ViTri{0, 2});
	cout << b.tongTien(RapCaoCap::VE_VIP_TT) << endl;

	return 0;
}
