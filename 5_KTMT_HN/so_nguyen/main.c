#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void luong_dau(int n, int bit);

int main()
{
	int n;
	scanf("%d", &n);
	luong_dau(n, 10);
	return 0;
}

/* bit dau tien ben trai the hien am-duong
 * cac bit tiep theo bieu dien gia tri
 * 00..0 va 10..0 the hien so 0
 */
void luong_dau(int n, int bit)
{
	int temp = n;
	char *s = malloc(bit + 1);

	if (n > 0) {
		s[0] = '0';
	} else {
		s[0] = '1';
		temp = -temp;
	}
	s[bit] = '\0';

	for (int i = bit - 1; i > 0; --i) {
		s[i] = '0' + temp % 2;
		temp /= 2;
	}
	printf("%d is %s\n", n, s);
	free(s);
}
