#include "xuly.h"

int main(void)
{
	int n;
	cout << "Nhap n : ";
	cin >> n;
	cout << "S(n) = 1 x 2 x .. x n" << endl;
	cout << "S(" << n << ") = " << giai_thua(n) << "\n\n";

	cout << "S2(n) = 1 + (1 / 3) + (1 / 5) + .. + 1 / (2n + 1)" << endl;
	cout << "S2(" << n << ") = " << tinh_S2(n) << "\n\n";

	cout << "S3(n) = (1/2) + (3/4) + .. + ((2n+1)/(2n+2))" << endl;
	cout << "S3(" << n << ") = " << tinh_S3(n) << "\n\n";

	double x;
	cout << "Nhap x : ";
	cin >> x;
	cout << "S4(n,x) =  x + x^2 + x^3 + .. + x^n" << endl;
	cout << "S4(" << n << "," << x << ") = " << tinh_S4(n, x) << "\n\n";

	cout << "S5(n,x) = x + (x2/ (1 + 2)) + (x3/ (1 + 2 + 3)) + .. + (xn/ "
		"(1 + 2 + .. + n))"
	     << endl;
	cout << "S5(" << n << "," << x << ") = " << tinh_S5(n, x) << "\n\n";

	int a[MAX];
	inputArray(a, n);
	cout << "So luong so nguyen to co trong mang : "
	     << countPrime(a, 0, n - 1) << endl;
	cout << "So luong so hoan thien co trong mang : "
	     << countPerfect(a, 0, n - 1) << endl;
	cout << "Tong cac so chan : " << sumEven(a, 0, n - 1) << endl;
	cout << "Vi tri cac so nguyen to co trong mang : ";
	outputPrimePos(a, 0, n - 1);
	cout << endl;
	cout << "Vi tri cac so chan co trong mang : ";
	outputEvenPos(a, 0, n - 1);
	cout << endl;
	cout << "Tong cac so lon hon so lien truoc trong mang : "
	     << sumBigger(a, 0, n - 1) << endl;
	cout << "So luong gia tri phan biet cua mang : " << countDiffe(a, n)
	     << endl;
	return 0;
}