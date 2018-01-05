#include "ham.h"

void replaceChar(char *filename, char ch_old, char ch_new)
{
	fstream f(filename, ios::in | ios::out);
	if (!f) {
		cout << "No File" << endl;
		return;
	}
	char c;
	while (f.get(c)) {
		if (c == ch_old) {
			// point to read
			int64_t pos = f.tellg();
			pos--;
			// point to write
			f.seekp(pos);
			f.put(ch_new);
			// reset point
			f.seekg(pos + 1);
		}
	}
	f.close();
}

void copyFile(char *file_from, char *file_to)
{
	ifstream f_from(file_from);
	ofstream f_to(file_to);
	char c;
	while (f_from.get(c))
		f_to.put(c);
	f_from.close();
	f_to.close();
}

bool isBigger(PhanSo A, PhanSo B)
{
	PhanSo TempA = A, TempB = B;
	if (TempA.mau < 0) {
		TempA.tu = -TempA.tu;
		TempA.mau = -TempA.mau;
	}
	if (TempB.mau < 0) {
		TempB.tu = -TempB.tu;
		TempB.mau = -TempB.mau;
	}

	if (TempA.tu * TempB.mau > TempA.mau * TempB.tu)
		return true;
	return false;
}

void sortPhanSo(listPhanSo A, ConditionSort Condt_Sort)
{
	PhanSo Temp;
	for (int i = 0; i < A.size - 1; ++i)
		for (int j = i + 1; j < A.size; ++j)
			if (Condt_Sort(A.list[i], A.list[j])) {
				Temp = A.list[i];
				A.list[i] = A.list[j];
				A.list[j] = Temp;
			}
}

void sortFilePhanSo(char *file_from, char *file_to)
{
	ifstream f_from(file_from);
	ofstream f_to(file_to);
	listPhanSo Data;
	Data.size = 0;
	Data.list = NULL;
	int m, n;
	while (f_from >> m >> n) {
		Data.list = (PhanSo *)realloc(Data.list,
					      (Data.size + 1) * sizeof(PhanSo));
		Data.list[Data.size].tu = m;
		Data.list[Data.size].mau = n;
		++Data.size;
	}
	sortPhanSo(Data, isBigger);
	for (m = 0; m < Data.size; ++m)
		f_to << Data.list[m].tu << " " << Data.list[m].mau << endl;
}

void ThongKe(char *file_from, char *file_to)
{
	int alphabet[26] = {0};
	ifstream f_from(file_from);
	ofstream f_to(file_to);
	char c;
	while (f_from.get(c)) {
		if (isalpha(c)) {
			c = tolower(c);
			++alphabet[c - 'a'];
		}
	}
	for (int i = 0; i < 26; ++i)
		if (alphabet[i])
			f_to << (char)('a' + i) << " : " << alphabet[i] << endl;
}