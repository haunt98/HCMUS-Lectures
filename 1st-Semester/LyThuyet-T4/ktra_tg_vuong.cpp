#include <stdio.h>
#include "ktra_tg_vuong.h"
int ktra_tg_vuong(float a, float b, float c)
//tra ve 1 neu a b c la 3 canh tam giac vuong
//tra ve 0 neu khong phai
{
	if (a*a + b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b)
		return 1;
	return 0;
}