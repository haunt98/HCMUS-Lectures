#include <stdio.h>
#include <string.h>

// remove duplicate in a string
void removeDuplicate(char *str);

int main()
{
	char s[] = "abacbc";
	removeDuplicate(s);
	printf("%s\n", s);
	return 0;
}

void removeDuplicate(char *str)
{
	if (!str)
		return;
	int n = strlen(str);
	if (n < 2)
		return;

	int tail = 1;
	for (int i = 1; i < n; ++i) {
		int j;
		for (j = 0; j < tail; ++j) {
			if (str[i] == str[j])
				break;
		}
		// no duplicate
		if (j == tail) {
			str[tail] = str[i];
			++tail;
		}
	}
	str[tail] = '\0';
}
