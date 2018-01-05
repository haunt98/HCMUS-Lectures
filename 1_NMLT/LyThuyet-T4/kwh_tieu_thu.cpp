#include "kwh_tieu_thu.h"
#include <stdio.h>
int kwh_tieu_thu(int chi_so, int chan_duoi, int chan_tren)
{
	if (chi_so < chan_duoi)
		return 0;
	if (chi_so > chan_tren)
		return chan_tren - chan_duoi;
	return chi_so - chan_duoi;
}