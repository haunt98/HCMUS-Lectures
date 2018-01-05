#include "nhap_pso.h"
#include <stdio.h>
void nhap_pso(int &x, int &y)
{
	printf("Nhap tu so: ");
	scanf("%d", &x);
	do {
		printf("Nhap mau so: ");
		scanf("%d", &y);
	} while (y == 0);
}