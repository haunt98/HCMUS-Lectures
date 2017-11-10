//MSSV: 1612
//Ho ten: Nguyen Tran Hau
//Bai tap mang so thuc

#include "MangSoThuc.h"

int main(void)
{
	float arr[MAX], arr2[MAX];
	float x;
	int len_mang, len2, k;

	printf("Bai tap mang so thuc.\n");
	nhap_mang(arr, len_mang); // Bai 128
	xuat_mang(arr, len_mang); // Bai 130
	lke_vt_am(arr, len_mang); // Bai 133
	printf("Gia tri lon nhat cua mang: %0.2f\n", lon_nhat(arr, len_mang)); // Bai 134
	printf("Gia tri duong dau tien cua mang: %0.2f\n", duong_dau(arr, len_mang)); // Bai 135
	printf("Vi tri gia tri nho nhat cua mang: vi tri thu %d\n", vi_tri_nho_nhat(arr, len_mang)); // Bai 137
	printf("Gia tri duong nho nhat cua mang: %0.2f\n", duong_nho_nhat(arr, len_mang)); // Bai 140
	printf("Gia tri nho nhat cua mang: %0.2f\n", nho_nhat(arr, len_mang)); //Bai 142
	printf("Gia tri am lon nhat cua mang: %0.2f\n", am_lon_nhat(arr, len_mang)); // Bai 150
	printf("Vi tri gia tri am lon nhat cua mang: vi tri thu %d\n", vt_am_lon_nhat(arr, len_mang)); // Bai 154

	printf("Nhap x (trong bai 155): ");
	scanf("%f", &x);
	printf("Gia tri trong mang xa x nhat: %0.2f\n", xa_nhat(x, arr, len_mang)); // Bai 155

	tim_doan(arr, len_mang); //Bai 157
	printf("Doan: [-%0.2f,%0.2f]\n", tim_x(arr, len_mang), tim_x(arr, len_mang)); // Bai 158
	printf("Gia tri am cuoi cung lon hon -1 cua mang: %0.2f\n", cuoi_cung(arr, len_mang)); // Bai 160
	lke_cap(arr, len_mang); // Bai 174
	gan_nhau_nhat(arr, len_mang); // Bai 175
	liet_ke_am(arr, len_mang); // Bai 176
	lke_180(arr, len_mang); // Bai 180
	lke_vtri_lon_nhat(arr, len_mang); // Bai 183
	lke_duong_nho_nhat(arr, len_mang); // Bai 187
	lke_a_b_c(arr, len_mang); // Bai 195
	printf("Tong cac gia tri cua mang: %0.2f\n", tong(arr, len_mang)); // Bai 200
	printf("Tong cac gia tri lon hon gia tri lien truoc no: %0.2f\n", tong_204(arr, len_mang)); // Bai 204
	printf("Tong cac gia tri lon hon tri tuyet doi gia tri lien sau no: %0.2f\n", tong_205(arr, len_mang)); // Bai 205
	printf("Tong cac gia tri lon gia tri xung quang: %0.2f\n", tong_cuc_dai(arr, len_mang)); // Bai 206
	printf("Nhap x (Bai 213): ");
	scanf("%f", &x);
	printf("Trung binh cong cac gia tri lon hon %0.2f: %0.2f\n", x, tbc_lon_hon(x, arr, len_mang)); // Bai 213

	printf("Khoang cach trung binh giua cac gia tri trong mang: %0.2f\n", khoang_cach_tb(arr, len_mang)); // Bai 215

	printf("Nhap x (Bai 219): ");
	scanf("%f", &x);
	printf("Tan suat cua %0.2f: %d\n", x, tan_suat(x, arr, len_mang)); // Bai 219

	dem_cuc_tri(arr, len_mang); // Bai 222
	printf("So gia tri lon nhat: %d\n", dem_lon_nhat(arr, len_mang)); // Bai 225 
	printf("So gia tri ke nhau, cung dau, tri tuyet doi so lien sau lon hon so lien truoc: %d\n", dem_gia_tri(arr, len_mang)); // Bai 228	
	printf("So cac gia tri phan biet: %d\n", dem_phan_biet(arr, len_mang)); // Bai 229
	lke_khong_duy_nhat(arr, len_mang); // Bai 232
	lke_tan_suat(arr, len_mang); // Bai 233
	nhap_mang(arr2, len2);
	printf("So luong gia tri chi xuat hien mot trong hai mang: %d\n", dem_gia_tri_xuat_hien(arr, len_mang, arr2, len2)); // Bai 234

	lke_gia_tri_xuat_hien(arr, len_mang, arr2, len2); // Bai 235
	printf("Kiem tra tinh tang dan: %d\n", tang_dan(arr, len_mang)); // Bai 248
	printf("Kiem tra mang dang song: %d\n", ktra_dang_song(arr, len_mang)); // Bai 252

	printf("Nhap mang (Bai 253): ");
	nhap_mang(arr2, len2);
	printf("Mang truoc nam trong mang sau: %d\n", ktra_a_trong_b(arr, len_mang, arr2, len2)); // Bai 253

	printf("So cac gia tri trong mang lon hon moi gia tri dung dang truoc no: %d\n", dem_lon_truoc(arr, len_mang)); // Bai 254

	sap_xep_tang(arr, len_mang); // Bai 255
	printf("Mang tang dan: \n");
	xuat_mang(arr, len_mang);
	
	printf("Nhap mang (Bai 260): \n");
	nhap_mang(arr2, len2);
	printf("Kiem tra mang 1 mang 2 co phai la hoan vi: %d\n", ktra_hoanvi(arr, len_mang, arr2, len2)); // Bai 260

	sap_xep_duong(arr, len_mang); // Bai 261
	duong_tang_am_giam(arr, len_mang); // Bai 263

	printf("Nhap mang (Bai 264): \n");
	nhap_mang(arr2, len2);
	tron_mang(arr, len_mang, arr2, len2); // Bai 264
	them_vi_tri(x, k, arr, len_mang); // Bai 266
	nhap_giam_dan(arr, len_mang);
	
	printf("Nhap x (Bai 269): ");
	scanf("%f", &x);
	them_bao_toan(x, arr, len_mang); // Bai 269
	xoa_lon_nhat(arr, len_mang); // Bai 272
	xoa_trung(arr, len_mang); // Bai 278
	xoa_trung_tat_ca(arr, len_mang); // Bai 279
	dao_nguoc(arr, len_mang); // Bai 283
	nguyen_hoa(arr, len_mang);
	tao_mang_am(arr, len_mang, arr2, len2); // Bai 308
	tao_mang_lan_can(arr, len_mang, arr2, len2); // Bai 309
	lke_con_tang(arr, len_mang); // Bai 295
	lke_con_lon_nhat(arr, len_mang); // Bai 296
	return 0;
}