#include "xuly.h"

int main()
{
	cout << "Mang dong" << endl;
	aStack aS;
	init_aStack(aS, MAX);
	rand_aStack(aS);
	// Them
	push_aStack(aS, 100);
	print_aStack(aS);
	// Lay va xoa
	int x;
	pop_aStack(aS, x);
	cout << "Pop : " << x << endl;
	peek_aStack(aS, x);
	cout << "Peek : " << x << endl;

	cout << "Danh sach" << endl;
	lStack lS;
	init_lStack(lS);
	rand_lStack(lS);
	// Them
	push_lStack(lS, 100);
	print_lStack(lS);
	// Lay va xoa
	pop_lStack(lS, x);
	cout << "Pop : " << x << endl;
	peek_lStack(lS, x);
	cout << "Peek : " << x << endl;
	return 0;
}