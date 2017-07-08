#include <stdio.h>
#include "6_1.h"
#include "6_2.h"
#include "6_3.h"
#include "6_4.h"
int main(void)
{
	int lua_chon;
	for (int i = 1; i < 5; ++i)
		printf("%d. Bai tap 6.%d.\n",i,i);
	printf("5. Thoat.\n");
	printf("Lua chon cua ban (1-5): ");
	scanf("%d", &lua_chon);
	if (lua_chon == 1)
		baitap_6_1();
	else if (lua_chon == 2)
		baitap_6_2();
	else if (lua_chon == 3)
		baitap_6_3();
	else if (lua_chon == 4)
		baitap_6_4();
	else
		printf("Tam biet.\n");
	return 0;
}