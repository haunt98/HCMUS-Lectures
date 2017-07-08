#include "ham.h"

void nhap_x_n(float &x, int &n)
{
	printf("Nhap x: ");
	scanf_s("%f", &x);
	printf("Nhap n: ");
	scanf_s("%d", &n);
}

void Bai8(int N, int M)
{
	for (int i = 0; i < M; ++i)
	{
		printf("%d\n", N & 1);
		N = N >> 1;
	}
}

float Bai17(float x, int n)
{
	float S = 0;
	float tam = 1;
	for (int i = 0; i < n; ++i)
	{
		tam = tam*x / (i + 1);
		S += tam;
	}
	return S;
}

float Bai18(float x, int n)
{
	float S = 1;
	float tam = 1;
	for (int i = 0; i < n; ++i)
	{
		tam = tam*x*x / ((2 * i + 1)*(2 * i + 2));
		S += tam;
	}
	return S;
}

float Bai19(float x, int n)
{
	float S;
	float tam;
	tam = x;
	S = 1 + x;
	for (int i = 0; i < n; ++i)
	{
		tam = tam*x*x / ((2 * i + 2)*(2 * i + 3));
		S += tam;
	}
	return S;
}

int Bai29_uoc(int n)
{
	int uoc_le;
	for (int i = 1; i <= n; ++i)
	{
		if (n%i == 0 && i % 2 != 0)
			uoc_le = i;
	}
	return uoc_le;
}

void Bai30_hoanthien(int n)
{
	int tong_uoc = 0;
	for (int i = 1; i < n; ++i)
	{
		if (n%i == 0)
			tong_uoc += i;
	}
	if (tong_uoc == n)
		printf("n la so hoan thien\n");
	else
		printf("n khong phai la so hoan thien\n");
}

void Bai31_ngto(int n)
{
	int state;
	state = 1;
	if (n == 1)
		state = 0;
	for (int i = 2; i <= sqrt((double)n); ++i)
	{
		if (n%i == 0)
		{
			state = 0;
			break;
		}
	}
	if (state == 1)
		printf("%d la so nguyen to\n", n);
	else
		printf("%d khong phai la so nguyen to\n", n);
}

void Bai32_chphuong(int n)
{
	int state;
	state = 0;
	for (int i = 0; i <= n / 2 + 1; ++i)
	{
		if (i*i == n)
		{
			state = 1;
			break;
		}
	}
	if (state == 0)
		printf("%d khong phai la so chinh phuong\n", n);
	else
		printf("%d la so chinh phuong\n", n);
}

float Bai39(int n)
{
	int giai_thua;
	float S;
	S = 0;
	giai_thua = 1;
	for (int i = 1; i <= n; ++i)
	{
		giai_thua = giai_thua * i;
		S = pow(S + giai_thua, (float)1 / (i + 1));
	}
	return S;
}

float Bai40(float x, int n)
{
	float S, tam;
	S = 0;
	tam = 1;
	for (int i = 0; i < n; ++i)
	{
		tam *= x;
		S = sqrt(S + tam);
	}
	return S;
}

float Bai41(int n)
{
	float S;
	S = 2;
	for (int i = 0; i < n; ++i)
	{
		S = 1 + 1.0 / S;
	}
	S = S - 1;
	return S;
}

int Bai42(int n)
{
	int k;
	k = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i*(i + 1) / 2 < n)
			k = i;
	}
	return k;
}

int Bai51(int n)
{
	int max_chu_so;
	max_chu_so = n % 10;
	for (int i = 0; n > 0; ++i)
	{
		n = n / 10;
		if (n % 10 > max_chu_so)
			max_chu_so = n % 10;
	}
	return max_chu_so;
}

int Bai53(int n)
{
	int n_tam, dem, max_chu_so;
	n_tam = n;
	max_chu_so = n_tam % 10;
	for (int i = 0; n_tam > 0; ++i)
	{
		n_tam = n_tam / 10;
		if (n_tam % 10 > max_chu_so)
			max_chu_so = n_tam % 10;
	}
	dem = 0;
	n_tam = n;
	for (int i = 0; n_tam > 0; ++i)
	{
		if (n_tam % 10 == max_chu_so)
			++dem;
		n_tam = n_tam / 10;
	}
	return dem;
}

int Bai55(int n)
{
	int n_tam, dem, chu_so_dau_tien;
	n_tam = n;
	while (n_tam > 0)
	{
		chu_so_dau_tien = n_tam % 10;
		n_tam = n_tam / 10;
	}
	n_tam = n;
	dem = 0;
	for (int i = 0; n_tam > 0; ++i)
	{
		if (n_tam % 10 == chu_so_dau_tien)
			++dem;
		n_tam = n_tam / 10;
	}
	return dem;
}

void Bai57(int n)
{
	int n_tam, state;
	state = 1;
	n_tam = n;
	for (int i = 0; n_tam > 0; ++i)
	{
		if ((n_tam % 10) % 2 != 0)
		{
			state = 0;
			break;
		}
		n_tam = n_tam / 10;
	}
	if (state == 1)
		printf("%d chua toan chu so chan\n", n);
	else
		printf("%d khong chua toan chu so chan\n", n);
}

void Bai59(int n)
{
	int n_tam, n_nguoc;
	n_tam = n;
	n_nguoc = 0;
	for (int i = 0; n_tam > 0; ++i)
	{
		n_nguoc = n_nguoc * 10 + n_tam % 10;
		n_tam = n_tam / 10;
	}
	if (n_nguoc == n)
		printf("%d la so doi xung\n", n);
	else
		printf("%d khong phai la so doi xung\n", n);
}

void Bai61(int n)
{
	int n_tam, state;
	state = 1;
	n_tam = n;
	for (int i = 0; n_tam > 9; ++i)
	{
		if (n_tam % 10 >= (n_tam / 10) % 10)
		{
			state = 0;
			break;
		}
		n_tam = n_tam / 10;
	}
	if (state == 1)
		printf("Cac chu so cua %d giam dan tu trai qua phai\n", n);
	else
		printf("Cac chu so cua %d khong giam dan tu trai qua phai\n", n);
}

int Bai62_uoc(int a, int b)
{
	while (a > 0 && b>0)
	{
		if (a >= b)
			a = a - b;
		else
			b = b - a;
	}
	if (a == 0)
		return b;
	else
		return a;
}

int Bai63_boi(int a, int b)
{
	int bcnn;
	for (int i = 1; i <= b; ++i)
	{
		if ((a*i) % b == 0)
		{
			bcnn = a*i;
			break;
		}
	}
	return bcnn;
}

float Bai67(float x, int n)
{
	float tam, S;
	S = 0;
	tam = -1;
	for (int i = 0; i < n; ++i)
	{
		tam = tam*x*(-1);
		S += tam;
	}
	return S;
}

float Bai69(float x, int n)
{
	float tam, S;
	S = 0;
	tam = -1 / x;
	for (int i = 0; i < n + 1; ++i)
	{
		tam = tam*x*x*(-1);
		S += tam;
	}
	return S;
}

float Bai71(float x, int n)
{
	float S = 0;
	float tam_x = 1;
	float tam_tong = 0;

	for (int i = 0; i < n; ++i)
	{
		tam_x = tam_x*x*(-1);
		tam_tong += (i + 1);
		S = S + tam_x / tam_tong;
	}
	return S;
}

float Bai73(float x, int n)
{
	float S = -1;
	float x_tam, giaithua_tam;
	x_tam = -1;
	giaithua_tam = 1;
	for (int i = 0; i < n; ++i)
	{
		x_tam = x_tam*x*x*(-1);
		giaithua_tam = giaithua_tam*(2 * i + 1)*(2 * i + 2);
		S = S + x_tam / giaithua_tam;
	}
	return S;
}

void Bai75(int n)
{
	int flag;

	flag = 1;
	int n_tam = n;
	while (n_tam > 0)
	{
		if (n_tam % 2 == 0)
			n_tam = n_tam / 2;
		else if (n_tam == 1)
			break;
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		printf("%d co dang 2^k\n", n);
	else
		printf("%d khong co dang 2^k\n", n);
}

void Bai76(int n)
{
	int flag;

	flag = 1;
	int n_tam = n;
	while (n_tam > 0)
	{
		if (n_tam % 3 == 0)
			n_tam = n_tam / 3;
		else if (n_tam == 1)
			break;
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		printf("%d co dang 3^k\n", n);
	else
		printf("%d khong co dang 3^k\n", n);
}