// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai tap Tuan 9

#include "xuly.h"

int main(void)
{
	tt_sinh_vien A[MAX];
	int n, sl;

	FILE *f_in = fopen("input.txt", "r");
	FILE *f_out = fopen("output.txt", "w");

	if (f_in == NULL)
		printf("Khong mo file duoc.\n");
	else {
		f_nhap_sv_ds(f_in, A, sl);
		// f_xuat_sv_ds(f_out, A, sl);
		fclose(f_in);
		// fclose(f_out);
	}

	printf("nhap vao bt(3,4,5,7,9,11,12,13,29): ");
	scanf("%d", &n);

	switch (n) {
	case (3):
		sv_cao(A, sl);
		break;
	case (4):
		lke_tb(A, sl);
		break;
	case (5):
		lke_xl(A, sl);
		break;
	case (7):
		tim_ms(A, sl);
		break;
	case (9):
		them_sv(A, sl);
		break;
	case (11):
		lke_nu(A, sl);
		break;
	case (12):
		lke_nam(A, sl);
		break;
	case (13):
		tim_sua(A, sl);
		break;
	case (18):
		sv_lon(A, sl);
		break;
	case (29):
		f_xuat_sv_ds(f_out, A, sl);
		fclose(f_out);
		break;
	default:
		break;
	}

	return 0;
}