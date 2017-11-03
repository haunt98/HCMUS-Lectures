#include "xuly.h"

void nhap_mang(int arr[MAX][MAX], int &hang, int &cot)
{
	int i, j;
	do {
		printf("Nhap hang va cot: ");
		scanf("%d %d", &hang, &cot);
	} while (hang <= 0 && cot <= 0);
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < cot; ++j)
		{
			printf("Vi tri[%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

void xuat_mang(int arr[MAX][MAX], int hang, int cot)
{
	int i, j;
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < cot; ++j)
		{
			printf("%-6d ", arr[i][j]);
		}
		printf("\n");
	}
}

int tong(int arr[MAX][MAX], int hang, int cot)
{
	int i, j, sum;
	sum = 0;
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < cot; ++j)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

int tan_suat(int x, int arr[MAX][MAX], int hang, int cot)
{
	int i, j, dem;
	dem = 0;
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < cot; ++j)
		{
			if (arr[i][j] == x)
				++dem;
		}
	}
	return dem;
}

int tan_suat_duong(int arr[MAX][MAX], int hang, int cot)
{
	int i, j, dem;
	dem = 0;
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < cot; ++j)
		{
			if (arr[i][j] > 0)
				++dem;
		}
	}
	return dem;
}

void sap_xep_tang(int arr[], int len)
{
	int i, j, key;
	for (i = 1; i < len; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j > -1 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		++j;
		arr[j] = key;
	}
}

void sap_xep_giam(int arr[], int len)
{
	int i, j, key;
	for (i = 1; i < len; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j > -1 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		++j;
		arr[j] = key;
	}
}

void tang_cot_giam_hang(int arr[MAX][MAX], int hang, int cot)
{
	int mang_tam[MAX];
	int i, j, k, len_tam;

	//tang dan tren cot
	for (j = 0; j < cot; ++j)
	{
		for (len_tam = 0, i = 0; i < hang; ++i)
		{
			mang_tam[len_tam++] = arr[i][j];
		}
		sap_xep_tang(mang_tam, len_tam);
		for (k = 0, i = 0; i < hang; ++i)
		{
			arr[i][j] = mang_tam[k++];
		}
	}
	//giam dan tren hang
	for (i = 0; i < hang; ++i)
		sap_xep_giam(arr[i], cot);
}

void tang_hang_tang_cot(int arr[MAX][MAX], int hang, int cot)
{
	int mang_tam[MAX];
	int i, j, k, len_tam;

	//tang dan tren hang
	tang_hang(arr, hang, cot);

	//tang dan tren cot
	for (j = 0; j < cot; ++j)
	{
		for (len_tam = 0, i = 0; i < hang; ++i)
		{
			mang_tam[len_tam++] = arr[i][j];
		}
		sap_xep_tang(mang_tam, len_tam);
		for (k = 0, i = 0; i < hang; ++i)
		{
			arr[i][j] = mang_tam[k++];
		}
	}
}

int tong_khong_am(int arr[MAX][MAX], int hang, int cot)
{
	int i, j, sum;
	sum = 0;
	for (i = 0; i < hang; ++i)
		for (j = 0; j < cot; ++j)
			if (arr[i][j] >= 0)
				sum += arr[i][j];
	return sum;
}

int tong_cheo_chinh(int arr[MAX][MAX], int hang, int cot)
{
	int i, j, sum;
	sum = 0;
	for (i = 0, j = 0; i < hang && j < cot; ++i, ++j)
		sum += arr[i][j];
	return sum;
}

int tong_cheo_phu(int arr[MAX][MAX], int hang, int cot)
{
	int i, j, sum;
	sum = 0;
	for (i = 0, j = cot - 1; i < hang && j >= 0; ++i, --j)
		sum += arr[i][j];
	return sum;
}

void tang_hang(int arr[MAX][MAX], int hang, int cot)
{
	int i = 0;
	for (i = 0; i < hang; ++i)
		sap_xep_tang(arr[i], cot);
}

int tong_matran(int arr1[MAX][MAX], int hang1, int cot1, int arr2[MAX][MAX], int hang2, int cot2,
	int kqua[MAX][MAX], int &kqua_hang, int &kqua_cot)
{
	int i, j;
	if (hang1 != hang2 || cot1 != cot2)
		return 0;
	kqua_hang = hang1; kqua_cot = cot1;
	for (i = 0; i < hang1; ++i)
		for (j = 0; j < cot1; ++j)
			kqua[i][j] = arr1[i][j] + arr2[i][j];
	return 1;
}

int tich_matran(int arr1[MAX][MAX], int hang1, int cot1, int arr2[MAX][MAX], int hang2, int cot2,
	int kqua[MAX][MAX], int &kqua_hang, int &kqua_cot)
{
	int i, j, k;
	if (cot1 != hang2)
		return 0;
	
	kqua_hang = hang1; kqua_cot = cot2;
	for (i = 0; i < kqua_hang; ++i)
		for (j = 0; j < kqua_cot; ++j)
		{
			kqua[i][j] = 0;
			for (k = 0; k < cot1; ++k)
				kqua[i][j] += arr1[i][k] * arr2[k][j];
		}
	return 1;
}

void phai_90(int arr[MAX][MAX], int &hang, int &cot)
{
	int tam[MAX][MAX];
	int i, j;
	for (i = 0; i < hang; ++i)
		for (j = 0; j < cot; ++j)
			tam[j][hang - 1 - i] = arr[i][j];
	i = hang; hang = cot; cot = i;
	for (i = 0; i < hang; ++i)
		for (j = 0; j < cot; ++j)
			arr[i][j] = tam[i][j];
}

void trai_90(int arr[MAX][MAX], int &hang, int &cot)
{
	for (int i = 0; i < 3; ++i)
		phai_90(arr, hang, cot);
}

void xoay(int arr[MAX][MAX], int &hang, int &cot, int huong, int n)
{
	int i;
	if (huong == LEFT)
		for (i = 0; i < n; ++i)
			trai_90(arr, hang, cot);
	else
		for (i = 0; i < n; ++i)
			phai_90(arr, hang, cot);
}

void xoa_hang(int vt_hang, int arr[MAX][MAX], int &hang, int &cot)
{
	if (vt_hang >= hang || vt_hang < 0)
		return;
	int i, j;
	for (i = vt_hang; i < hang - 1; ++i)
		for (j = 0; j < cot; ++j)
			arr[i][j] = arr[i + 1][j];
	--hang;
}

void xoa_cot(int vt_cot, int arr[MAX][MAX], int hang, int &cot)
{
	if (vt_cot >= cot || vt_cot < 0)
		return;
	int i, j;
	for (i = 0; i < hang; ++i)
		for (j = vt_cot; j < cot - 1; ++j)
			arr[i][j] = arr[i][j + 1];
	--cot;
}

void xoa_trung(int arr1[MAX][MAX], int hang1, int cot1, int arr2[MAX][MAX], int hang2, int cot2)
{
	int i, j, a, b, c, d, key, flag;
	for (i = 0; i < hang1; ++i)
		for (j = 0; j < cot1; ++j)
		{
			key = arr1[i][j];
			flag = 0;
			for (a = 0; a < hang2; ++a)
				for (b = 0; b < cot2; ++b)
					if (arr2[a][b] == key)
					{
						flag = 1;
						arr2[a][b] = 0;
					}
			if (flag == 1)
				for (c = 0; c < hang1; ++c)
					for (d = 0; d < cot1; ++d)
						if (arr1[c][d] == key)
							arr1[c][d] = 0;
		}
}

void lon_nhat(int arr[MAX][MAX], int hang, int cot)
{
	int i, j, max_all, max;
	max_all = arr[0][0];
	for (i = 0; i < hang; ++i)
		for (j = 0; j < cot; ++j)
			if (arr[i][j] > max_all)
				max_all = arr[i][j];
	printf("Phan tu lon nhat tren toan ma tran: %d\n", max_all);
	for (i = 0; i < hang; ++i)
	{
		max = arr[i][0];
		for (j = 0; j < cot; ++j)
			if (arr[i][j] > max)
				max = arr[i][j];
		printf("Phan tu lon nhat tren dong %d: %d\n", i, max);
	}
	for (j = 0; j < cot; ++j)
	{
		max = arr[0][j];
		for (i = 0; i < hang; ++i)
			if (arr[i][j] > max)
				max = arr[i][j];
		printf("Phan tu lon nhat tren cot %d: %d\n", j, max);
	}
}

void nho_nhat(int arr[MAX][MAX], int hang, int cot)
{
	int i, j, min_all, min;
	min_all = arr[0][0];
	for (i = 0; i < hang; ++i)
		for (j = 0; j < cot; ++j)
			if (arr[i][j] < min_all)
				min_all = arr[i][j];
	printf("Phan tu nho nhat tren toan ma tran: %d\n", min_all);
	for (i = 0; i < hang; ++i)
	{
		min = arr[i][0];
		for (j = 0; j < cot; ++j)
			if (arr[i][j] < min)
				min = arr[i][j];
		printf("Phan tu nho nhat tren dong %d: %d\n", i, min);
	}
	for (j = 0; j < cot; ++j)
	{
		min = arr[0][j];
		for (i = 0; i < hang; ++i)
			if (arr[i][j] < min)
				min = arr[i][j];
		printf("Phan tu nho nhat tren cot %d: %d\n", j, min);
	}
}

void matran_tong(int arr[MAX][MAX], int &hang, int &cot)
{
	int arr1[MAX][MAX], arr2[MAX][MAX];
	int hang1, cot1, hang2, cot2;
	nhap_mang(arr1, hang1, cot1);
	nhap_mang(arr2, hang2, cot2);
	printf("Tong 2 ma tran da nhap:\n");
	tong_matran(arr1, hang1, cot1, arr2, hang2, cot2, arr, hang, cot);
	xuat_mang(arr, hang, cot);
}

void matran_tich(int arr[MAX][MAX], int &hang, int &cot)
{
	int arr1[MAX][MAX], arr2[MAX][MAX];
	int hang1, cot1, hang2, cot2;
	nhap_mang(arr1, hang1, cot1);
	nhap_mang(arr2, hang2, cot2);
	printf("Tich 2 ma tran da nhap:\n");
	tich_matran(arr1, hang1, cot1, arr2, hang2, cot2, arr, hang, cot);
	xuat_mang(arr, hang, cot);
}

int tong1(int arr1[MAX][MAX], int hang1, int cot1, int arr2[MAX][MAX], int hang2, int cot2)
{
	int tam[MAX][MAX], hang, cot;
	if (!tong_matran(arr1, hang1, cot1, arr2, hang2, cot2, tam, hang, cot))
		return 0;
	tong_matran(arr1, hang1, cot1, arr2, hang2, cot2, tam, hang, cot);
	for (int i = 0; i < hang1; ++i)
		for (int j = 0; j < cot1; ++j)
			arr1[i][j] = tam[i][j];
	return 1;
}

int tong_n_mtran(int result[MAX][MAX], int &hang, int &cot)
{
	int n, i, j;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	} while(n < 1);
	
	int tam[MAX][MAX], hang_t, cot_t;

	printf("Nhap %d ma tran\n", n);

	nhap_mang(tam, hang_t, cot_t);
	hang = hang_t; cot = cot_t;
	
	for (i = 0; i < hang; ++i)
		for (j = 0; j < cot; ++j)
			result[i][j] = 0;
	tong1(result, hang, cot, tam, hang_t, cot_t);
	for (i = 0; i < n - 1; ++i)
	{
		nhap_mang(tam, hang_t, cot_t);
		if (hang_t != hang || cot_t != cot)
			return 0;
		tong1(result, hang, cot, tam, hang_t, cot_t);
	}
	return 1;
}

int tich1(int arr1[MAX][MAX], int &hang1, int &cot1, int arr2[MAX][MAX], int hang2, int cot2)
{
	int tam[MAX][MAX], hang, cot;
	if (!tich_matran(arr1, hang1, cot1, arr2, hang2, cot2, tam, hang, cot))
		return 0;
	tich_matran(arr1, hang1, cot1, arr2, hang2, cot2, tam, hang, cot);
	hang1 = hang; cot1 = cot;
	for (int i = 0; i < hang1; ++i)
		for (int j = 0; j < cot1; ++j)
			arr1[i][j] = tam[i][j];
	return 1;
}

int tich_n_mtran(int result[MAX][MAX], int &hang, int &cot)
{
	int n, i, j;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	} while (n < 1);

	int tam[MAX][MAX], hang_t, cot_t;
	int tam2[MAX][MAX], hang_2, cot_2;
	nhap_mang(tam, hang_t, cot_t);
	if (n >= 2)
	{
		nhap_mang(tam2, hang_2, cot_2);
		tich1(tam, hang_t, cot_t, tam2, hang_2, cot_2);
		for (i = 0; i < n - 2; ++i)
		{
			nhap_mang(tam2, hang_2, cot_2);
			if (cot_t != hang_2)
				return 0;
			tich1(tam, hang_t, cot_t, tam2, hang_2, cot_2);
		}
	}
	hang = hang_t; cot = cot_t;
	for (i = 0; i < hang; ++i)
		for (j = 0; j < cot; ++j)
			result[i][j] = tam[i][j];

	return 1;
}

void nhap_mang_r(float arr[MAX][MAX], int &hang, int &cot)
{
	int i, j;
	do {
		printf("Nhap hang va cot: ");
		scanf("%d %d", &hang, &cot);
	} while (hang <= 0 && cot <= 0);
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < cot; ++j)
		{
			printf("Vi tri[%d][%d]: ", i, j);
			scanf("%f", &arr[i][j]);
		}
	}
}

void xuat_mang_r(float arr[MAX][MAX], int hang, int cot)
{
	int i, j;
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < cot; ++j)
		{
			printf("%0.3f ", arr[i][j]);
		}
		printf("\n");
	}
}

int nghich_dao(float arr[MAX][MAX], int n, float result[MAX][MAX])
{
	int hang, cot, i;
	float d;

	// tao mang phu I ben canh 
	for (cot = n; cot < n * 2; ++cot)
		for (hang = 0; hang < n; ++hang)
		{
			if (hang == cot - n)
				arr[hang][cot] = 1;
			else
				arr[hang][cot] = 0;
		}

	//chuyen ve so 0 cac so khong thuoc duong cheo chinh
	for (cot = 0; cot < n; ++cot)
		for (hang = 0; hang < n;++hang)
			if (hang != cot)
			{
				d = arr[hang][cot] / arr[cot][cot];
				for (i = 0; i < 2 * n; ++i)
					arr[hang][i] -= arr[cot][i] * d;
			}
	
	//Lay ma tran nghich dao bang cach chia cho duong cheo chinh
	for (hang = 0; hang < n; ++hang)
	{
		d = arr[hang][hang];
		if (d == 0)
		{
			return 0;
		}
		else
			for (cot = 0; cot < 2 * n; ++cot)
				arr[hang][cot] /= d;
	}

	//chuyen ve mang result
	for (hang = 0; hang < n; ++hang)
		for (cot = 0; cot < n; ++cot)
			result[hang][cot] = arr[hang][cot + n];
	return 1;
}