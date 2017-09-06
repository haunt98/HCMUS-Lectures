#include <stdio.h>
#include "ktra_tg_can.h"
int ktra_tg_can(float a, float b, float c)
//tra ve 1 neu la tam giac can
//tra ve 0 neu khong phai
{
	if (a == b || b == c || c == a)
		return 1;
	return 0;
}