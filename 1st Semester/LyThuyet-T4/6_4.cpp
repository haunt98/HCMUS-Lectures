#include <stdio.h>
#include "nhap_chi_so.h"
#include "kwh_tieu_thu.h"
#define CHI_SO_MAX 999999999
void baitap_6_4()
{
	int chi_so_cu, chi_so_moi;
	nhap_chi_so(chi_so_cu, chi_so_moi);
	int chi_so = chi_so_moi - chi_so_cu;
	int tien_dien =
		1242 * kwh_tieu_thu(chi_so, 0, 100)
		+ 1304 * kwh_tieu_thu(chi_so, 100, 150)
		+ 1651 * kwh_tieu_thu(chi_so, 150, 200)
		+ 1788 * kwh_tieu_thu(chi_so, 200, 300)
		+ 1912 * kwh_tieu_thu(chi_so, 300, 400)
		+ 1962 * kwh_tieu_thu(chi_so, 400, CHI_SO_MAX);
	printf("Tien dien phai tra: %d dong\n", tien_dien);
}