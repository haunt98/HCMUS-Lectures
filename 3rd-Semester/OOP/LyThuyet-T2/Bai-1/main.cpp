#include "phanso.h"

using namespace std;

int main() {
	PhanSo a;
	a.nhap();

	PhanSo b;
	b.nhap();

	if (a.sosanh(b) > 0)
		cout << ">" << endl;
	else if (a.sosanh(b) == 0)
		cout << "=" << endl;
	else
		cout << "<" << endl;
	return 0;
}