#include "Xe.h"
#include <iostream>

using namespace std;

int main(void)
{
	XeMay a;
	a.themHang(10);
	a.themXang(200);
	a.chay(100);
	cout << a.xang() << endl;
	XeTai b;
	b.themHang(1000);
	b.themXang(100);
	b.chay(1000);
	cout << b.hetXang() << endl;
	cout << b.xang() << endl;
	return 0;
}
