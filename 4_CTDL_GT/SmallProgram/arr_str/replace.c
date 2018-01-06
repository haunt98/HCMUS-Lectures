#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceSpace(char **str, const char *to);

int main()
{
	char STR[] = "this is none";
	char *s = malloc(strlen(STR) + 1);
	strcpy(s, STR);

	replaceSpace(&s, "%20");
	printf("%s\n", s);

	free(s);
	return 0;
}

void replaceSpace(char **str, const char *to)
{
	if (!*str)
		return;
	int oldLen = strlen(*str);
	int countSpace = 0;
	for (int i = 0; i < oldLen; ++i) {
		if ((*str)[i] == ' ')
			++countSpace;
	}

	int newLen = oldLen + countSpace * (strlen(to) - 1);
	*str = (char *)realloc(*str, newLen + 1);
	(*str)[newLen] = '\0';
	int toLen = strlen(to);

	for (int i = oldLen - 1; i >= 0; --i) {
		if ((*str)[i] == ' ') {
			for (int j = toLen - 1; j >= 0; --j) {
				(*str)[--newLen] = to[j];
			}
		} else {
			(*str)[--newLen] = (*str)[i];
		}
	}
}
