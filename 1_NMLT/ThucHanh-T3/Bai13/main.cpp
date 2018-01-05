// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 13: Tinh tien gia ve Galaxy Cinema
#include <stdio.h>
int main(void)
{
	int gio, phut, thu_trong_tuan, gia_ve;
	printf("Nhap vao thoi diem di xe phim\n(chu y dong ho 24h)\nlan luot "
	       "gio va phut: ");
	scanf("%d %d", &gio, &phut);
	printf("Nhap vao thu trong tuan\n(neu chu nhat nhap vao so 1): ");
	scanf("%d", &thu_trong_tuan);
	if (thu_trong_tuan == 3)
		gia_ve = 50000;
	else if (thu_trong_tuan == 6 || thu_trong_tuan == 7 ||
		 thu_trong_tuan == 1) {
		if (gio * 60 + phut < 17 * 60)
			gia_ve = 75000;
		else
			gia_ve = 80000;
	} else {
		if (gio * 60 + phut < 17 * 60)
			gia_ve = 60000;
		else
			gia_ve = 70000;
	}
	printf("Gia ve: %d dong\n", gia_ve);
	return 0;
}