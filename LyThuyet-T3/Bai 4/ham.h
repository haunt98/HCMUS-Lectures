#include <stdio.h>

typedef int ** intc2;
typedef int * intc1;

void nhapMatran(intc2 &A, int &M, int &N);

void xuatMatran(intc2 A, int M, int N);

bool laNguyento(int n);

void trichDanhsachNguyento(intc2 A, int M, int N, intc1 &B, int &L);

void xuatMang(intc1 B, int L);