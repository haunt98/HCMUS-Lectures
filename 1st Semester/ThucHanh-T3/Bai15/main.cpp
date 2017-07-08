//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 15
#include <stdio.h>
int main(void)
{
	int thang_truoc, thang_nay, chi_so, tien_nuoc;
	printf("Nhap vao chi so nuoc thang truoc(dv m3): ");
	scanf("%d", &thang_truoc);
	printf("Nhap vao chi so nuoc thang nay(dv m3): ");
	scanf("%d", &thang_nay);
	chi_so = thang_nay - thang_truoc;
	printf("%d\n", chi_so);
	if (chi_so >= 0 && chi_so <= 4)
		tien_nuoc = chi_so * 3300;
	else if (chi_so > 4 && chi_so <= 6)
		tien_nuoc = 4 * 3300 + (chi_so - 4) * 5200;
	else
		tien_nuoc = 4 * 3300 + 2 * 5200 + (chi_so - 6) * 7000;
	tien_nuoc = tien_nuoc + tien_nuoc / 10;
	printf("Tien nuoc phai tra: %d dong\n", tien_nuoc);
	return 0;
}