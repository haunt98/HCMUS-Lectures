// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai tap tuan 08

#include "xuly.h"

int main(void)
{
	int arr[MAX][MAX], arr2[MAX][MAX], kqua[MAX][MAX];
	int hang, cot, x, y, hang2, cot2, kqua_hang, kqua_cot;
	float r_arr[MAX][MAX], r_kqua[MAX][MAX];

	nhap_mang(arr, hang, cot);
	xuat_mang(arr, hang, cot);

	printf("Tong cac phan tu cua mang: %d\n",
	       tong(arr, hang, cot)); // Bai 1 TB

	printf("Nhap x can tim tan suat: ");
	scanf("%d", &x);
	printf("Tan suat cua x: %d lan xuat hien.\n",
	       tan_suat(x, arr, hang, cot)); // Bai 2 TB

	printf("So lan xuat hien cua cac so nguyen duong: %d\n",
	       tan_suat_duong(arr, hang, cot)); // Bai 3 TB

	printf("Tong cac phan tu khong am: %d\n",
	       tong_khong_am(arr, hang, cot)); // Bai 4 TB

	printf("Tong cac phan tu tren duong cheo chinh: %d\n",
	       tong_cheo_chinh(arr, hang, cot)); // Bai 5 TB

	printf("Tong cac phan tu tren duong cheo phu: %d\n",
	       tong_cheo_phu(arr, hang, cot)); // Bai 6 TB

	nhap_mang(arr2, hang2, cot2);

	printf("Tong 2 mang da nhap:\n");
	tong_matran(arr, hang, cot, arr2, hang2, cot2, kqua, kqua_hang,
		    kqua_cot); // Bai 8-tong TB
	xuat_mang(kqua, kqua_hang, kqua_cot);

	printf("Tich 2 ma tran da nhap:\n");
	tich_matran(arr, hang, cot, arr2, hang2, cot2, kqua, kqua_hang,
		    kqua_cot); // Bai 8-tich TB
	xuat_mang(kqua, kqua_hang, kqua_cot);

	printf("Mang tang dan tren hang:\n");
	tang_hang(arr, hang, cot); // Bai 7 TB
	xuat_mang(arr, hang, cot);

	printf("Mang tang dan tren cot va giam dan tren hang: \n");
	tang_cot_giam_hang(arr, hang, cot); // Bai 1 K
	xuat_mang(arr, hang, cot);

	printf("Mang tang dan tren cot va tang dan tren hang: \n");
	tang_hang_tang_cot(arr, hang, cot); // Bai 2 K
	xuat_mang(arr, hang, cot);

	printf("Xoay ma tran sang phai: \n"); // Bai 4 K
	phai_90(arr, hang, cot);
	xuat_mang(arr, hang, cot);

	printf("Xoay ma tran sang trai: \n"); // Bai 4 K
	trai_90(arr, hang, cot);
	xuat_mang(arr, hang, cot);

	printf("Nhap 1 neu xoay trai nhap 2 neu muon xoay phai: "); // Bai 5 K
	scanf("%d", &x);
	printf("Nhap so lan quay: ");
	scanf("%d", &y);
	xoay(arr, hang, cot, x, y);
	xuat_mang(arr, hang, cot);

	printf("Nhap cot can xoa: "); // Bai 6 K
	scanf("%d", &x);
	xoa_cot(x, arr, hang, cot);
	xuat_mang(arr, hang, cot);

	printf("Nhap hang can xoa: "); // Bai 6 K
	scanf("%d", &x);
	xoa_hang(x, arr, hang, cot);
	xuat_mang(arr, hang, cot);

	printf("Nhap hai mang de xoa trung lap:\n");
	nhap_mang(arr, hang, cot);
	nhap_mang(arr2, hang2, cot2);
	xoa_trung(arr, hang, cot, arr2, hang2, cot2); // Bai 7 K
	xuat_mang(arr, hang, cot);
	printf("\n");
	xuat_mang(arr2, hang2, cot2);

	lon_nhat(arr, hang, cot); // Bai 11 K
	nho_nhat(arr, hang, cot);

	matran_tong(arr, hang, cot); // Bai 8 K
	matran_tich(arr, hang, cot); // Bai 9 K

	if (tong_n_mtran(kqua, kqua_hang, kqua_cot)) // Bai 3 K
	{
		printf("Tong n ma tran da nhap\n");
		xuat_mang(kqua, kqua_hang, kqua_cot);
	} else
		printf("Khong cong duoc\n");

	if (tich_n_mtran(kqua, kqua_hang, kqua_cot)) // Bai 3 K
	{
		printf("Tich n ma tran da nhap\n");
		xuat_mang(kqua, kqua_hang, kqua_cot);
	} else
		printf("Khong nhan duoc\n");

	printf("Nhap ma tran can tim nghich dao\n");
	nhap_mang_r(r_arr, hang, cot);
	if (hang != cot)
		printf("Khong co nghich dao\n");
	else {
		if (nghich_dao(r_arr, hang, r_kqua)) // Bai 10 K
		{
			printf("Nghich dao:\n");
			xuat_mang_r(r_kqua, hang, hang);
		} else
			printf("Khong co nghich dao\n");
	}
	return 0;
}