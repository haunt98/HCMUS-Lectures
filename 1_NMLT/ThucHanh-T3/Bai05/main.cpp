// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 05
#include <stdio.h>
int main(void)
{
	char chu_cai, thay_doi;
	// doi chu thuong thanh chu hoa doi chu hoa thanh chu thuong
	printf("Nhap mot chu cai: ");
	scanf("%c", &chu_cai);
	if (chu_cai >= 'a' && chu_cai <= 'z') {
		thay_doi = chu_cai + 'A' - 'a';
		printf("%c\n", thay_doi);
	}
	if (chu_cai >= 'A' && chu_cai <= 'Z') {
		thay_doi = chu_cai - 'A' + 'a';
		printf("%c\n", thay_doi);
	}
	return 0;
}