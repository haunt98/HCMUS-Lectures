#include "nhap_1_canh.h"
#include <stdio.h>
void nhap_1_canh(float &x)
{
	do {
		printf("Nhap vao mot canh cua tam giac: ");
		scanf("%f", &x);
	} while (x <= 0);
}