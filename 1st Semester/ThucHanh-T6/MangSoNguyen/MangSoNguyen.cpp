#include "MangSoNguyen.h"

void nhap_mang(int arr[], int &len_mang) // Bai 129
{
	int i;
	
	do{
		printf("Nhap do dai mang: ");
		scanf("%d", &len_mang);
	}while(len_mang < 1);
	
	for(i = 0; i < len_mang; ++i)
	{
		printf("Nhap gia tri mang tai vi tri thu %d: ", i);
		scanf("%d",&arr[i]);
	}
}

void xuat_mang(int arr[], int len_mang) // Bai 131
{
	int i;
	for(i = 0; i < len_mang; ++i)
	{
		printf("Gia tri mang tai vi tri thu %d: %d\n", i, arr[i]);
	}

}

int la_nguyen_to(int n)
{
	int i;
	if (n < 2)
		return 0;
	for(i = 2; i <= sqrt((double)n); ++i)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int nguyen_to_dau(int arr[], int len_mang) // Bai 144
{
	int i;
	for(i = 0; i < len_mang; ++i)
	{
		if(arr[i] > 0 && la_nguyen_to(arr[i]))
			return arr[i];
	}
	return -1;
}

int nguyen_to_lon_nhat(int arr[], int len_mang) // Bai 151
{
	int i;
	int p_max = nguyen_to_dau(arr, len_mang);
	for(i = 0; i < len_mang; ++i)
	{
		if(arr[i] > p_max && la_nguyen_to(arr[i]))
			p_max = arr[i];
	}
	if(p_max == -1)
		return 0;
	return p_max;
}

int dau_tien_trong_doan(int x, int y, int arr[], int len_mang) // Bai 161
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] > x && arr[i] < y)
			return arr[i];
	}
	return x;
}

int dau_le(int n)
{
	int tam = n;
	if (tam < 0)
		tam = -tam;
	while (tam > 10)
		tam = tam / 10;
	if (tam % 2 != 0)
		return 1;
	return 0;
}

int dau_le_dau_tien(int arr[], int len_mang) // Bai 165
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (dau_le(arr[i]))
			return arr[i];
	}
	return 0;
}

int la_2_k(int n)
{
	int flag = 1;
	int n_tam = n;
	while (n_tam > 0)
	{
		if (n_tam % 2 == 0)
			n_tam = n_tam / 2;
		else if (n_tam == 1)
			break;
		else
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

int dau_2_k(int arr[], int len_mang) // Bai 166
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (la_2_k(arr[i]))
			return arr[i];
	}
	return 0;
}

int le_dau_tien(int arr[], int len_mang)
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 != 0)
			return arr[i];
	}
	return 0;
}

int chan_nho_le(int arr[], int len_mang) // Bai 169
{
	int i;
	int min_le = le_dau_tien(arr, len_mang);
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 != 0 && arr[i] < min_le)
			min_le = arr[i];
	}
	return min_le - 1;
}

int lon_nhat_mang(int arr[], int len_mang)
{
	int i;
	int max = arr[0];
	for (i = 1; i < len_mang; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int snt_nho(int arr[], int len_mang) // Bai 170
{
	int snt;
	for (snt = lon_nhat_mang(arr, len_mang) + 1;; ++snt)
	{
		if (la_nguyen_to(snt))
			return snt;
	}
}

int ucln(int a, int b) // UCLN cua a va b
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	while (a > 0 && b > 0)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	if (a == 0)
		return b;
	return a;
}

int uoc_chung(int arr[], int len_mang) // Bai 171
{
	int i;
	int uoc = arr[0];
	for (i = 1; i < len_mang; ++i)
	{
		uoc = ucln(uoc, arr[i]);
	}
	return uoc;
}

int bcnn(int a, int b) // BCNN cua a va b
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return a*b / ucln(a, b);
}

int boi_chung(int arr[], int len_mang) // Bai 172
{
	int i;
	int boi = arr[0];
	for (i = 1; i < len_mang; ++i)
	{
		boi = bcnn(boi, arr[i]);
	}
	return boi;
}

int tim_chu_so(int arr[], int len_mang) // Bai 173
{
	int index[10] = { 0 }; // co 10 chu so tu 0 -> 9
	int i;
	int tam;
	
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] == 0)
			++index[0];
		tam = arr[i];
		while (tam > 0)
		{
			++index[tam % 10];
			tam = tam / 10;
		}
	}

	int vt_min = 0;
	for (i = 0; i < 10; ++i)
	{
		if (index[i] < index[vt_min])
			vt_min = i;
	}
	return vt_min;
}

void lke_doan(int x, int y, int arr[], int len_mang) // Bai 177
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] >= x && arr[i] <= y)
			printf("%d, ", arr[i]);
	}
	printf("\n");
}

void lke_180(int arr[], int len_mang) // Bai 180
{
	printf("Cac gia tri nho hon tri tuyet doi gia tri lien sau va lon hon gia tri lien truoc: ");
	int i;
	for (i = 1; i < len_mang - 1; ++i)
	{
		if (arr[i] < abs(arr[i + 1]) && arr[i] > arr[i - 1])
			printf("%d, ", arr[i]);
	}
	printf("\n");
}

void chan_lan_can(int arr[], int len_mang) // Bai 181
{
	printf("Cac gia tri chan co it nhat 1 lan can chan: ");
	int i = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (i == 0)
		{
			if (arr[i + 1] % 2 == 0)
				printf("%d, ", arr[i]);
		}
		else if (i == len_mang - 1)
		{
			if (arr[i - 1] % 2 == 0)
				printf("%d, ", arr[i]);
		}
		else
		{
			if (arr[i] % 2 == 0 && (arr[i - 1] % 2 == 0 || arr[i + 1] % 2 == 0))
				printf("%d, ", arr[i]);
		}
	}
	printf("\n");
}

void lke_vtri_nguyento(int arr[], int len_mang) // Bai 184
{
	int i;
	printf("Cac vi tri ma tai do la so nguyen to: ");
	for (i = 0; i < len_mang; ++i)
	{
		if (la_nguyen_to(arr[i]))
			printf("%d, ", i + 1);
	}
	printf("\n");
}

void lke_dau_le(int arr[], int len_mang) // Bai 189
{
	int i;
	printf("Cac vi tri co gia tri la cac so nguyen co chu so dau tien la so le: ");
	for (i = 0; i < len_mang; ++i)
	{
		if (dau_le(arr[i]))
			printf("%d, ", i + 1);
	}
	printf("\n");
}

void gan_nhau_nhat(int arr[], int len_mang) // Bai 194
{
	int min = abs(arr[0] - arr[1]);
	int i, j;
	for (i = 0; i < len_mang - 1; ++i)
	{
		for (j = i + 1; j < len_mang; ++j)
		{
			if (abs(arr[i] - arr[j]) < min)
				min = abs(arr[i] - arr[j]);
		}
	}
	printf("Cac cap gia tri gan nhau nhat: ");
	for (i = 0; i < len_mang - 1; ++i)
	{
		for (j = i + 1; j < len_mang; ++j)
		{
			if (abs(arr[i] - arr[j]) == min)
				printf("(%d,%d) ", arr[i], arr[j]);
		}
	}
}

int tong(int arr[], int len_mang) // Bai 200
{
	int sum = 0;
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

int tong_chuc_5(int arr[], int len_mang) // Bai 203
{
	int i, tam, sum;
	sum = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] < 0)
			tam = -arr[i];
		else
			tam = arr[i];
		if ((tam / 10) % 10 == 5)
			sum += arr[i];
	}
	return sum;
}

float tb_nguyento(int arr[], int len_mang) // Bai 211
{
	int sum, dem, i;
	sum = 0; dem = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (la_nguyen_to(arr[i]))
		{
			sum += arr[i];
			dem++;
		}
	}
	float tbc = (float)sum / (float)dem;
	return tbc;
}

int dem_chan(int arr[], int len_mang) // Bai 216
{
	int dem = 0;
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 == 0)
			++dem;
	}
	return dem;
}

int tuong_quan_chan_le(int arr[], int len_mang) // Bai 221
{
	int dem_chan, dem_le, i;
	dem_chan = 0; dem_le = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 == 0)
			++dem_chan;
		else
			++dem_le;
	}
	if (dem_chan == dem_le)
		return 0;
	else if (dem_chan > dem_le)
		return -1;
	else
		return 1;
}

void dem_cuc_tri(int arr[], int len_mang) // Bai 222
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

int dem_nguyento(int arr[], int len_mang) //Bai 223
{
	int i, dem;
	dem = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (la_nguyen_to(arr[i]))
			++dem;
	}
	return dem;
}

int dem_trai_dau(int arr[], int len_mang) // Bai 227
{
	int i, dem;
	dem = 0;
	for (i = 0; i < len_mang - 1; ++i)
	{
		if (arr[i] * arr[i + 1] < 0)
			++dem;
	}
	return dem;
}

int dem_gia_tri(int arr[], int len_mang) // Bai 228
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

int tan_suat(int x, int arr[], int len_mang) 
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

int dem_phan_biet(int arr[], int len_mang) // Bai 229 
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

void lke_duy_nhat(int arr[], int len_mang) // Bai 231
{
	int i;
	printf("Cac gia tri xuat hien trong mang dung 1 lan: ");
	for (i = 0; i < len_mang; ++i)
	{
		if (tan_suat(arr[i], arr, len_mang) == 1)
			printf("%d, ", arr[i]);
	}
	printf("\n");

}

void lke_khong_duy_nhat(int arr[], int len_mang) // Bai 232
{
	int i, n_len = 0;
	int mang_tam[MAX];
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
		printf("%d, ", mang_tam[i]);
	}
	printf("\n");
}

void lke_tan_suat(int arr[], int len_mang) // Bai 233
{
	int i, n_len;
	int mang_tam[MAX];
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
		printf("%d           %d\n", mang_tam[i], tan_suat(mang_tam[i], arr, len_mang));
	}
}

void lke_nhieu_nhat(int arr[], int len_mang) // Bai 238
{
	int mang_tam[MAX];
	int i, max, n_len;
	n_len = 0;
	for (i = 0; i < len_mang; ++i) // Xoa trung lap trong mang
	{
		if (tan_suat(arr[i], mang_tam, n_len) == 0)
			mang_tam[n_len++] = arr[i];
	}
	max = tan_suat(mang_tam[0], arr, len_mang);
	for (i = 1; i < n_len; ++i)
	{
		if (tan_suat(mang_tam[i], arr, len_mang) > max) // Tim so lan xuat hien nhieu nhat
			max = tan_suat(mang_tam[i], arr, len_mang);
	}
	printf("Cac gia tri co so lan xuat hien nhieu nhat: ");
	for (i = 0; i < n_len; ++i)
	{
		if (tan_suat(mang_tam[i], arr, len_mang) == max)
			printf("%d, ", mang_tam[i]);
	}
	printf("\n");
}

int dem_nguyento_phanbiet(int arr[], int len_mang) // Bai 239
{
	int mang_tam[MAX];
	int i, dem, n_len;
	dem = 0; n_len = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (tan_suat(arr[i], mang_tam, n_len) == 0) // Xoa trung lap trong mang
			mang_tam[n_len++] = arr[i];
	}
	for (i = 0; i < n_len; ++i)
	{
		if (la_nguyen_to(mang_tam[i]))
			++dem;
	}
	return dem;
}

int ton_tai_khong(int arr[], int len_mang) // Bai 240
{
	int i, flag;
	flag = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (arr[i] == 0)
			flag = 1;
	}
	return flag;
}

int hai_khong(int arr[], int len_mang) // Bai 241
{
	int i, flag;
	flag = 0;
	for (i = 0; i < len_mang - 1; ++i)
	{
		if (arr[i] == 0 && arr[i + 1] == 0)
			flag = 1;
	}
	return flag;
}

int ton_tai_nguyento(int arr[], int len_mang) // Bai 243
{
	int i, flag;
	flag = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (la_nguyen_to(arr[i]))
			flag = 1;
	}
	return flag;
}

int la_hoan_thien(int n) // Kiem tra so hoan thien
{
	int tong_uoc, i;
	if (n < 1)
		return 0;
	for (tong_uoc = 0, i = 1; i < n; ++i)
	{
		if (n%i == 0)
			tong_uoc += i;
	}
	if (tong_uoc == n)
		return 1;
	return 0;
}

int ktra_tinh_chat(int arr[], int len_mang) // Bai 244
{
	int i, flag;
	flag = 0;
	for (i = 0; i < len_mang; ++i)
	{
		if (!la_hoan_thien(arr[i]) || arr[i] <= 256)
			flag = 1;
	}
	return flag;
}

int ktra_chan_le(int arr[], int len_mang) // Bai 247
{
	int i, flag;
	flag = 1;
	for (i = 0; i < len_mang - 1; ++i)
	{
		if ((arr[i] + arr[i + 1])%2 == 0)
			flag = 0;
	}
	return flag;
}

int tang_dan(int arr[], int len_mang) // Bai 248
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

void cap_so_cong(int arr[], int len_mang) // Bai 250
{
	int i, flag;
	flag = 1;
	if (len_mang == 1)
		flag = 0;
	else
	{
		for (i = 0; i < len_mang-2; ++i)
		{
			if (arr[i] + arr[i + 2] != 2 * arr[i + 1])
				flag = 0;
		}
	}
	if (flag == 0)
		printf("Khong phai cap so cong.\n");
	else
		printf("Lap thanh cap so cong voi cong sai: %d\n", arr[1] - arr[0]);
}

int ktra_bang_nhau(int arr[], int len_mang) // Bai 251
{
	int i, flag;
	flag = 1;
	for (i = 0; i < len_mang - 1; ++i)
	{
		if (arr[i] != arr[i + 1])
			flag = 0;
	}
	return flag;
}

int ktra_dang_song(int arr[], int len_mang) // Bai 252
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

int ktra_a_trong_b(int arr1[], int len_1, int arr2[], int len_2) // Bai 253
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

int dem_lon_truoc(int arr[], int len_mang) // Bai 254
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

void sap_xep_giam(int arr[], int len_mang) // Bai 256
{
	int i, j;
	int tam;
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

void sap_xep_tang(int arr[], int len_mang) 
{
	int i, j;
	int tam;
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
		arr[j] = tam;
	}
}

void vtri_le_tang(int arr[], int len_mang) // Bai 257
{
	int len_mang_tam, i, j;
	int mang_tam[MAX];
	for (len_mang_tam = 0, i = 0; i < len_mang; ++i)
	{
		if (i % 2 != 0)
			mang_tam[len_mang_tam++] = arr[i];
	}
	sap_xep_tang(mang_tam,len_mang_tam);
	for (j = 0, i = 0; i < len_mang; ++i)
	{
		if (i % 2 != 0)
			arr[i] = mang_tam[j++];
	}
	printf("Vi tri le tang dan\n");
	xuat_mang(arr, len_mang);
}

void nguyento_tang(int arr[], int len_mang) // Bai 258
{
	int len_mang_tam, i, j;
	int mang_tam[MAX];
	for (len_mang_tam = 0, i = 0; i < len_mang; ++i)
	{
		if (la_nguyen_to(arr[i]))
			mang_tam[len_mang_tam++] = arr[i];
	}
	sap_xep_tang(mang_tam, len_mang_tam);
	for (i = 0, j = 0; i < len_mang; ++i)
	{
		if (la_nguyen_to(arr[i]))
			arr[i] = mang_tam[j++];
	}
	printf("Cac so nguyen to trong mang tang dan\n");
	xuat_mang(arr, len_mang);
}

void hoan_thien_giam(int arr[], int len_mang) // Bai 259
{
	int len_mang_tam, i, j;
	int mang_tam[MAX];
	for (len_mang_tam = 0, i = 0; i < len_mang; ++i)
	{
		if (la_hoan_thien(arr[i]))
			mang_tam[len_mang_tam++] = arr[i];
	}
	sap_xep_giam(mang_tam, len_mang_tam);
	for (i = 0, j = 0; i < len_mang; ++i)
	{
		if (la_hoan_thien(arr[i]))
			arr[i] = mang_tam[j++];
	}
	printf("Cac so hoan thien trong mang giam dan\n");
	xuat_mang(arr, len_mang);
}

int ktra_hoanvi(int arr1[], int len1, int arr2[], int len2) // Bai 260
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

void sx_chan_le(int arr[], int len_mang) // Bai 262
{
	int mang_chan[MAX], mang_le[MAX];
	int len_chan, len_le;
	int i, j, k;
	for (len_chan = 0, len_le = 0, i = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 == 0)
			mang_chan[len_chan++] = arr[i];
		else
			mang_le[len_le++] = arr[i];
	}
	sap_xep_tang(mang_chan, len_chan); sap_xep_tang(mang_le, len_le);
	for (i = 0, j = 0, k = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 == 0)
			arr[i] = mang_chan[j++];
		else
			arr[i] = mang_le[k++];
	}
	printf("Sap xep chan tang va le tang:\n");
	xuat_mang(arr, len_mang);
}

void nhap_bao_toan(int arr[], int &len_mang) // Bai 270
{
	nhap_mang(arr, len_mang);
	sap_xep_tang(arr, len_mang);
}

void xoa_ptu_cs(int k, int arr[], int &len_mang) // Bai 271
{
	int i;
	for (i = k; i < len_mang - 1; ++i)
		arr[i] = arr[i + 1];
	len_mang--;
}

void xoa_nguyento(int arr[], int &len_mang) // Bai 277
{
	int i;
	for (i = 0; i < len_mang; ++i)
	{
		if (la_nguyen_to(arr[i]))
		{
			xoa_ptu_cs(i, arr, len_mang);
			--i;
		}
	}
}

void xoa_trung(int arr[], int &len_mang) // Bai 278
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

void xoa_trung_tat_ca(int arr[], int &len_mang) // Bai 279
{
	int i, j;
	int tam;
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

void dao_nguoc(int arr[], int len_mang) // Bai 283
{
	int i, j;
	int tam;
	for (i = 0, j = len_mang - 1; i < j; ++i, --j)
	{
		tam = arr[i];
		arr[i] = arr[j];
		arr[j] = tam;
	}
}

void dao_chan(int arr[], int len_mang) // Bai 284
{
	int mang_chan[MAX];
	int i, j, len_mang_chan;
	for (len_mang_chan = 0, i = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 == 0)
			mang_chan[len_mang_chan++] = arr[i];
	}
	dao_nguoc(mang_chan, len_mang_chan);
	for (j = 0, i = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 == 0)
			arr[i] = mang_chan[j++];
	}
}

void chan_le_2hang(int arr[], int len_mang) // Bai 289
{
	int i, len_chan, len_le;
	int mang_chan[MAX], mang_le[MAX];
	for (len_chan = 0, len_le = 0, i = 0; i < len_mang; ++i)
	{
		if (arr[i] % 2 == 0)
			mang_chan[len_chan++] = arr[i];
		else
			mang_le[len_le++] = arr[i];
	}
	printf("So chan: ");
	for (i = 0; i < len_chan; ++i)
		printf("%d ", mang_chan[i]);
	printf("\nSo le: ");

	for (i = 0; i < len_le; ++i)
		printf("%d ", mang_le[i]);
	printf("\n");
}

void liet_ke_con(int arr[], int &len_mang) // Bai 293
{
	xoa_trung(arr, len_mang);
	int n, i, j;
	for (i = 0, n = 1; i < len_mang; ++i)
		n *= 2;
	printf("Cac tap hop con cua mang:\n");
	for (i = 0; i < n; ++i) // i : list of subset
	{
		printf("{");
		for (j = 0; j < len_mang; ++j) // j: list of element
			if (i >> j & 1)
				printf("%d, ", arr[j]);
				
		printf("}\n");
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

void con_lon_hon2(int arr[], int &len_mang) // Bai 294
{
	xoa_trung(arr, len_mang);
	int n, i, j;
	for (i = 0, n = 1; i < len_mang; ++i)
		n *= 2;
	printf("Tap con co do dai > 2:\n");
	for (i = 0; i < n; ++i)
	{
		if (count_bit_1(i) > 2)
		{
			printf("{");
			for (j = 0; j < len_mang; ++j) // j: list of element
				if (i >> j & 1)
					printf("%d, ", arr[j]);

			printf("}\n");
		}
	}
}

void tao_mang_le(int arr1[], int len1, int arr2[], int &len2) // Bai 307
{
	int i;
	len2 = 0;
	for (i = 0; i < len1; ++i)
	{
		if (arr1[i] % 2 != 0)
			arr2[len2++] = arr1[i];
	}
	xoa_trung(arr2, len2);
}

void tao_mang_nguyento(int arr1[], int len1, int arr2[], int &len2) // Bai 310
{
	int i;
	len2 = 0;
	for (i = 0; i < len1; ++i)
	{
		if (la_nguyen_to(arr1[i]))
			arr2[len2++] = arr1[i];
	}
	xoa_trung(arr2, len2);
}