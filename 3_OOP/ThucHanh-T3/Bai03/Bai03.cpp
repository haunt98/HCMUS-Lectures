// 1612180
// Nguyen Tran Hau
// Bai 3 mang so nguyen

#include "IntArray.h"

int main()
{
	// Using dynamic allocated array
	IntArray m1;
	IntArray m2(7);
	int a[100];
	int n = 8;
	for (int i = 0; i < n; i++) {
		a[i] = i * 2 / 7;
	}
	IntArray m3(a, n);
	IntArray m4(m2);
	IntArray m5;
	m5 = m2;
	cin >> m2;
	cout << m2;
	cout << m3[7] << endl;
	m3[7] = 1;
	cout << (int)m4 << endl;
	return 0;
}