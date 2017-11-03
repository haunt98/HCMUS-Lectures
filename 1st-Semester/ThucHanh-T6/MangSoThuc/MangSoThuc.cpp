#include "MangSoThuc.h"

void nhap_mang(float arr[], int &len_mang) // Bai 129
{
	int i;
	do{
		printf("Nhap do dai mang: ");
		scanf("%d", &len_mang);
	} while (len_mang < 1);

	for (i = 0; i < len_mang; ++i)
	{
		printf("Nhap gia tri mang tai vi tri thu %d: ", i);
		scanf("%f", &arr[i]);
	}
}

void xuat_mang(float arr[], int len_mang) // Bai 130
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		printf("Gia tri mang tai vi tri thu %d: %0.2f\n", i, arr[i]);
	}

}

void lke_vt_am(float arr[], int len_mang) // Bai 133
{
	int i;
	printf("Cac vi tri nhan gia tri am cua mang: ");
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] < 0)
			printf("%d, ", i + 1);
	}
	printf("\n");
}

float lon_nhat(float arr[], int len_mang) // Bai 134
{
	int i;
	float max = arr[0];
	for (i = 1; i < len_mang; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

float duong_dau(float arr[], int len_mang) // Bai 135
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] > 0)
			return	arr[i];
	}
	return -1;
}

int vi_tri_nho_nhat(float arr[], int len_mang) // Bai 137
{
	int i;
	int cso_min = 0;
	for (i = 1; i < len_mang; ++i)
	{
		if (arr[i] < arr[cso_min])
			cso_min = i;
	}
	return cso_min + 1;
}

float duong_nho_nhat(float arr[], int len_mang) // Bai 140
{
	int i;
	float min = duong_dau(arr, len_mang);
	for (i = 0; i< len_mang; ++i)
	{
		if (arr[i] > 0 && arr[i] < min)
			min = arr[i];
	}
	return min;
}

float nho_nhat(float arr[], int len_mang) //Bai 142
{
	int i;
	float min = arr[0];
	for (i = 1; i < len_mang; ++i)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

float am_dau(float arr[], int len_mang)
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] < 0)
			return	arr[i];
	}
	return 0;
}

float am_lon_nhat(float arr[], int len_mang) // Bai 150
{
	int i;
	float am_max = am_dau(arr, len_mang);
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] < 0 && arr[i] > am_max)
			am_max = arr[i];
	}
	return am_max;
}

int vt_am_lon_nhat(float arr[], int len_mang) // Bai 154
{
	int i;
	if (!am_dau(arr, len_mang))
		return -1;
	int vt_am_max = 0;
	for (i = 1; i < len_mang; ++i)
	{
		if (arr[i] < 0 && arr[i] > arr[vt_am_max])
			vt_am_max = i;
	}
	return vt_am_max + 1;
}

float xa_nhat(float x, float arr[], int len_mang) // Bai 155
{
	int i = 0;
	float max = abs(x - arr[0]);
	float sth = arr[0];
	for (i = 1; i < len_mang; ++i)
	{
		if (abs(x - arr[i]) > max)
		{
			max = abs(x - arr[i]);
			sth = arr[i];
		}
	}
	return sth;
}

void tim_doan(float arr[], int len_mang) // Bai 157
{
	float min = nho_nhat(arr, len_mang);
	float max = lon_nhat(arr, len_mang);
	printf("Doan chua tat ca gia tri trong mang: [%0.2f,%0.2f]\n", min, max);
}

float tim_x(float arr[], int len_mang) // Bai 158
{
	float min = nho_nhat(arr, len_mang);
	float max = lon_nhat(arr, len_mang);
	if (abs(min) > abs(max))
		return abs(min);
	return abs(max);
}

float cuoi_cung(float arr[], int len_mang) // Bai 160
{
	int i;
	for (i = len_mang - 1; i > -1; --i)
	{
		if (arr[i] < 0 && arr[i] > -1)
			return arr[i];
	}
	return 0;
}

void lke_cap(float arr[], int len_mang) // Bai 174
{
	int i, j;
	for (i = 0; i < len_mang - 1; ++i)
	{
		for (j = i + 1; j < len_mang; ++j)
		{
			if (arr[i] > arr[j])
				printf("(%0.2f,%0.2f) ", arr[j], arr[i]);
			else
				printf("(%0.2f,%0.2f) ", arr[i], arr[j]);
		}
	}
}

void gan_nhau_nhat(float arr[], int len_mang) // Bai 175
{
	int i, j;
	float min = abs(arr[0] - arr[1]);
	float x = arr[0];
	float y = arr[1];
	for (i = 0; i < len_mang - 1; ++i)
	{
		for (j = i + 1; j < len_mang; ++j)
		{
			if (abs(arr[i] - arr[j]) < min)
			{
				min = abs(arr[i] - arr[j]);
				x = arr[i];
				y = arr[j];
			}
		}
	}
	printf("2 gia tri gan nhau nhat trong mang: %0.2f va %0.2f\n", x, y);
}

void liet_ke_am(float arr[], int len_mang) // Bai 176
{
	printf("Cac so am trong mang: ");
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] < 0)
			printf("%0.2f, ",arr[i]);
	}
	printf("\n");
}

void lke_180(float arr[], int len_mang) // Bai 180
{
	printf("Cac gia tri nho hon tri tuyet doi gia tri lien sau va lon hon gia tri lien truoc: ");
	int i;
	for (i = 1; i < len_mang - 1; ++i)
	{
		if (arr[i] < abs(arr[i + 1]) && arr[i] > arr[i - 1])
			printf("%0.2f, ", arr[i]);
	}
	printf("\n");
}

void lke_vtri_lon_nhat(float arr[], int len_mang) // Bai 183
{
	int i;
	float max = lon_nhat(arr, len_mang);
	printf("Liet ke cac vi tri ma tai do la gia tri lon nhat cua mang: ");
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] == max)
			printf("%d, ", i + 1);
	}
	printf("\n");
}

void lke_duong_nho_nhat(float arr[], int len_mang) // Bai 187
{
	int i;
	float min = duong_nho_nhat(arr, len_mang);
	printf("Vi tri ma gia tri tai do bang gia tri duong nho nhat trong mang: ");
	if (min == -1)
		return;
	else
	{
		for (i = 0; i < len_mang; ++i)
		{
			if (arr[i] == min)
				printf("%d, ", i + 1);
		}
		printf("\n");
	}

}

void lke_a_b_c(float arr[], int len_mang) // Bai 195
{
	int i, j, k;
	printf("Cac gia tri thoa (a,b,c) voi a = b + c: ");
	for (i = 0; i < len_mang - 2; ++i)
	{
		for (j = i + 1; j < len_mang - 1; ++j)
		{
			for (k = j + 1; k < len_mang; ++k)
			{
				if (arr[i] == arr[j] + arr[k])
					printf("(%0.2f,%0.2f,%0.2f) ", arr[i], arr[j], arr[k]);
				if (arr[j] == arr[k] + arr[i])
					printf("(%0.2f,%0.2f,%0.2f) ", arr[j], arr[k], arr[i]);
				if (arr[k] == arr[i] + arr[j])
					printf("(%0.2f,%0.2f,%0.2f) ", arr[k], arr[i], arr[j]);
			}
		}
	}
	printf("\n");
}

float tong(float arr[], int len_mang) // Bai 200
{
	float sum = 0;
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

float tong_204(float arr[], int len_mang) // Bai 204
{
	int i;
	float sum = 0;
	for (i = 1; i < len_mang; ++i)
	{
		if (arr[i] > arr[i - 1])
			sum += arr[i];
	}
	return sum;
}

float tong_205(float arr[], int len_mang) // Bai 205
{
	int i;
	float sum = 0;
	for (i = 0; i < len_mang - 1; ++i)
	{
		if (arr[i] > abs(arr[i + 1]))
			sum += arr[i];
	}
	return sum;
}

float tong_cuc_dai(float arr[], int len_mang) // Bai 206
{
	float sum = 0;
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (i == 0)
		{
			if (arr[i] > arr[i + 1])
				sum += arr[i];
		}
		else if (i == len_mang - 1)
		{
			if (arr[i] > arr[i - 1])
				sum += arr[i];
		}
		else
		{
			if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
				sum += arr[i];
		}
	}
	return sum;
}

float tbc_lon_hon(float x, float arr[], int len_mang) // Bai 213
{
	int i, dem;
	float sum, tbc;
	sum = 0; dem = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] > x)
		{
			sum += arr[i];
			++dem;
		}
	}
	tbc = sum / dem;
	return tbc;
}

float khoang_cach_tb(float arr[], int len_mang) // Bai 215
{
	float sum, tbc;
	int i, j, dem;
	sum = 0; dem = 0;
	for (i = 0; i < len_mang - 1; ++i)
	{
		for (j = i + 1; j < len_mang; ++j)
		{
			sum += abs(arr[i] - arr[j]);
			++dem;
		}
	}
	tbc = sum / dem;
	return tbc;
}

int tan_suat(float x, float arr[], int len_mang) // Bai 219
{
	int dem = 0;
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] == x)
			++dem;
	}
	return dem;
}

void dem_cuc_tri(float arr[], int len_mang) // Bai 222
{
	int dem_lon, dem_nho, i;
	dem_lon = 0; dem_nho = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (i == 0)
		{
			if (arr[i] > arr[i + 1])
				++dem_lon;
			if (arr[i] < arr[i + 1])
				++dem_nho;
		}
		else if (i == len_mang - 1)
		{
			if (arr[i] > arr[i - 1])
				++dem_lon;
			if (arr[i] < arr[i - 1])
				++dem_nho;
		}
		else
		{
			if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
				++dem_lon;
			if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1])
				++dem_nho;
		}
	}
	printf("So gia tri lon hon gia tri xung quanh: %d\n", dem_lon);
	printf("So gia tri nho hon gia tri xung quanh: %d\n", dem_nho);
}

int dem_lon_nhat(float arr[], int len_mang) // Bai 225
{
	float max = lon_nhat(arr, len_mang);
	int i, dem;
	dem = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] == max)
			++dem;
	}
	return dem;
}

int dem_trai_dau(float arr[], int len_mang) // Bai 227
{
	int i, dem;
	dem = 0;
	for (i = 0; i < len_mang-1; ++i)
	{
		if (arr[i] * arr[i + 1] < 0)
			++dem;
	}
	return dem;
}

int dem_gia_tri(float arr[], int len_mang) // Bai 228
{
	int dem, i;
	dem = 0;
	for (i = 0; i < len_mang - 1; ++i)
	{
		if (arr[i] * arr[i + 1] > 0 && arr[i] < abs(arr[i + 1]))
			++dem;
	}
	return dem;
}

int dem_phan_biet(float arr[], int len_mang) // Bai 229 
{
	int dem, flag, i;
	dem = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (tan_suat(arr[i], arr, len_mang) == 1)
			++dem;
	}
	return dem;
}

void lke_khong_duy_nhat(float arr[], int len_mang) // Bai 232
{
	int i, n_len = 0;
	float mang_tam[MAX];
	for (i = 0; i < len_mang; ++i)
	{
		if (tan_suat(arr[i], arr, len_mang) > 1)
		{
			if (tan_suat(arr[i], mang_tam, n_len) == 0)
				mang_tam[n_len++] = arr[i];
		}
	}
	printf("Cac gia tri xuat hien trong day qua mot lan: ");
	for (i = 0; i < n_len; ++i)
	{
		printf("%0.2f, ", mang_tam[i]);
	}
	printf("\n");
}

void lke_tan_suat(float arr[], int len_mang) // Bai 233
{
	int i, n_len;
	float mang_tam[MAX];
	n_len = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (tan_suat(arr[i], mang_tam, n_len) == 0)
		{
			mang_tam[n_len++] = arr[i];
		}
	}
	printf("Gia tri Tan suat\n");
	for (i = 0; i < n_len; ++i)
	{
		printf("%0.2f           %d\n", mang_tam[i], tan_suat(mang_tam[i], arr, len_mang));
	}
}

int dem_gia_tri_xuat_hien(float arr1[], int len_1, float arr2[], int len_2) // Bai 234
{
	float mang_tam_1[MAX], mang_tam_2[MAX];
	int i, dem, n_len_1, n_len_2;
	dem = 0; n_len_1 = 0; n_len_2 = 0;

	for (i = 0; i < len_1; ++i)
	{
		if (tan_suat(arr1[i], mang_tam_1, n_len_1) == 0) // Loai trung lap mang 1
			mang_tam_1[n_len_1++] = arr1[i];
	}
	for (i = 0; i < n_len_1; ++i)
	{
		if (tan_suat(mang_tam_1[i], arr2, len_2) == 0) // Xuat hien mang 1 nhung khong co trong mang 2
			++dem;
	}

	for (i = 0; i < len_2; ++i)
	{
		if (tan_suat(arr2[i], mang_tam_2, n_len_2) == 0) // Loai trung lap mang 2
			mang_tam_2[n_len_2++] = arr2[i];
	}
	for (i = 0; i < n_len_2; ++i)
	{
		if (tan_suat(mang_tam_2[i], arr1, len_1) == 0) // Xuat hien mang 2 nhung khong co trong mang 1
			++dem;
	}
	return dem;
}

void lke_gia_tri_xuat_hien(float arr1[], int len_1, float arr2[], int len_2) // Bai 235
{
	float mang_tam_1[MAX], mang_tam_2[MAX];
	int i, n_len_1, n_len_2;
	n_len_1 = 0; n_len_2 = 0;
	printf("Cac gia tri chi xuat hien mot trong hai mang: ");
	for (i = 0; i < len_1; ++i)
	{
		if (tan_suat(arr1[i], mang_tam_1, n_len_1) == 0) // Loai trung lap mang 1
			mang_tam_1[n_len_1++] = arr1[i];
	}
	for (i = 0; i < n_len_1; ++i)
	{
		if (tan_suat(mang_tam_1[i], arr2, len_2) == 0) // Xuat hien mang 1 nhung khong co trong mang 2
			printf("%0.2f, ", mang_tam_1[i]); 
	}

	for (i = 0; i < len_2; ++i)
	{
		if (tan_suat(arr2[i], mang_tam_2, n_len_2) == 0) // Loai trung lap mang 2
			mang_tam_2[n_len_2++] = arr2[i];
	}
	for (i = 0; i < n_len_2; ++i)
	{
		if (tan_suat(mang_tam_2[i], arr1, len_1) == 0) // Xuat hien mang 2 nhung khong co trong mang 1
			printf("%0.2f, ", mang_tam_2[i]);
	}
	printf("\n");
}

int tang_dan(float arr[], int len_mang) // Bai 248
{
	int i, flag;
	flag = 1;
	for (i = 0; i < len_mang - 1; ++i)
	{
		if (arr[i] >= arr[i + 1])
			flag = 0;
	}
	return flag;
}

int ktra_dang_song(float arr[], int len_mang) // Bai 252
{
	int i, flag;
	flag = 1;
	for (i = 1; i < len_mang - 1; ++i)
	{
		if ((arr[i] <= arr[i + 1] || arr[i] <= arr[i - 1]) && (arr[i] >= arr[i + 1] || arr[i] >= arr[i - 1]))
			flag = 0;
	}
	return flag;
}

int ktra_a_trong_b(float arr1[], int len_1, float arr2[], int len_2) // Bai 253
{
	int i, flag;
	flag = 1;
	if (len_1 > len_2)
		flag = 0;
	else
	{
		for (i = 0; i < len_1; ++i)
		{
			if (tan_suat(arr1[i], arr2, len_2) < tan_suat(arr1[i], arr1, len_1))
				flag = 0;
		}
	}
	return flag;
}

int dem_lon_truoc(float arr[], int len_mang) // Bai 254
{
	int flag, dem, i, j;
	dem = 0;
	for (i = 1; i < len_mang; ++i)
	{
		flag = 1;
		for (j = 0; j < i; ++j)
		{
			if (arr[j] >= arr[i])
				flag = 0;
		}
		if (flag == 1)
			++dem;
	}
	return dem;
}

void sap_xep_tang(float arr[], int len_mang) // Bai 255
{
	int i, j;
	float tam;
	for (i = 1; i < len_mang; ++i)
	{
		tam = arr[i];
		j = i - 1;
		while (j > -1 && arr[j] > tam)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		j = j + 1;
		arr[j]=tam;
	}
}

void sap_xep_giam(float arr[], int len_mang)
{
	int i, j;
	float tam;
	for (i = 1; i < len_mang; ++i)
	{
		tam = arr[i];
		j = i - 1;
		while (j > -1 && arr[j] < tam)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		j = j + 1;
		arr[j] = tam;
	}
}

int ktra_hoanvi(float arr1[], int len1, float arr2[], int len2) // Bai 260
{
	int i, flag;
	flag = 1;
	if (len1 != len2)
		flag = 0;
	else
	{
		for (i = 0; i < len1; ++i)
			if (tan_suat(arr1[i], arr1, len1) != tan_suat(arr1[i], arr2, len2))
				flag = 0;
	}
	return flag;
}

void sap_xep_duong(float arr[], int len_mang) // Bai 261
{
	float mang_tam[MAX];
	int i, j, new_len;
	for (new_len = 0, i = 0; i < len_mang; ++i)
	{
		if (arr[i] > 0)
			mang_tam[new_len++] = arr[i];
	}
	sap_xep_tang(mang_tam, new_len);
	for (i = 0, j = 0; i < len_mang; ++i)
	{
		if (arr[i] > 0)
			arr[i] = mang_tam[j++];
	}
	printf("Sap xep cac so duong:\n");
	xuat_mang(arr, len_mang);
}

void duong_tang_am_giam(float arr[], int len_mang) // Bai 263
{
	float mang_duong[MAX], mang_am[MAX];
	int len_duong, len_am;
	int i, j, k;
	for (len_duong = 0, len_am = 0, i = 0; i < len_mang; ++i)
	{
		if (arr[i] > 0)
			mang_duong[len_duong++] = arr[i];
		if (arr[i] < 0)
			mang_am[len_am++] = arr[i];
	}
	sap_xep_tang(mang_duong, len_duong);
	sap_xep_giam(mang_am, len_am);
	for (j = 0, k = 0, i = 0; i < len_mang; ++i)
	{
		if (arr[i] > 0)
			arr[i] = mang_duong[j++];
		if (arr[i] < 0)
			arr[i] = mang_am[k++];
	}
	printf("Duong tang am giam:\n");
	xuat_mang(arr, len_mang);
}

void tron_mang(float arr1[], int len1, float arr2[], int len2) // Bai 264
{
	int i;
	int n_len = len1 + len2;
	for (i = len1; i < n_len; ++i)
	{
		arr1[i] = arr2[i - len1];
	}
	sap_xep_tang(arr1, n_len);
	printf("Tron mang\n");
	xuat_mang(arr1, n_len);
}

void them_vi_tri(float &x, int &k, float arr[], int &len_mang) // Bai 266
{
	printf("Nhap x (Bai 265): ");
	scanf("%f", &x);
	printf("Nhap vi tri k (Bai 265): ");
	scanf("%d", &k);
	int i;
	for (i = len_mang; i > k; --i)
	{
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
	len_mang++;
}

void nhap_giam_dan(float arr[], int &len_mang) // Bai 267
{
	nhap_mang(arr, len_mang);
	sap_xep_giam(arr, len_mang);
}

void them_bao_toan(float x, float arr[], int &len_mang) // Bai 269
{
	arr[len_mang] = x;
	len_mang++;
	sap_xep_tang(arr, len_mang);
}

void xoa_ptu_cs(int k, float arr[], int &len_mang) // Bai 271
{
	int i;
	for (i = k; i < len_mang - 1; ++i)
		arr[i] = arr[i + 1];
	len_mang--;
} 

void xoa_lon_nhat(float arr[], int &len_mang) // Bai 272
{
	float max = lon_nhat(arr, len_mang);
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] == max)
		{
			xoa_ptu_cs(i, arr, len_mang);
			--i;
		}
	}
}

void xoa_trung(float arr[], int &len_mang) // Bai 278
{
	int i, j;
	for (i = 0; i < len_mang; ++i)
	{
		for (j = i + 1; j < len_mang; ++j)
		{
			if (arr[i] == arr[j])
			{
				xoa_ptu_cs(j, arr, len_mang);
				--i;
			}
		}
	}
}

void xoa_trung_tat_ca(float arr[], int &len_mang) // Bai 279
{
	int i, j;
	float tam;
	for (i = 0; i < len_mang; ++i)
	{
		if (tan_suat(arr[i], arr, len_mang) > 1)
		{
			tam = arr[i];
			xoa_ptu_cs(i, arr, len_mang);
			--i;
			for (j = i; j < len_mang; ++j)
			{
				if (arr[j] == tam)
				{
					xoa_ptu_cs(j, arr, len_mang);
					--j;
				}
			}
		}
	}
}

void dao_nguoc(float arr[], int len_mang) // Bai 283
{
	int i, j;
	float tam;
	for (i = 0, j = len_mang - 1; i < j; ++i, --j)
	{
		tam = arr[i];
		arr[i] = arr[j];
		arr[j] = tam;
	}
}

void nguyen_hoa(float arr[], int len_mang) // Bai 292
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		arr[i] = round(arr[i]);
	}
}

int count_bit_1(int n)
{
	int dem = 0;
	while (n > 0)
	{
		if (n & 1)
			++dem;
		n >>= 1;
	}
	return dem;
}

void xuat_day(float arr[], int len_mang)
{
	int i;
	printf("{");
	for (i = 0; i < len_mang; ++i)
		printf("%0.2f, ", arr[i]);
	printf("}\n");
}

void lke_con_tang(float arr[], int &len_mang) // Bai 295
{
	xoa_trung(arr, len_mang);
	float mang_tam[MAX];
	int len_mang_tam, n, i, j;
	for (i = 0, n = 1; i < len_mang; ++i)
		n *= 2;
	for (i = 1; i < n; ++i)
	{
			len_mang_tam = 0;
			for (j = 0; j < len_mang; ++j)
			{
				if (i >> j & 1)
					mang_tam[len_mang_tam++] = arr[j];
			}
			sap_xep_tang(mang_tam, len_mang_tam);
			xuat_day(mang_tam, len_mang_tam);
	}
}

void lke_con_lon_nhat(float arr[], int &len_mang) // Bai 296
{
	xoa_trung(arr, len_mang);
	float mang_tam[MAX];
	int len_mang_tam, n, i, j;
	float max = lon_nhat(arr, len_mang);
	xoa_lon_nhat(arr, len_mang);
	for (i = 0, n = 1; i < len_mang; ++i)
		n *= 2;
	for (i = 0; i < n; ++i)
	{
		len_mang_tam = 0;
		mang_tam[len_mang_tam++] = max;
		for (j = 0; j < len_mang; ++j)
		{
			if (i >> j & 1)
				mang_tam[len_mang_tam++] = arr[j];
		}
		sap_xep_tang(mang_tam, len_mang_tam);
		xuat_day(mang_tam, len_mang_tam);
	}
}

void tao_mang_am(float arr1[], int len1, float arr2[], int &len2) // Bai 308
{
	int i;
	len2 = 0;
	for (i = 0; i < len1; ++i)
	{
		if (arr1[i] < 0)
			arr2[len2++] = arr1[i];
	}
	xoa_trung(arr2, len2);
}

void tao_mang_lan_can(float arr1[], int len1, float arr2[], int &len2) // Bai 309
{
	int i = 0;
	len2 = 0;
	arr2[len2++] = arr1[1];
	for (i = 1; i < len1 - 1; ++i)
	{
		arr2[len2++] = arr1[i - 1] + arr1[i + 1];
	}
	arr2[len2++] = arr1[len1 - 2];
}

