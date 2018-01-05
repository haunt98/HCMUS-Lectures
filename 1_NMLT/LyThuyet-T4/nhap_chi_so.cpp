#include "nhap_chi_so.h"
#include <stdio.h>
void nhap_chi_so(int &chi_so_cu, int &chi_so_moi)
{
	do {
		printf("Nhap chi so dien cu: ");
		scanf("%d", &chi_so_cu);
	} while (chi_so_cu < 0);
	do {
		printf("Nhap chi so dien moi: ");
		scanf("%d", &chi_so_moi);
	} while (chi_so_moi < chi_so_cu);
}