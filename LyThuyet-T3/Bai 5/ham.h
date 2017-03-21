#include <stdio.h>

typedef void(*so_sanh)(int *, int *); // tang dan, giam dan

void tang_dan(int *a, int *b);

void giam_dan(int *a, int *b);

void sap_xep(int *A, int so_luong, so_sanh T);