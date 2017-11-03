//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 14
#include <stdio.h>
int main(void)
{
	int thang_truoc, thang_nay, chi_so;
	float tien_dien;
	printf("Nhap chi so dien thang truoc: ");
	scanf("%d", &thang_truoc);
	printf("Nhap chi so dien thang nay: ");
	scanf("%d", &thang_nay);
	chi_so = thang_nay - thang_truoc;
	if (chi_so >= 0 && chi_so <= 50)
		tien_dien = chi_so * 1484;
	else if (chi_so >= 51 && chi_so <= 100)
		tien_dien = 50 * 1484 + (chi_so - 50) * 1533;
	else if (chi_so >= 101 && chi_so <= 200)
		tien_dien = 50 * 1484 + 50 * 1533 + (chi_so - 100) * 1786;
	else if (chi_so >= 201 && chi_so <= 300)
		tien_dien = 50 * 1484 + 50 * 1533 + 100 * 1786 + (chi_so - 200) * 2242;
	else if (chi_so >= 301 && chi_so <= 400)
		tien_dien = 50 * 1484 + 50 * 1533 + 100 * 1786 + 100 * 2242 + (chi_so - 300) * 2503;
	else
		tien_dien = 50 * 1484 + 50 * 1533 + 100 * 1786 + 100 * 2242 + 100 * 2503 + (chi_so - 400) * 2587;
	tien_dien *= 1.1;
	printf("Tien dien phai tra: %.1f dong.\n", tien_dien);
	return 0;
}