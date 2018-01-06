#include <stdio.h>
#include <string.h>

int isAnagram(const char *s, const char *t);

int main()
{
	printf("%d\n", isAnagram("bac", "baca"));
	return 0;
}

int isAnagram(const char *s, const char *t)
{
	if (strlen(s) != strlen(t) || !s || !t)
		return 0;
	int tableChar[256] = {0};
	for (int i = 0; s[i] != '\0'; ++i) {
		++tableChar[(int)s[i]];
		--tableChar[(int)t[i]];
	}
	for (int i = 0; i < 256; ++i) {
		if (tableChar[i])
			return 0;
	}
	return 1;
}
