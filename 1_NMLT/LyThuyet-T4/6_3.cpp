#include "6_3.h"
#include "ktra_tg.h"
#include "ktra_tg_can.h"
#include "ktra_tg_deu.h"
#include "ktra_tg_vuong.h"
#include "nhap_3_canh.h"
#include <stdio.h>
void baitap_6_3()
{
	float a, b, c;
	nhap_3_canh(a, b, c);
	if (ktra_tg(a, b, c) == 0)
		printf("Khong phai so do 3 canh tam giac.\n");
	else {
		if (ktra_tg_can(a, b, c) == 1) {
			if (ktra_tg_deu(a, b, c) == 1)
				printf("Day la tam giac deu.\n");
			else if (ktra_tg_vuong(a, b, c) == 1)
				printf("Day la tam giac vuong can.\n");
			else
				printf("Day la tam giac can.\n");
		} else if (ktra_tg_vuong(a, b, c) == 1)
			printf("Day la tam giac vuong.\n");
		else
			printf("Day la tam giac thuong.\n");
	}
}