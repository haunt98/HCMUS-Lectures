#include "phanso.h"

int main()
{
	PhanSo *ps1 = PhanSo::tao(2, 3);
	PhanSo *ps2 = PhanSo::tao(3, 4);
	PhanSo *ps3 = PhanSo::tao(4, 5);
	delete ps1;
	delete ps2;
	delete ps3;
	return 0;
}
