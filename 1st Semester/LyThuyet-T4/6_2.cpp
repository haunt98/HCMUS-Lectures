#include <stdio.h>
#include "6_2.h"
#include "nhap_pso.h"
#include "cong_pso.h"
#include "nhan_pso.h"
void baitap_6_2()
{
	int a, b, c, d ;
	char phep_tinh;
	printf("Nhap phan so thu I: \n");
	nhap_pso(a, b);
	printf("\nNhap phan so thu II: \n");
	nhap_pso(c, d);
	printf("\nNhap phep tinh(+ - * /): ");
	scanf_s(" %c", &phep_tinh);
	if (phep_tinh == '+')
		cong_pso(a, b, c, d);
	else if (phep_tinh == '-')
		cong_pso(a, b, -c, d); //phep tru la phep cong voi so doi
	else if (phep_tinh == '*')
		nhan_pso(a, b, c, d);
	else
	{
		if (c == 0)
			printf("\nKhong thuc hien duoc.\n");
		else
			nhan_pso(a, b, d, c); //phep chia la phep nhan voi so nghich dao
	}
}