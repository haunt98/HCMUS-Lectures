#include "xuly.h"

int so_sanh(char s[], char t[])
{
	if (strlen(s) != strlen(t))
		return 0;
	for (int i = 0; i < strlen(s); ++i)
		if (s[i] != t[i])
			return 0;
	return 1;
}

void nhap_sv(tt_sinh_vien &sv)
{
	char tam[MAX];
	int i, l_email;
	printf("MSSV: ");
	scanf("%d", &sv.MSSV);
	printf("Ho: ");
	gets(tam);
	gets(sv.ho);
	printf("Ten lot: ");
	gets(sv.ten_lot);
	printf("Ten: ");
	gets(sv.ten);
	printf("Nhap CMND: ");
	scanf("%d", &sv.CMND);
	printf("Nhap ngay thang nam sinh(lan luot): ");
	scanf("%d %d %d", &sv.ngay_sinh.ngay, &sv.ngay_sinh.thang,
	      &sv.ngay_sinh.nam);
	printf("Gioi tinh (0 la nam, 1 la nu): ");
	scanf("%d", &sv.gioi_tinh);
	printf("Dia chi thuong tru: ");
	gets(tam);
	gets(sv.dia_chi);
	printf("Diem trung binh: ");
	scanf("%f", &sv.dtb);
	{
		l_email = 0;
		sv.email[l_email++] = tolower(sv.ho[0]);
		sv.email[l_email++] = tolower(sv.ten_lot[0]);
		for (i = 0; i < strlen(sv.ten); ++i)
			sv.email[l_email++] = tolower(sv.ten[i]);
		sv.email[l_email] = '\0';
		strcat(sv.email, "@student.hcmus.edu.vn");
	}
	sv.nam_tuoi = sv.ngay_sinh.nam % 12;
}

void xuat_sv(tt_sinh_vien sv)
{
	printf("MSSV: %d\n", sv.MSSV);
	printf("Ho va ten: %s %s %s\n", sv.ho, sv.ten_lot, sv.ten);
	printf("Ngay sinh: %2d/%2d/%4d\n", sv.ngay_sinh.ngay,
	       sv.ngay_sinh.thang, sv.ngay_sinh.nam);
	printf("CMND: %d\n", sv.CMND);
	{
		printf("Gioi tinh: ");
		if (sv.gioi_tinh == nam)
			printf("Nam\n");
		else if (sv.gioi_tinh == nu)
			printf("Nu\n");
		else
			printf("Khong xac dinh\n");
	}
	printf("Dia chi thuong tru: %s\n", sv.dia_chi);
	printf("Diem trung binh: %0.2f\n", sv.dtb);
	{
		printf("Nam tuoi: ");
		switch (sv.nam_tuoi) {
		case (than):
			printf("Nam Than\n");
			break;
		case (dau):
			printf("Nam Dau\n");
			break;
		case (tuat):
			printf("Nam Tuat\n");
			break;
		case (hoi):
			printf("Nam Hoi\n");
			break;
		case (ti):
			printf("Nam Ti\n");
			break;
		case (suu):
			printf("Nam Suu\n");
			break;
		case (dan):
			printf("Nam Dan\n");
			break;
		case (meo):
			printf("Nam Meo\n");
			break;
		case (thin):
			printf("Nam Thin\n");
			break;
		case (ty):
			printf("Nam Ty\n");
			break;
		case (ngo):
			printf("Nam Ngo\n");
			break;
		case (mui):
			printf("Nam Mui\n");
			break;
		default:
			break;
		}
	}
	printf("Email SV: %s\n", sv.email);
}

void sv_cao(tt_sinh_vien sv[], int sl) // Bai 3
{
	int vt_max, i;
	vt_max = 0;
	for (i = 1; i < sl; ++i)
		if (sv[i].dtb > sv[vt_max].dtb)
			vt_max = i;
	printf("Sinh vien co diem trung binh cao nhat: %s %s %s\n",
	       sv[vt_max].ho, sv[vt_max].ten_lot, sv[vt_max].ten);
}

void lke_tb(tt_sinh_vien sv[], int sl)
{
	printf("Nhung sinh vien duoi diem trung binh:\n");
	for (int i = 0; i < sl; ++i)
		if (sv[i].dtb < 5.0)
			printf("%s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
}

void lke_xl(tt_sinh_vien sv[], int sl)
{
	printf("Nhung sinh vien hoc luc Kem:\n");
	for (int i = 0; i < sl; ++i)
		if (sv[i].dtb < 4.0)
			printf("%s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
	printf("Nhung sinh vien hoc luc Yeu:\n");
	for (int i = 0; i < sl; ++i)
		if (sv[i].dtb >= 4.0 && sv[i].dtb < 5.0)
			printf("%s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
	printf("Nhung sinh vien hoc luc Trung binh:\n");
	for (int i = 0; i < sl; ++i)
		if (sv[i].dtb >= 5.0 && sv[i].dtb < 6.0)
			printf("%s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
	printf("Nhung sinh vien hoc luc Trung binh kha:\n");
	for (int i = 0; i < sl; ++i)
		if (sv[i].dtb >= 6.0 && sv[i].dtb < 7.0)
			printf("%s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
	printf("Nhung sinh vien hoc luc Kha:\n");
	for (int i = 0; i < sl; ++i)
		if (sv[i].dtb >= 7.0 && sv[i].dtb < 8.0)
			printf("%s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
	printf("Nhung sinh vien hoc luc Gioi:\n");
	for (int i = 0; i < sl; ++i)
		if (sv[i].dtb >= 8.0 && sv[i].dtb < 9.0)
			printf("%s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
	printf("Nhung sinh vien hoc luc Xuat sac:\n");
	for (int i = 0; i < sl; ++i)
		if (sv[i].dtb >= 8.0 && sv[i].dtb <= 10.0)
			printf("%s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
}

void nhap_ds_sv(tt_sinh_vien sv[], int &sl)
{
	printf("Nhap vao so luong sinh vien: ");
	scanf("%d", &sl);
	for (int i = 0; i < sl; ++i) {
		printf("Nhap thong tin SV %d\n", i);
		nhap_sv(sv[i]);
	}
}

void xuat_ds_sv(tt_sinh_vien sv[], int sl)
{
	for (int i = 0; i < sl; ++i) {
		printf("Thong tin SV %d\n", i);
		xuat_sv(sv[i]);
	}
}

void xoa_e_trung(tt_sinh_vien sv[], int sl) // Xoa email trung
{
	int i, j, tam, len;
	for (i = 0; i < sl; ++i) {
		tam = 1;
		for (j = i + 1; j < sl; ++j)
			if (so_sanh(sv[j].email, sv[i].email)) {
				len = strlen(sv[j].email);
				sv[j].email[len - 21] = '0' + tam;
				sv[j].email[len - 20] = '\0';
				strcat(sv[j].email, "@student.hcmus.edu.vn");
				tam++;
			}
	}
}

void f_nhap_sv(FILE *f, tt_sinh_vien &sv)
{
	int i, l_email;

	fscanf(f, "%d", &sv.MSSV);

	fscanf(f, "%s", sv.ho);
	fscanf(f, "%s", sv.ten_lot);
	fscanf(f, "%s", sv.ten);
	fscanf(f, "%d", &sv.CMND);
	fscanf(f, "%d %d %d", &sv.ngay_sinh.ngay, &sv.ngay_sinh.thang,
	       &sv.ngay_sinh.nam);
	fscanf(f, "%d", &sv.gioi_tinh);
	fgets(sv.dia_chi, MAX - 1, f);
	fgets(sv.dia_chi, MAX - 1, f);
	fscanf(f, "%f", &sv.dtb);
	{
		l_email = 0;
		sv.email[l_email++] = tolower(sv.ho[0]);
		sv.email[l_email++] = tolower(sv.ten_lot[0]);
		for (i = 0; i < strlen(sv.ten); ++i)
			sv.email[l_email++] = tolower(sv.ten[i]);
		sv.email[l_email] = '\0';
		strcat(sv.email, "@student.hcmus.edu.vn");
	}
	sv.nam_tuoi = sv.ngay_sinh.nam % 12;
}

void f_xuat_sv(FILE *f, tt_sinh_vien sv)
{
	fprintf(f, "MSSV: %d\n", sv.MSSV);
	fprintf(f, "Ho va ten: %s %s %s\n", sv.ho, sv.ten_lot, sv.ten);
	fprintf(f, "Ngay sinh: %2d/%2d/%4d\n", sv.ngay_sinh.ngay,
		sv.ngay_sinh.thang, sv.ngay_sinh.nam);
	fprintf(f, "CMND: %d\n", sv.CMND);
	{
		fprintf(f, "Gioi tinh: ");
		if (sv.gioi_tinh == nam)
			fprintf(f, "Nam\n");
		else if (sv.gioi_tinh == nu)
			fprintf(f, "Nu\n");
		else
			fprintf(f, "Khong xac dinh\n");
	}
	fprintf(f, "Dia chi thuong tru: %s", sv.dia_chi);
	fprintf(f, "Diem trung binh: %0.2f\n", sv.dtb);
	{
		fprintf(f, "Nam tuoi: ");
		switch (sv.nam_tuoi) {
		case (than):
			fprintf(f, "Nam Than\n");
			break;
		case (dau):
			fprintf(f, "Nam Dau\n");
			break;
		case (tuat):
			fprintf(f, "Nam Tuat\n");
			break;
		case (hoi):
			fprintf(f, "Nam Hoi\n");
			break;
		case (ti):
			fprintf(f, "Nam Ti\n");
			break;
		case (suu):
			fprintf(f, "Nam Suu\n");
			break;
		case (dan):
			fprintf(f, "Nam Dan\n");
			break;
		case (meo):
			fprintf(f, "Nam Meo\n");
			break;
		case (thin):
			fprintf(f, "Nam Thin\n");
			break;
		case (ty):
			fprintf(f, "Nam Ty\n");
			break;
		case (ngo):
			fprintf(f, "Nam Ngo\n");
			break;
		case (mui):
			fprintf(f, "Nam Mui\n");
			break;
		default:
			break;
		}
	}
	fprintf(f, "Email SV: %s\n", sv.email);
}

void f_nhap_sv_ds(FILE *f, tt_sinh_vien sv[], int &sl)
{
	fscanf(f, "%d", &sl);
	for (int i = 0; i < sl; ++i)
		f_nhap_sv(f, sv[i]);
	xoa_e_trung(sv, sl);
}

void f_xuat_sv_ds(FILE *f, tt_sinh_vien sv[], int sl)
{
	for (int i = 0; i < sl; ++i)
		f_xuat_sv(f, sv[i]);
}

void tim_ms(tt_sinh_vien sv[], int sl)
{
	int x;
	printf("Nhap MSSV cua sinh vien: ");
	scanf("%d", &x);
	for (int i = 0; i < sl; ++i)
		if (sv[i].MSSV == x)
			printf("SV %s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
}

void lke_nu(tt_sinh_vien sv[], int sl)
{
	for (int i = 0; i < sl; ++i)
		if (sv[i].gioi_tinh == nu)
			printf("SV %s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
}

void lke_nam(tt_sinh_vien sv[], int sl)
{
	for (int i = 0; i < sl; ++i)
		if (sv[i].gioi_tinh == nam)
			printf("SV %s %s %s\n", sv[i].ho, sv[i].ten_lot,
			       sv[i].ten);
}

void them_sv(tt_sinh_vien sv[], int &sl)
{
	nhap_sv(sv[sl]);
	sl++;
}

void tim_sua(tt_sinh_vien sv[], int sl)
{
	int mssv;
	printf("Nhap MSSV can tim: ");
	scanf("%d", &mssv);
	for (int i = 0; i < sl; ++i)
		if (sv[i].MSSV == mssv)
			nhap_sv(sv[i]);
}

void sv_lon(tt_sinh_vien sv[], int sl)
{
	int max = 0;
	for (int i = 0; i < sl; ++i)
		if (sv[i].ngay_sinh.nam < sv[max].ngay_sinh.nam)
			max = i;
	printf("Sinh vien lon tuoi nhat la: %s %s %s\n", sv[max].ho,
	       sv[max].ten_lot, sv[max].ten);
}