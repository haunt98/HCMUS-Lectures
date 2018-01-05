#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <inttypes.h>
#include <iostream>
using namespace std;

struct PhanSo {
	int tu, mau;
};

typedef PhanSo *ConTroPhanSo;

struct listPhanSo {
	ConTroPhanSo list;
	int size;
};

typedef bool (*ConditionSort)(PhanSo, PhanSo);

void replaceChar(char *filename, char ch_old, char ch_new);

void copyFile(char *file_from, char *file_to);

bool isBigger(PhanSo A, PhanSo B);

void sortPhanSo(listPhanSo A, ConditionSort Condt_Sort);

void sortFilePhanSo(char *file_from, char *file_to);

void ThongKe(char *file_from, char *file_to);