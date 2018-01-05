#include <math.h>
#include <stdio.h>
// Giai pt bac 2 ax^2+bx+c
int main()
{
	float a, b, c, delta, x1, x2;
	printf("Giai phuong trinh bac 2 ax^2+bx+c\n");
	printf("Nhap a, b, c\n");
	scanf("%f %f %f", &a, &b, &c);
	if (a == 0) {
		printf("Day khong phai la phuong trinh bac 2\n");
	} else {
		delta = b * b - 4 * a * c;
		if (delta < 0) {
			printf("Phuong trinh vo nghiem\n");
		} else if (delta == 0) {
			x1 = -b / (2.0 * a);
			printf("Phuong trinh co nghiem kep x = %f\n", x1);
		} else {
			x1 = (-b + sqrt(delta)) / (2.0 * a);
			x2 = (-b - sqrt(delta)) / (2.0 * a);
			printf("Phuong trinh co 2 nghiem phan biet\n");
			printf("Ngiem thu nhat x1 = %f\n", x1);
			printf("Ngiem thu hai x2 = %f\n", x2);
		}
	}
	return 0;
}