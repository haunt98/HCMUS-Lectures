#include <iostream>
#define MAXN 100 // So phan tu toi da cua mang
#define MAXM 1000 // so tien toi da dung de doi
#define INFINITE 1000000
using namespace std;

int main()
{
	int N, money; // n la so phan tu cua mang, m la so tien can doi
	int a[MAXN]; // Mang luu cac to tien
	int f[MAXM]; // f[x] co y nghia la so to tien it nhat de doi n dong
	int track[MAXM]; // trace[x] co y nghia la de doi x dong thi phai dung to thu trace[x]
	// Nhap
	cout << "Nhap so phan tu mang: ";
	cin >> N;
	cout << "Nhap mang: ";
	for (int i = 0; i < N; i++)
		cin >> a[i];
	cout << "Nhap so tien can doi: ";
	cin >> money;
	for (int i = 0; i <= money; i++)
		f[i] = INFINITE; // Ban dau gan f[x] = VC;
	f[0] = 0; // So to de doi 0 dong la 0
	// Bottom-up, tinh cac f[x]
	for (int i = 0; i <= money; i++)
	{
		for (int j = 0; j < N; j++)
			if (i - a[j] >= 0 && (f[i - a[j]] != INFINITE))
			{ // kiem tra xem co the dung to thu j (thuoc mang a) de doi hay khong
				if (f[i] > f[i - a[j]] + 1)
				{
					f[i] = f[i - a[j]] + 1; // Toi uu so to doi,
					track[i] = j; // Luu vet, de doi i dong can dung to thu j
				}
			}
	}
	if (f[money] == INFINITE)
		cout << "Khong co cach doi!\n";
	else
	{
		cout << "So to toi thieu: " << f[money] << endl;
		cout << "Cac to dung de doi: ";
		while (money != 0)
		{
			cout << a[track[money]] << " ";  // Lan luot luu vet ve 0
			money = money - a[track[money]];
		}
	}

	return 0;
}