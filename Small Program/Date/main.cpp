#include <stdio.h>

const int months_days[2][12] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

struct Date{
	int dd, mm, yy;
};

bool is_leap_year(Date d)
{
	if (d.yy % 4 == 0 && d.yy % 100 != 0 || d.yy % 400 == 0)
		return true; // 1
	return false; // 0
}

int day_of_year(Date d)
{
	int result = d.dd;
	for (int i = 0; i < d.mm - 1; ++i)
		result += months_days[is_leap_year(d)][d.mm];
	return result;
}

int main(void)
{
	Date d = Date{ 2, 3, 2016 };
	printf("%d\n", day_of_year(d));
	return 0;
}