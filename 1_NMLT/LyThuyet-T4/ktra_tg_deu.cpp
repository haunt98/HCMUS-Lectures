#include "ktra_tg_deu.h"
#include <stdio.h>
int ktra_tg_deu(float a, float b, float c)
// tra ve 1 neu a b c 3 canh cua tam giac deu
// tra ve 0 neu khong phai
{
	if (a == b && b == c)
		return 1;
	return 0;
}