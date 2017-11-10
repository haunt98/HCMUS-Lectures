#ifndef _MANGSOTHUC_H_
#define _MANGSOTHUC_H_

#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap_mang(float arr[], int &len_mang); // Bai 128

void xuat_mang(float arr[], int len_mang); // Bai 130

void lke_vt_am(float arr[], int len_mang); // Bai 133

float lon_nhat(float arr[], int len_mang); // Bai 134

float duong_dau(float arr[], int len_mang); // Bai 135

int vi_tri_nho_nhat(float arr[], int len_mang); // Bai 137

float duong_nho_nhat(float arr[], int len_mang); // Bai 140

float nho_nhat(float arr[], int len_mang); // Bai 142

float am_dau(float arr[], int len_mang);

float am_lon_nhat(float arr[], int len_mang); // Bai 150

int vt_am_lon_nhat(float arr[], int len_mang); // Bai 154

float xa_nhat(float x, float arr[], int len_mang); // Bai 155

void tim_doan(float arr[], int len_mang); // Bai 157

float tim_x(float arr[], int len_mang); // Bai 158

float cuoi_cung(float arr[], int len_mang); // Bai 160

void lke_cap(float arr[], int len_mang); // Bai 174

void gan_nhau_nhat(float arr[], int len_mang); // Bai 175

void liet_ke_am(float arr[], int len_mang); // Bai 176

void lke_180(float arr[], int len_mang); // Bai 180

void lke_vtri_lon_nhat(float arr[], int len_mang); // Bai 183

void lke_duong_nho_nhat(float arr[], int len_mang); // Bai 187

void lke_a_b_c(float arr[], int len_mang); // Bai 195

float tong(float arr[], int len_mang); // Bai 200

float tong_204(float arr[], int len_mang); // Bai 204

float tong_205(float arr[], int len_mang); // Bai 205

float tong_cuc_dai(float arr[], int len_mang); // Bai 206

float tbc_lon_hon(float x, float arr[], int len_mang); // Bai 213

float khoang_cach_tb(float arr[], int len_mang); // Bai 215

int tan_suat(float x, float arr[], int len_mang); // Bai 219

void dem_cuc_tri(float arr[], int len_mang); // Bai 222

int dem_lon_nhat(float arr[], int len_mang); // Bai 225

int dem_trai_dau(float arr[], int len_mang); // Bai 227

int dem_gia_tri(float arr[], int len_mang); // Bai 228

int dem_phan_biet(float arr[], int len_mang); // Bai 229

void lke_khong_duy_nhat(float arr[], int len_mang); // Bai 232

void lke_tan_suat(float arr[], int len_mang); // Bai 233

int dem_gia_tri_xuat_hien(float arr1[], int len_1, float arr2[], int len_2); // Bai 234

void lke_gia_tri_xuat_hien(float arr1[], int len_1, float arr2[], int len_2); // Bai 235

int tang_dan(float arr[], int len_mang); // Bai 248

int ktra_dang_song(float arr[], int len_mang); // Bai 252

int ktra_a_trong_b(float arr1[], int len_1, float arr2[], int len_2); // Bai 253

int dem_lon_truoc(float arr[], int len_mang); // Bai 254

void sap_xep_tang(float arr[], int len_mang); // Bai 255

void sap_xep_giam(float arr[], int len_mang);

int ktra_hoanvi(float arr1[], int len1, float arr2[], int len2); // Bai 260

void sap_xep_duong(float arr[], int len_mang); // Bai 261

void duong_tang_am_giam(float arr[], int len_mang); // Bai 263

void tron_mang(float arr1[], int len1, float arr2[], int len2); // Bai 264

void them_vi_tri(float &x, int &k, float arr[], int &len_mang); // Bai 266

void nhap_giam_dan(float arr[], int &len_mang); // Bai 267

void them_bao_toan(float x, float arr[], int &len_mang); // Bai 269

void xoa_ptu_cs(int k, int arr[], int &len_mang); // Bai 271

void xoa_lon_nhat(float arr[], int &len_mang); // Bai 272

void xoa_trung(float arr[], int &len_mang); // Bai 278

void xoa_trung_tat_ca(float arr[], int &len_mang); // Bai 279

void dao_nguoc(float arr[], int len_mang); // Bai 283

void nguyen_hoa(float arr[], int len_mang); // Bai 292

int count_bit_1(int n);

void xuat_day(float arr[], int len_mang);

void lke_con_tang(float arr[], int &len_mang); // Bai 295

void lke_con_lon_nhat(float arr[], int &len_mang);

void tao_mang_am(float arr1[], int len1, float arr2[], int &len2); // Bai 308

void tao_mang_lan_can(float arr1[], int len1, float arr2[], int &len2); // Bai 309
#endif