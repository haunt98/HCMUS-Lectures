// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 04
#include <stdio.h>
int main(void)
{
	int n;
	printf("Nhap vao mot so nguyen bat ki: ");
	scanf("%d", &n);
	if (n < 0 || n > 9)
		printf("khong doc duoc.\n");
	else {
		if (n == 0)
			printf("khong\n");
		else if (n == 1)
			printf("mot\n");
		else if (n == 2)
			printf("hai\n");
		else if (n == 3)
			printf("ba\n");
		else if (n == 4)
			printf("bon\n");
		else if (n == 5)
			printf("nam\n");
		else if (n == 6)
			printf("sau\n");
		else if (n == 7)
			printf("bay\n");
		else if (n == 8)
			printf("tam\n");
		else
			printf("chin\n");
	}
	return 0;
}