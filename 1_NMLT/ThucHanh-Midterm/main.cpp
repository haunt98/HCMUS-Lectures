// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai tap giua ki

#include "xuly.h"

int main(void)
{
	float nhietdo_khong_nhuan[365];
	float nhietdo_nhuan[366];
	int ngay, thang, nam, so_thutu, flag_nam_nhuan;
	int so_tt_max;

	nhap_ngay_thang_nam(ngay, thang, nam, flag_nam_nhuan);
	so_thutu = so_thu_tu_ngay(ngay, thang, nam, flag_nam_nhuan);
	if (flag_nam_nhuan == 1) {
		nhap_nhiet_do(so_thutu, nhietdo_nhuan, 366);
		so_tt_max = cs_max_mang(nhietdo_nhuan, 366);
		doi_ra_ngay(so_tt_max + 1, nam, flag_nam_nhuan);
	} else {
		nhap_nhiet_do(so_thutu, nhietdo_khong_nhuan, 365);
		so_tt_max = cs_max_mang(nhietdo_khong_nhuan, 365);
		doi_ra_ngay(so_tt_max + 1, nam, flag_nam_nhuan);
	}
	return 0;
}