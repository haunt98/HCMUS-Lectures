#include "xuly.h"

void nhap_ngay_thang_nam(int &ngay, int &thang, int &nam, int &flag_nam_nhuan)
{
	printf("Nhap ngay thang nam: ");
	scanf("%d %d %d", &ngay, &thang, &nam);
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		flag_nam_nhuan = 1;
	else
		flag_nam_nhuan = 0;
}

int so_thu_tu_ngay(int ngay, int thang, int nam, int flag_nam_nhuan)
{
	int nam_khong_nhuan[12] = {31, 28, 31, 30, 31, 30,
				   31, 31, 30, 31, 30, 31};
	int nam_nhuan[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int result = ngay;
	if (flag_nam_nhuan == 1)
		for (int i = 0; i < thang - 1; ++i)
			result += nam_nhuan[i];
	else
		for (int i = 0; i < thang - 1; ++i)
			result += nam_khong_nhuan[i];
	return result;
}

void doi_ra_ngay(int so_thu_tu, int nam, int flag_nam_nhuan)
{
	int thu, ngay, thang, sum;
	int nam_khong_nhuan[12] = {31, 28, 31, 30, 31, 30,
				   31, 31, 30, 31, 30, 31};
	int nam_nhuan[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	sum = 0;
	if (flag_nam_nhuan == 1) {
		for (thang = 0; thang < 12; ++thang) {
			sum += nam_nhuan[thang];
			if (sum < so_thu_tu &&
			    sum + nam_nhuan[thang + 1] > so_thu_tu)
				break;
		}
	} else {
		for (thang = 0; thang < 12; ++thang) {
			sum += nam_khong_nhuan[thang];
			if (sum < so_thu_tu &&
			    sum + nam_nhuan[thang + 1] > so_thu_tu)
				break;
		}
	}
	thang = thang + 2;
	ngay = so_thu_tu - sum;
	thu = ((so_thu_tu - 1) % 7 + 6) % 7;
	printf("Nhiet do cao nhat: Thu: %d Ngay: %d Thang: %d Nam: %d\n", thu,
	       ngay, thang, nam);
}

void nhap_nhiet_do(int so_thutu, float arr[], int len)
{
	int so_ngay_lien_tiep, i;
	printf("Nhap so ngay lien tiep: ");
	scanf("%d", &so_ngay_lien_tiep);
	for (i = so_thutu - 1; i < so_thutu - 1 + so_ngay_lien_tiep; ++i) {
		printf("Nhap nhiet do: ");
		scanf("%f", &arr[i]);
	}
}

int cs_max_mang(float arr[], int len)
{
	int cs_max = 0;
	for (int i = 1; i < len; ++i)
		if (arr[i] > arr[cs_max])
			cs_max = i;
	return cs_max;
}

void xuat_mang(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}