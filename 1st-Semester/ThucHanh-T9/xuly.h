#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

enum g_tinh
{
	nam,
	nu
};

struct n_sinh
{
	int ngay;
	int thang;
	int nam;
};

enum n_tuoi
{
	than,
	dau,
	tuat,
	hoi,
	ti,
	suu,
	dan,
	meo,
	thin,
	ty,
	ngo,
	mui,
};

struct tt_sinh_vien
{
	int MSSV;
	char ho[20];
	char ten_lot[20];
	char ten[20];
	int CMND;
	n_sinh ngay_sinh;
	int gioi_tinh;
	char dia_chi[MAX];
	float dtb;
	char email[MAX];
	int nam_tuoi;
};

int so_sanh(char s[], char t[]);

void nhap_sv(tt_sinh_vien &sv); 

void xuat_sv(tt_sinh_vien sv);

void sv_cao(tt_sinh_vien sv[], int sl); // Bai 3

void lke_tb(tt_sinh_vien sv[], int sl); // Bai 4

void lke_xl(tt_sinh_vien sv[], int sl); // Bai 5

void nhap_ds_sv(tt_sinh_vien sv[], int &sl); // Bai 1

void xuat_ds_sv(tt_sinh_vien sv[], int sl); // Bai 2

void xoa_e_trung(tt_sinh_vien sv[], int sl);

void f_nhap_sv(FILE *f, tt_sinh_vien &sv);

void f_xuat_sv(FILE *f, tt_sinh_vien sv);

void f_nhap_sv_ds(FILE *f, tt_sinh_vien sv[], int &sl); // Bai 28

void f_xuat_sv_ds(FILE *f, tt_sinh_vien sv[], int sl); // Bai 29

void tim_ms(tt_sinh_vien sv[], int sl); // Bai 7

void lke_nu(tt_sinh_vien sv[], int sl); // Bai 11

void lke_nam(tt_sinh_vien sv[], int sl); // Bai 12

void them_sv(tt_sinh_vien sv[], int &sl); // Bai 9 

void xoa_sv(tt_sinh_vien sv[], int &sl); // Bai 10

void tim_sua(tt_sinh_vien sv[], int sl); // Bai 13

void sv_lon(tt_sinh_vien sv[], int sl); // Bai 18