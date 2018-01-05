#include <stdio.h>
#include <string.h>

#define MAX 100

struct thuthap {
	char ten[MAX];
	int ngay;
	int thang;
	int nam;
};

int songay(int thang, int nam);

int stt(thuthap A);

int ktra(char s[], char t[]);

void nhap(FILE *f, thuthap A[], int &len);

int dem(int chi_so, thuthap A[], int len);

void lietke(thuthap A[], int len);

void lk_thang(thuthap A[], int len);

void lk_daunam(thuthap A[], int len);
