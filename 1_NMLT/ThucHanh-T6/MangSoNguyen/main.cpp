// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai tap mang so nguyen
#include "MangSoNguyen.h"

int main(void)
{
	int arr[MAX], arr2[MAX];
	int len_mang, len2;
	int x, y;

	printf("Bai tap mang so nguyen.\n");
	nhap_mang(arr, len_mang); // Bai 129
	xuat_mang(arr, len_mang); // Bai 131
	printf("So nguyen to dau tien cua mang: %d\n",
	       nguyen_to_dau(arr, len_mang)); // Bai 144
	printf("So nguyen to lon nhat cua mang: %d\n",
	       nguyen_to_lon_nhat(arr, len_mang)); // Bai 151
	printf("Nhap x, y (trong bai 161): ");
	scanf("%d %d", &x, &y);
	printf("Gia tri dau tien cua mang nam trong (%d,%d): %d\n", x, y,
	       dau_tien_trong_doan(x, y, arr, len_mang)); // Bai 161
	printf("Gia tri dau tien cua mang co chu so dau tien la so le: %d\n",
	       dau_le_dau_tien(arr, len_mang)); // Bai 165
	printf("Gia tri dau tien cua mang co dang 2^k: %d\n",
	       dau_2_k(arr, len_mang)); // Bai 166
	printf("So chan lon nhat nho hon moi gia tri le co trong mang: %d\n",
	       chan_nho_le(arr, len_mang)); // Bai 169
	printf("So nguyen to nho nhat lon hon moi gia tri trong mang: %d\n",
	       snt_nho(arr, len_mang)); // Bai 170
	printf("UCLN cua tat ca phan tu co trong mang: %d\n",
	       uoc_chung(arr, len_mang)); // Bai 171
	printf("BCNN cua tat ca phan tu co trong mang: %d\n",
	       boi_chung(arr, len_mang)); // Bai 172
	printf("Chu so xuat hien it nhat trong mang: %d\n",
	       tim_chu_so(arr, len_mang)); // Bai 173
	printf("Nhap x, y (trong bai 177): ");
	scanf("%d %d", &x, &y);
	lke_doan(x, y, arr, len_mang);    // Bai 177
	lke_180(arr, len_mang);		  // Bai 180
	chan_lan_can(arr, len_mang);      // Bai 181
	lke_vtri_nguyento(arr, len_mang); // Bai 184
	lke_dau_le(arr, len_mang);	// Bai 189
	gan_nhau_nhat(arr, len_mang);     // Bai 194
	printf("Tong cac gia tri cua mang: %d\n",
	       tong(arr, len_mang)); // Bai 200
	printf("Tong cac so nguyen co chu so hang chuc la 5: %d\n",
	       tong_chuc_5(arr, len_mang)); // Bai 203
	printf("Trung binh cong cac so nguyen to: %0.2f\n",
	       tb_nguyento(arr, len_mang)); // Bai 211
	printf("So cac gia tri chan co trong mang: %d\n",
	       dem_chan(arr, len_mang)); // Bai 216
	printf("Tuong quan chan le: %d\n",
	       tuong_quan_chan_le(arr, len_mang)); // Bai 221
	dem_cuc_tri(arr, len_mang);		   // Bai 222
	printf("So cac so nguyen to: %d\n",
	       dem_nguyento(arr, len_mang)); // Bai 223
	printf("So cac cap gia tri ke nhau va trai dau: %d\n",
	       dem_trai_dau(arr, len_mang)); // Bai 227
	printf("So gia tri ke nhau, cung dau, tri tuyet doi so lien sau lon "
	       "hon so lien truoc: %d\n",
	       dem_gia_tri(arr, len_mang)); // Bai 228
	printf("So cac gia tri phan biet: %d\n",
	       dem_phan_biet(arr, len_mang)); // Bai 229
	lke_duy_nhat(arr, len_mang);	  // Bai 231
	lke_khong_duy_nhat(arr, len_mang);    // Bai 232
	lke_tan_suat(arr, len_mang);	  // Bai 233
	lke_nhieu_nhat(arr, len_mang);	// Bai 238
	printf("So cac so nguyen to phan biet trong mang: %d\n",
	       dem_nguyento_phanbiet(arr, len_mang)); // Bai 239
	printf("Kiem tra mang co ton tai so khong: %d\n",
	       ton_tai_khong(arr, len_mang)); // Bai 240
	printf("Kiem tra mang co ton tai 2 so khong lien tiep: %d\n",
	       hai_khong(arr, len_mang)); // Bai 241
	printf("Kiem tra mang co ton tai so nguyen to: %d\n",
	       ton_tai_nguyento(arr, len_mang)); // Bai 243
	printf("Kiem tra mang khong ton tai so hoan thien lon hon 256: %d\n",
	       ktra_tinh_chat(arr, len_mang)); // Bai 244
	printf("Kiem tra mang co tinh chan le: %d\n",
	       ktra_chan_le(arr, len_mang)); // Bai 247
	printf("Kiem tra tinh tang dan: %d\n",
	       tang_dan(arr, len_mang)); // Bai 248
	cap_so_cong(arr, len_mang);      // Bai 250
	printf("Kiem tra cac phan tu co bang nhau khong: %d\n",
	       ktra_bang_nhau(arr, len_mang)); // Bai 251
	printf("Kiem tra mang dang song: %d\n",
	       ktra_dang_song(arr, len_mang)); // Bai 252
	printf("Nhap mang (Bai 253): \n");
	nhap_mang(arr2, len2);
	printf("Mang truoc nam trong mang sau: %d\n",
	       ktra_a_trong_b(arr, len_mang, arr2, len2)); // Bai 253
	printf("So cac gia tri trong mang lon hon moi gia tri dung dang truoc "
	       "no: %d\n",
	       dem_lon_truoc(arr, len_mang)); // Bai 254
	sap_xep_giam(arr, len_mang);	  // Bai 256
	printf("Mang giam dan: \n");
	xuat_mang(arr, len_mang);
	vtri_le_tang(arr, len_mang);    // Bai 257
	nguyento_tang(arr, len_mang);   // Bai 258
	hoan_thien_giam(arr, len_mang); // Bai 259
	printf("Nhap mang (Bai 260): \n");
	nhap_mang(arr2, len2);
	printf("Kiem tra mang 1 mang 2 co phai la hoan vi: %d\n",
	       ktra_hoanvi(arr, len_mang, arr2, len2)); // Bai 260
	sx_chan_le(arr, len_mang);			// Bai 262
	nhap_bao_toan(arr, len_mang);			// Bai 270
	xoa_nguyento(arr, len_mang);			// Bai 277
	xoa_trung(arr, len_mang);			// Bai 278
	xoa_trung_tat_ca(arr, len_mang);		// Bai 279
	dao_nguoc(arr, len_mang);			// Bai 283
	dao_chan(arr, len_mang);			// Bai 284
	chan_le_2hang(arr, len_mang);			// Bai 289
	tao_mang_le(arr, len_mang, arr2, len2);		// Bai 307
	tao_mang_nguyento(arr, len_mang, arr2, len2);   // Bai 310
	liet_ke_con(arr, len_mang);			// Bai 293
	con_lon_hon2(arr, len_mang);			// Bai 294
	return 0;
}
