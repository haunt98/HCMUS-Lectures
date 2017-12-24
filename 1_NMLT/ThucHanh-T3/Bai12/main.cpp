//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Bai 12
#include <stdio.h>
int main(void)
{
	int so_gio, thoi_diem, thu_trong_tuan, vip, tien;
	printf("Nhap vao so gio: ");
	scanf("%d", &so_gio);
	printf("Nhap vao thoi diem(dong ho 24h): ");
	scanf("%d", &thoi_diem);
	printf("Nhap vao thu trong tuan(neu la chu nhat nhap vao so 1): ");
	scanf("%d", &thu_trong_tuan);
	printf("Neu la phong VIP nhap so 1, khong phai nhap so 0: ");
	scanf("%d", &vip);
	if (vip == 0)
	{
		if (thu_trong_tuan == 7 || thu_trong_tuan == 1)
			tien = so_gio * 200000;
		else
		{
			if (thoi_diem + so_gio <= 18)
				tien = so_gio * 80000;
			else if (thoi_diem > 18)
				tien = so_gio * 200000;
			else
				tien = (18 - thoi_diem) * 80000 + (thoi_diem + so_gio - 18) * 200000;
		}
	}
	else
	{
		if (thu_trong_tuan == 7 || thu_trong_tuan == 1)
			tien = so_gio * 400000;
		else
		{
			if (thoi_diem + so_gio <= 18)
				tien = so_gio * 100000;
			else if (thoi_diem > 18)
				tien = so_gio * 300000;
			else
				tien = (18 - thoi_diem) * 100000 + (thoi_diem + so_gio - 18) * 300000;
		}
	}
	printf("Tien thue phong: %d dong\n", tien);
	return 0;
}