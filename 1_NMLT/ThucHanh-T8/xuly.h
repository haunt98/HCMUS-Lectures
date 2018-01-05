#include <stdio.h>
#define MAX 100
#define LEFT 1
#define RIGHT 2

void nhap_mang(int arr[MAX][MAX], int &hang, int &cot);

void xuat_mang(int arr[MAX][MAX], int hang, int cot);

int tong(int arr[MAX][MAX], int hang, int cot); // Bai 1 TB

int tan_suat(int x, int arr[MAX][MAX], int hang, int cot); // Bai 2 TB

int tan_suat_duong(int arr[MAX][MAX], int hang, int cot); // Bai 3 TB

void sap_xep_tang(int arr[], int len);

void sap_xep_giam(int arr[], int len);

void tang_cot_giam_hang(int arr[MAX][MAX], int hang, int cot); // Bai 1 K

void tang_hang_tang_cot(int arr[MAX][MAX], int hang, int cot); // Bai 2 K

int tong_khong_am(int arr[MAX][MAX], int hang, int cot); // Bai 4 TB

int tong_cheo_chinh(int arr[MAX][MAX], int hang, int cot); // Bai 5 TB

int tong_cheo_phu(int arr[MAX][MAX], int hang, int cot); // Bai 6 TB

void tang_hang(int arr[MAX][MAX], int hang, int cot); // Bai 7 TB

int tong_matran(int arr1[MAX][MAX], int hang1, int cot1, int arr2[MAX][MAX],
		int hang2, int cot2, int kqua[MAX][MAX], int &kqua_hang,
		int &kqua_cot); // Bai 8-tong TB

int tich_matran(int arr1[MAX][MAX], int hang1, int cot1, int arr2[MAX][MAX],
		int hang2, int cot2, int kqua[MAX][MAX], int &kqua_hang,
		int &kqua_cot); // Bai 8-tich TB

void phai_90(int arr[MAX][MAX], int &hang, int &cot); // Bai 4 xoay phai K

void trai_90(int arr[MAX][MAX], int &hang, int &cot); // Bai 4 xoay trai K

void xoay(int arr[MAX][MAX], int &hang, int &cot, int huong,
	  int n); // Bai 5 xoay n buoc K

void xoa_hang(int vt_hang, int arr[MAX][MAX], int &hang,
	      int &cot); // Bai 6 xoa hang K

void xoa_cot(int vt_cot, int arr[MAX][MAX], int hang,
	     int &cot); // Bai 6 xoa cot K

void xoa_trung(int arr1[MAX][MAX], int hang1, int cot1, int arr2[MAX][MAX],
	       int hang2, int cot2); // Bai 7 K

void lon_nhat(int arr[MAX][MAX], int hang, int cot); // Bai 11 K

void nho_nhat(int arr[MAX][MAX], int hang, int cot); // Bai 11 K

void matran_tong(int arr[MAX][MAX], int &hang, int &cot); // Bai 8 K

void matran_tich(int arr[MAX][MAX], int &hang, int &cot); // Bai 9 K

int tong1(int arr1[MAX][MAX], int hang1, int cot1, int arr2[MAX][MAX],
	  int hang2, int cot2);

int tong_n_mtran(int result[MAX][MAX], int &hang, int &cot); // Bai 3 K

int tich1(int arr1[MAX][MAX], int &hang1, int &cot1, int arr2[MAX][MAX],
	  int hang2, int cot2);

int tich_n_mtran(int result[MAX][MAX], int &hang, int &cot); // Bai 3K

void nhap_mang_r(float arr[MAX][MAX], int &hang, int &cot);

void xuat_mang_r(float arr[MAX][MAX], int hang, int cot);

int nghich_dao(float arr[MAX][MAX], int n, float result[MAX][MAX]); // Bai 10 K