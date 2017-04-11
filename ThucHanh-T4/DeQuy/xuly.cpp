#include "xuly.h"
int giai_thua(int n)
{
	if (n == 0)
		return 1;
	return n*giai_thua(n - 1);
}

double tinh_S2(int n)
{
	if (n == 0)
		return 1;
	return (double)1 / (2 * n + 1) + tinh_S2(n - 1);
}

double tinh_S3(int n)
{
	if (n == 0)
		return 1 / 2;
	return (double)(2 * n + 1) / (2 * n + 2) + tinh_S3(n - 1);
}

double tinh_S4(int n, double x)
{
	if (n == 1)
		return x;
	return x + x*tinh_S4(n - 1, x);
}

double tinh_S5(int n, double x)
{
	if (n == 1)
		return x;
	return x_mu_n(n, x) / (n*(n + 1) / 2) + tinh_S5(n - 1, x);
}

double x_mu_n(int n, double x)
{
	if (n == 0)
		return 1;
	return x*(x_mu_n(n - 1, x));
}

int countPrime(int *a, int left, int right)
{
	if (left == right)
	{
		if (isPrime(a[left]))
			return 1;
		return 0;
	}
	int mid = (left + right) / 2;
	int count_left = countPrime(a, left, mid);
	int count_right = countPrime(a, mid + 1, right);
	return count_left + count_right;
}

bool isPrime(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i*i <= n; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

void inputArray(int *a, int &n)
{
	cout << "Nhap so luong mang : ";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
}

int countPerfect(int *a, int left, int right)
{
	if (left == right)
	{
		if (isPerfect(a[left]))
			return 1;
		return 0;
	}
	int mid = (left + right) / 2;
	int count_left = countPerfect(a, left, mid);
	int count_right = countPerfect(a, mid + 1, right);
	return count_left + count_right;
}

bool isPerfect(int n)
{
	int temp = 0;
	for (int i = 1; i < n; ++i)
	{
		if (n%i == 0)
			temp += i;
	}
	return temp == n ? true : false;
}

int sumEven(int *a, int left, int right)
{
	if (left == right)
	{
		if (a[left] % 2 == 0)
			return a[left];
		return 0;
	}
	int mid = (left + right) / 2;
	int sum_left = sumEven(a, left, mid);
	int sum_right = sumEven(a, mid + 1, right);
	return sum_left + sum_right;
}

void outputPrimePos(int *a, int left, int right)
{
	if (left == right)
	{
		if (isPrime(a[left]))
			cout << left << " ";
		return;
	}
	int mid = (left + right) / 2;
	outputPrimePos(a, left, mid);
	outputPrimePos(a, mid + 1, right);
}

void outputEvenPos(int *a, int left, int right)
{
	if (left == right)
	{
		if (a[left] % 2 == 0)
			cout << left << " ";
		return;
	}
	int mid = (left + right) / 2;
	outputEvenPos(a, left, mid);
	outputEvenPos(a, mid + 1, right);
}

int sumBigger(int *a, int left, int right)
{
	if (left == right)
	{
		if (left > 0)
		{
			if (a[left] > a[left - 1])
				return a[left];
		}
		return 0;
	}
	int mid = (left + right) / 2;
	int sum_left = sumBigger(a, left, mid);
	int sum_right = sumBigger(a, mid + 1, right);
	return sum_left + sum_right;
}

int countDiffe(int *a, int size)
{
	if (size == 1)
		return 1;
	int temp = !appearArray(a, 1, size - 1, a[0]); // la 1:  so khong lap lai;
	return temp + countDiffe(a + 1, size - 1);
}

int appearArray(int *a, int left, int right, int x)
{
	if (left == right)
	{
		if (a[left] == x)
			return YES;
		return NO;
	}
	int mid = (left + right) / 2;
	int temp_1 = appearArray(a, left, mid, x);
	int temp_2 = appearArray(a, mid + 1, right, x);
	return temp_1 > temp_2 ? temp_1 : temp_2;
}