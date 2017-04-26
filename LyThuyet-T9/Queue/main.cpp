#include "xuly.h"

int main()
{
	cout << "Mang dong" << endl;
	aQueue aQ;
	init_aQueue(aQ, MAX);
	rand_aQueue(aQ);
	// Them
	push_aQueue(aQ, 100);
	print_aQueue(aQ);
	// Lay ra
	int x;
	pop_aQueue(aQ, x);
	cout << "Pop : " << x << endl;
	peek_aQueue(aQ, x);
	cout << "Peek : " << x << endl;
	cout << endl;
	cout << "Danh sach" << endl;
	lQueue lQ;
	init_lQueue(lQ);
	rand_lQueue(lQ);
	// Them
	push_lQueue(lQ, 100);
	print_lQueue(lQ);
	// Lay ra
	pop_lQueue(lQ, x);
	cout << "Pop : " << x << endl;
	peek_aQueue(aQ, x);
	cout << "Peek : " << x << endl;
	return 0;
}