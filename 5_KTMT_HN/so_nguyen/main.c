#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void luong_dau(int n, int bit);
void bu_1(int n, int bit);
void bu_2(int n, int bit);
void bias(int n, int bit);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Use: a n bit\n");
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

/* luong va dau
 * bit dau tien ben trai the hien am-duong
 * cac bit tiep theo bieu dien gia tri
 * 00..0 va 10..0 the hien so 0
 */
void luong_dau(int n, int bit)
{
	int temp = n;
	char *s = malloc(bit + 1);

	if (n >= 0) {
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

/* so bu 1
 * bit dau tien van la dau
 * so am la 1 tru di so duong
 * tuong tu luong_dau 00..0 va 11..1 deu bieu dien 0
 */
void bu_1(int n, int bit)
{
	int temp = n;
	char *s = malloc(bit + 1);

	if (n < 0)
		temp = -temp;
	s[0] = '0';
	s[bit] = '\0';

	for (int i = bit - 1; i > 0; --i) {
		s[i] = '0' + temp % 2;
		temp /= 2;
	}
	if (n < 0) {
		for (int i = 0; i < bit; ++i) {
			s[i] = '0' + 1 - (s[i] - '0');
		}
	}
	printf("%d is %s\n", n, s);
	free(s);
}

// bu 2 la bu 1 cong them 1
void bu_2(int n, int bit)
{
	int temp = n;
	char *s = malloc(bit + 1);

	if (n < 0)
		temp = -temp;
	s[0] = '0';
	s[bit] = '\0';

	for (int i = bit - 1; i > 0; --i) {
		s[i] = '0' + temp % 2;
		temp /= 2;
	}
	if (n < 0) {
		// lay bu 1
		for (int i = 0; i < bit; ++i) {
			s[i] = '0' + 1 - (s[i] - '0');
		}
		// cong 1
		int du = 0;
		if (s[bit - 1] == '1') {
			s[bit - 1] = '0';
			du = 1;
		} else {
			s[bit - 1] = '1';
		}
		for (int i = bit - 2; i > 0; --i) {
			if (s[i] == '0' && du == 1) {
				s[i] = '1';
				du = 0;
			} else if (s[i] == '1' && du == 1) {
				s[i] = '0';
			}
		}
		// bit tan cung ben trai luon giu -1 voi so am
		s[0] = '1';
	}
	printf("%d is %s\n", n, s);
	free(s);
}

void bias(int n, int bit)
{
	if (n == 0) {
		char *zero = malloc(bit + 1);
		zero[0] = '0';
		for (int i = 1; i < bit; ++i) {
			zero[i] = '1';
		}
		zero[bit] = '\0';
		printf("%d is %s\n", n, zero);
		free(zero);
	} else if (n > 0) {
		int temp = n - 1;
		char *s = malloc(bit + 1);
		s[bit] = '\0';
		s[0] = '1'; // positive bias alwats 1..

		for (int i = bit - 1; i > 0; --i) {
			s[i] = '0' + temp % 2;
			temp /= 2;
		}
		printf("%d is %s\n", n, s);
		free(s);
	} else {
		// tim luong dau cua -n, sau do zero tru di
		int temp = -n;
		char *s = malloc(bit + 1);
		s[bit] = '\0';
		s[0] = '0';
		for (int i = bit - 1; i > 0; --i) {
			s[i] = '0' + temp % 2;
			temp /= 2;
		}
		for (int i = bit - 1; i > 0; --i) {
			if (s[i] == '1')
				s[i] = '0';
			else
				s[i] = '1';
		}
		printf("%d is %s\n", n, s);
		free(s);
	}
}
