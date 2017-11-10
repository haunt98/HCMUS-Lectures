#include <stdio.h>
#include "ktra_tg.h"
int ktra_tg(float a, float b, float c)
//tra ve 1 neu a b c la 3 canh tam giac
//tra ve 0 neu khong phai
{
	if (a + b > c && b + c > a && c + a > b)
		return 1;
	return 0;
}