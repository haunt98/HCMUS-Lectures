#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef bool(*SoSanh)(int, int);

bool tang_dan(int, int);
bool giam_dan(int, int);
bool chan_tang_le_giam(int, int);
// dua so le len truoc
bool chan_tang_le_giam_vi_tri(int, int);

void SapXep(int *, int, SoSanh);

void in_kq(int *, int,FILE *);

int main(int argc,char *argv[])
{
	if (argc != 4)
		cout << "Cau lenh: SapXep 'Ten file input' 'Ten file output' '1-4'" << endl;
	else
	{
		FILE *f_in = fopen(argv[1], "r");
		if (!f_in)
			return EXIT_FAILURE;
		FILE *f_out = fopen(argv[2], "w");

		int kieuSapXep = atoi(argv[3]);
		if (kieuSapXep<1 || kieuSapXep>4)
		{
			cout << "Chon kieu sap xep tu 1-4" << endl;
			return EXIT_FAILURE;
		}

		int size; fscanf(f_in, "%d", &size);
		int *arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			fscanf(f_in, "%d", &arr[i]);
		}
		
		switch (kieuSapXep)
		{
		case 1:
			SapXep(arr, size, tang_dan);
			break;
		case 2:
			SapXep(arr, size, giam_dan);
			break;
		case 3:
			SapXep(arr, size, chan_tang_le_giam);
			break;
		case 4:
			SapXep(arr, size, chan_tang_le_giam_vi_tri);
			break;
		default:
			break;
		}
		in_kq(arr, size, f_out);

		delete[]arr; 
		fclose(f_in); fclose(f_out);
	}

	return 0;
}

bool tang_dan(int x, int y)
{
	return x < y;
}
bool giam_dan(int x, int y)
{
	return x > y;
}
bool chan_tang_le_giam(int x, int y)
{
	if (x%2==0 && y%2==0) // chan tang
		return x < y;
	if (x%2!=0 && y%2!=0) // le giam
		return x > y;
	return true;
}
bool chan_tang_le_giam_vi_tri(int x, int y)
{
	if (x % 2 == 0 && y % 2 == 0) 
		return x < y;
	if (x % 2 != 0 && y % 2 != 0) 
		return x > y;
	if (x % 2 == 0 && y % 2 != 0)
		return false;
	return true;
}
void SapXep(int *arr, int size, SoSanh T)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (!T(arr[i], arr[j])) // khong dung dieu kien
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void in_kq(int *arr, int size,FILE *f)
{
	for (int i = 0; i < size; i++)
		fprintf(f, "%d ", arr[i]);
}