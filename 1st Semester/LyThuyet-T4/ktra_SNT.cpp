#include <stdio.h>
#include <math.h>
#include "ktra_SNT.h"
int ktra_SNT(int n)
//xuat ra 1 neu la so nguyen to
//xuat ra 0 neu khong phai so nguyen to
{
	if (n == 1)
		return 0;
	for (int i = 2; i <= sqrt((double)n); ++i)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;

}