#include "xuly.h"

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5 };
	cout << "Tong cac so chan trong mang 1 chieu a : " << sumEvenArray(a, 0, 4) << endl;
	int b[][MAX] = {
		{ 1, 2, 3 },
		{ 3, 4, 5 }
	};
	cout << "Tong cac so chan trong mang 2 chieu b : " << sumEvenMatrix(b, 0, 1, 3) << endl;
	double c[] = { 1.1, 2.2, 3.3, 4.4 };
	cout << "Vi tri cua 2.2 trong mang c : " << find_X_array(c, 0, 3, 2.2) << endl;
	int d[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	cout << "Danh sach cac so nguyen to trong mang d : " << endl;
	Prime_in_Array(d, 0, 10);
	return 0;
}