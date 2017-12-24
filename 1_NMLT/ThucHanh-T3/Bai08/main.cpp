//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 08
#include <stdio.h>
//tinh tien di taxi
int main(void)
{
	int do_dai;
	int tien;
	printf("Nhap quang duong di duoc: ");
	scanf("%d", &do_dai);
	if (do_dai <= 1)
		tien =do_dai* 15000;
	else if (do_dai >= 2 && do_dai <= 5)
		tien = 15000 + (do_dai - 1) * 13500;
	else if (do_dai > 5 && do_dai <= 12)
		tien = 15000 + 4 * 13500 + (do_dai - 5) * 11000;
	else
	{
		tien = 15000 + 4 * 13500 + (do_dai - 5) * 11000;
		tien = tien - tien / 10;
	}
	printf("Tien di taxi: %d dong\n", tien);
	return 0;
}