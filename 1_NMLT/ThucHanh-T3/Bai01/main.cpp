// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 01
#include <stdio.h>
#define dau 1
#define rot 0
int main(void)
{
	float d_thuc_hanh, d_bt, d_li_thuyet;
	int state = dau;
	int co_copy;
	printf("Nhap diem thuc hanh: ");
	scanf("%f", &d_thuc_hanh);
	printf("Nhap diem bai tap: ");
	scanf("%f", &d_bt);
	printf("Nhap diem thuc hanh: ");
	scanf("%f", &d_li_thuyet);
	float tong_diem = d_thuc_hanh * 0.3 + d_bt * 0.3 + d_li_thuyet * 0.4;
	printf("SV co copy hay khong? \n");
	printf("Co copy nhap so 1, Khong copy nhap so 0: ");
	scanf("%d", &co_copy);
	if (co_copy == 1 || d_thuc_hanh == 0 || d_bt == 0 || d_li_thuyet == 0 ||
	    tong_diem < 5)
		state = rot;
	if (state == dau)
		printf("Ket qua: SV dau.\n");
	else
		printf("Ket qua: SV rot.\n");
	return 0;
}