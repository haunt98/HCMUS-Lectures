// MSSV: Nguyen Tran Hau
// Ho ten: Nguyen Tran Hau
// Bai 07: Giai phuong trinh ax^2+bx+c=0
#include <math.h>
#include <stdio.h>
int main(void)
{
	printf("Giai pt ax^2+bx+c=0\n");
	float a, b, c, delta, x1, x2;
	printf("Nhap a: ");
	scanf("%f", &a);
	printf("Nhap b: ");
	scanf("%f", &b);
	printf("Nhap c: ");
	scanf("%f", &c);
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				printf("PT vo so nghiem\n");
			else
				printf("PT vo nghiem\n");
		} else {
			x1 = -c / b;
			printf("Nghiem x = %f\n", x1);
		}
	} else {
		delta = b * b - 4 * a * c;
		if (delta == 0) {
			x1 = -b / (2 * a);
			printf("PT co nghiem duy nhat x = %f\n", x1);
		} else if (delta > 0) {
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			printf("PT co hai nghiem\n");
			printf("Nghiem x1 = %f\n", x1);
			printf("Nghiem x2 = %f\n", x2);
		} else
			printf("PT vo nghiem\n");
	}
	return 0;
}