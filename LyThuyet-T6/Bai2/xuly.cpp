#include "xuly.h"

// Tong cac so chan trong mang
int sumEvenArray(int *a, int left, int right)
{
	if (left == right)
		return a[left] % 2 == 0 ? a[left] : 0;
	int mid = (left + right) / 2;
	int Even_1 = sumEvenArray(a, left, mid);
	int Even_2 = sumEvenArray(a, mid + 1, right);
	return Even_1 + Even_2;
}

// Tong cac so chan trong ma tran;
int sumEvenMatrix(int a[][MAX], int first_row, int last_row, int column)
{
	if (first_row == last_row)
		return sumEvenArray(a[first_row], 0, column - 1);
	int mid_row = (first_row + last_row) / 2;
	int Even_1 = sumEvenMatrix(a, first_row, mid_row, column);
	int Even_2 = sumEvenMatrix(a, mid_row + 1, last_row, column);
	return Even_1 + Even_2;
}

// Tim x trong mang a, tra ve vi tri cua x
// Tra ve -1 neu khong co
int find_X_array(double *a, int left, int right, double x)
{
	if (left == right)
		return a[left] == x ? left : -1;
	int mid = (left + right) / 2;
	int pos_X_1 = find_X_array(a, left, mid, x);
	int pos_X_2 = find_X_array(a, mid + 1, right, x);
	return pos_X_1 > pos_X_2 ? pos_X_1 : pos_X_2;
	// Tra ve so lon hon vi so nho hon co the = -1
}

bool isPrime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i*i <= x; ++i)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}

// Trich ra cac so nguyen to trong mang
void Prime_in_Array(int *a, int left, int right)
{
	if (left == right)
	{
		if (isPrime(a[left]))
			cout << a[left] << endl;
		return;
	}
	int mid = (left + right) / 2;
	Prime_in_Array(a, left, mid);
	Prime_in_Array(a, mid + 1, right);
	return;
}