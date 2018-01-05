#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t1_gio, t1_phut, t1_giay, t2_gio, t2_phut, t2_giay, tg_t1, tg_t2,
	    khoang_cach;

	printf("Nhap t1 theo thu tu gio phut giay\n");
	scanf("%d %d %d", &t1_gio, &t1_phut, &t1_giay);
	printf("Nhap t2 theo thu tu gio phut giay\n");
	scanf("%d %d %d", &t2_gio, &t2_phut, &t2_giay);

	tg_t1 = t1_gio * 3600 + t1_phut * 60 + t1_giay;
	tg_t2 = t2_gio * 3600 + t2_phut * 60 + t2_giay;
	khoang_cach = abs(tg_t1 - tg_t2);
	printf("Khoang cach thoi gian giua T1 va T2: %d\n", khoang_cach);
	return 0;
}