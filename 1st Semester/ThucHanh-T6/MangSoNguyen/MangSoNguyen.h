#ifndef _MANGSONGUYEN_H_
#define _MANGSONGUYEN_H_
#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap_mang(int arr[], int &len_mang); // Bai 129

void xuat_mang(int arr[], int len_mang); // Bai 131

int la_nguyen_to(int n); // Kiem tra so nguyen to

int nguyen_to_dau(int arr[], int len_mang); // Bai 144

int nguyen_to_lon_nhat(int arr[], int len_mang); // Bai 151

int dau_tien_trong_doan(int x, int y, int arr[], int len_mang); // Bai 161

int dau_le(int n);

int dau_le_dau_tien(int arr[], int len_mang); // Bai 165

int la_2_k(int n);

int dau_2_k(int arr[], int len_mang); // Bai 166

int le_dau_tien(int arr[], int len_mang); // Tra ve gia tri le dau tien cua mang

int chan_nho_le(int arr[], int len_mang); // Bai 169

int lon_nhat_mang(int arr[], int len_mang); // Tra ve gia tri lon nhat cua mang

int snt_nho(int arr[], int len_mang); // Bai 170

int ucln(int a, int b); // UCLN cua a va b

int uoc_chung(int arr[], int len_mang); // Bai 171

int bcnn(int a, int b); // BCNN cua a va b

int boi_chung(int arr[], int len_mang); // Bai 172

int tim_chu_so(int arr[], int len_mang); // Bai 173

void lke_doan(int x, int y, int arr[], int len_mang); // Bai 177

void lke_180(int arr[], int len_mang); // Bai 180

void chan_lan_can(int arr[], int len_mang); // Bai 181

void lke_vtri_nguyento(int arr[], int len_mang); // Bai 184

void lke_dau_le(int arr[], int len_mang); // Bai 189

void gan_nhau_nhat(int arr[], int len_mang); // Bai 194

int tong(int arr[], int len_mang); // Bai 200

int tong_chuc_5(int arr[], int len_mang); // Bai 203

float tb_nguyento(int arr[], int len_mang); // Bai 211

int dem_chan(int arr[], int len_mang); // Bai 216

int tuong_quan_chan_le(int arr[], int len_mang); // Bai 221

void dem_cuc_tri(int arr[], int len_mang); // Bai 222

int dem_nguyento(int arr[], int len_mang); //Bai 223

int dem_trai_dau(int arr[], int len_mang); // Bai 227

int dem_gia_tri(int arr[], int len_mang); // Bai 228

int tan_suat(int x, int arr[], int len_mang); 

int dem_phan_biet(int arr[], int len_mang); // Bai 229

void lke_duy_nhat(int arr[], int len_mang); // Bai 231

void lke_khong_duy_nhat(int arr[], int len_mang); // Bai 232

void lke_tan_suat(int arr[], int len_mang); // Bai 233

void lke_nhieu_nhat(int arr[], int len_mang); // Bai 238

int dem_nguyento_phanbiet(int arr[], int len_mang); // Bai	239

int ton_tai_khong(int arr[], int len_mang); // Bai 240

int hai_khong(int arr[], int len_mang); // Bai 241

int ton_tai_nguyento(int arr[], int len_mang); // Bai 243

int la_hoan_thien(int n); // Kiem tra so hoan thien

int ktra_tinh_chat(int arr[], int len_mang); // Bai 244

int ktra_chan_le(int arr[], int len_mang); // Bai 247

int tang_dan(int arr[], int len_mang); // Bai 248

void cap_so_cong(int arr[], int len_mang); // Bai 250

int ktra_bang_nhau(int arr[], int len_mang); // Bai 251

int ktra_dang_song(int arr[], int len_mang); // Bai 252

int ktra_a_trong_b(int arr1[], int len_1, int arr2[], int len_2); // Bai 253

int dem_lon_truoc(int arr[], int len_mang); // Bai 254

void sap_xep_giam(int arr[], int len_mang); // Bai 256

void vtri_le_tang(int arr[], int len_mang); // Bai 257

void nguyento_tang(int arr[], int len_mang); // Bai 258

void hoan_thien_giam(int arr[], int len_mang); // Bai 259

int ktra_hoanvi(int arr1[], int len1, int arr2[], int len2); // Bai 260

void sx_chan_le(int arr[], int len_mang); // Bai 262

void nhap_bao_toan(int arr[], int &len_mang); // Bai 270

void xoa_ptu_cs(int k, int arr[], int &len_mang); // Bai 271

void xoa_ptu_gtri(int x, int arr[], int &len_mang);

void xoa_nguyento(int arr[], int &len_mang); // Bai 277

void xoa_trung(int arr[], int &len_mang); // Bai 278

void xoa_trung_tat_ca(int arr[], int &len_mang); // Bai 279

void dao_nguoc(int arr[], int len_mang); // Bai 283

void dao_chan(int arr[], int len_mang); // Bai 284

void chan_le_2hang(int arr[], int len_mang); // Bai 289

void liet_ke_con(int arr[], int &len_mang); // Bai 293

int count_bit_1(int n);

void con_lon_hon2(int arr[], int &len_mang); // Bai 294

void tao_mang_le(int arr1[], int len1, int arr2[], int &len2); // Bai 307

void tao_mang_nguyento(int arr1[], int len1, int arr2[], int &len2); // Bai 310
#endif
