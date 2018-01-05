// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 02
#include <stdio.h>
int main(void)
{
	float diem_tb;
	printf("Nhap diem trung binh cua SV: ");
	scanf("%f", &diem_tb);
	if (diem_tb >= 9 && diem_tb <= 10)
		printf("Hoc luc: Xuat sac\n");
	else if (diem_tb >= 8 && diem_tb < 9)
		printf("Hoc luc: Gioi\n");
	else if (diem_tb >= 7 && diem_tb < 8)
		printf("Hoc luc: Kha\n");
	else if (diem_tb >= 6 && diem_tb < 7)
		printf("Hoc luc: Trung binh kha\n");
	else if (diem_tb >= 5 && diem_tb < 6)
		printf("Hoc luc: Trung binh\n");
	else if (diem_tb >= 4 && diem_tb < 5)
		printf("Hoc luc: Yeu\n");
	else
		printf("Hoc luc: Kem\n");
	return 0;
}