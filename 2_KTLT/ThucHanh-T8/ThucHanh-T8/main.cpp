#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
using namespace std;

typedef bool (*intCondition)(int, int);
void intSwap(int *, int *);
void intSort(int *, int, intCondition);
void printIntArr(int *, int);

bool giam_dan(int, int);
bool chan_giam_dan(int, int);
bool laNguyenTo(int);
bool NguyenTo_tang_dan(int, int);
bool chan_trai_tang_le_phai_giam(int, int);

typedef bool (*realCondition)(float, float);
void realSwap(float *, float *);
void realSort(float *, int, realCondition);
void printRealArr(float *, int);

bool am_tang_duong_giam(float, float);
bool lon_hon_trai(float, float);

int main()
{
	int arr[] = {11, -6, 97, 23, 3, -4, 7, -9, 12, 20, 9};
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Day so nguyen : ";
	printIntArr(arr, size);

	float arr2[] = {1.1, 2.2, -3.3, 4.4, -5.5, 7.7, -100, 10};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	cout << "Day so thuc : ";
	printRealArr(arr2, size2);

	int i;
	cout << "Chon 1-so nguyen 2-so thuc : ";
	cin >> i;
	if (i == 1) {
		cout << "Chon 1-giam dan\n     2-so chan giam dan\n     3-so "
			"nguyen to tang dan\n     4-chan trai tang, le phai "
			"giam"
		     << endl;
		cin >> i;
		switch (i) {
		case 1:
			intSort(arr, size, giam_dan);
			printIntArr(arr, size);
			break;
		case 2:
			intSort(arr, size, chan_giam_dan);
			printIntArr(arr, size);
			break;
		case 3:
			intSort(arr, size, NguyenTo_tang_dan);
			printIntArr(arr, size);
			break;
		case 4:
			intSort(arr, size, chan_trai_tang_le_phai_giam);
			printIntArr(arr, size);
			break;
		default:
			break;
		}
	}
	if (i == 2) {
		cout << "Chon 1-am tang duong giam\n     2-lon hon so ben trai"
		     << endl;
		cin >> i;
		switch (i) {
		case 1:
			realSort(arr2, size2, am_tang_duong_giam);
			printRealArr(arr2, size2);
			break;
		case 2:
			realSort(arr2, size2, lon_hon_trai);
			printRealArr(arr2, size2);
			break;
		default:
			break;
		}
	}

	return 0;
}

void intSwap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void intSort(int *arr, int size, intCondition T)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (!T(arr[i], arr[j]))
				intSwap(&arr[i], &arr[j]);
		}
	}
}
void printIntArr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool giam_dan(int x, int y)
{
	return x > y;
}
bool chan_giam_dan(int x, int y)
{
	if (x % 2 == 0 && y % 2 == 0)
		return x > y;
	return true;
}
bool laNguyenTo(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
bool NguyenTo_tang_dan(int x, int y)
{
	if (laNguyenTo(x) && laNguyenTo(y))
		return x < y;
	return true;
}
bool chan_trai_tang_le_phai_giam(int x, int y)
{
	if (x % 2 == 0 && y % 2 == 0)
		return x < y;
	if (x % 2 != 0 && y % 2 != 0)
		return x > y;
	if (x % 2 != 0 && y % 2 == 0)
		return false;
	return true;
}

void realSwap(float *x, float *y)
{
	float temp = *x;
	*x = *y;
	*y = temp;
}
void realSort(float *arr, int size, realCondition T)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (!T(arr[i], arr[j]))
				realSwap(&arr[i], &arr[j]);
		}
	}
}
void printRealArr(float *arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << fixed << setprecision(2) << arr[i] << " ";
	}
	cout << endl;
}

bool am_tang_duong_giam(float x, float y)
{
	if (x < 0 && y < 0)
		return x < y;
	if (x > 0 && y > 0)
		return x > y;
	return true;
}
bool lon_hon_trai(float x, float y)
{
	return x < y;
}
