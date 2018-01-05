// 1612180
// Nguyen Tran Hau
// Bai 2

#include "BenhVien.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	BenhVien a;
	a.doc("log.txt");
	a.outMoney();
	cout << "Ngoai tru: " << a.slNgoaiTru() << ", Noi tru: " << a.slNoiTru()
	     << endl;
	return 0;
}