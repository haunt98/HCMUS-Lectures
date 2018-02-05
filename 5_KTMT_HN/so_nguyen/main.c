#include "bieu_dien.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void test_tran();

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Use: a n bit\n");
		test_tran();
		return 0;
	}
	int n = atoi(argv[1]);
	int bit = atoi(argv[2]);
	luong_dau(n, bit);
	bu_1(n, bit);
	bu_2(n, bit);
	bias(n, bit);
	return 0;
}

void test_tran()
{
	int a = 2147483648; // INT_MAX + 1
	printf("%d\n", a);
        // chung to khi tran, a quay laitu INT_MIN
        printf("a == INT_MIN ? %d\n",a==INT_MIN);
}
