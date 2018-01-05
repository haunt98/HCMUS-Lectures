#include "xuly.h"

void thiBay(ThuBay *dv1, ThuBay *dv2)
{
	dv1->bay();
	dv2->bay();
}

void thiBoi(ThuBoi *dv1, ThuBoi *dv2)
{
	dv1->boi();
	dv2->boi();
}

void thuanhoaThu(ThuDeCon *dv)
{
	ThuDeCon con = dv->deCon();
}

void nuoiCa(LopCa *dv)
{
	dv->boi();
	LopCa con = dv->deTrung();
}

void nuoiBoSat(LopBoSat *dv)
{
	dv->bo();
	dv->anTap();
	LopBoSat con = dv->deTrung();
}
