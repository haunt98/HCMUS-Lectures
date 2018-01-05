// MSSV: 1612180
// Ho ten: Nguyen Tran Hau
// Bai 11
#include <stdio.h>
int main(void)
{
	float a, b, c;
	printf("Nhap vao 3 canh tam giac: ");
	scanf("%f %f %f", &a, &b, &c);
	if (a + b <= c || b + c <= a || c + a <= b)
		printf("Day khong phai la so do 3 canh tam giac.\n");
	else {
		if (a == b || b == c || c == a) {
			if (a == b && b == c)
				printf("Day la tam giac deu.\n");
			else if (a * a + b * b == c * c ||
				 b * b + c * c == a * a ||
				 c * c + a * a == b * b)
				printf("Day la tam giac vuong can.\n");
			else
				printf("Day la tam giac can.\n");
		} else if (a * a + b * b == c * c || b * b + c * c == a * a ||
			   c * c + a * a == b * b)
			printf("Day la tam giac vuong.\n");
		else
			printf("Day la tam giac thuong.\n");
	}
	return 0;
}