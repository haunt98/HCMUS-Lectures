#include "xuly.h"

void reverseString(char *str, int left, int right)
{
	if (left >= right)
		return;
	char temp = str[left];
	str[left] = str[right];
	str[right] = temp;
	reverseString(str, left + 1, right - 1);
}

int findSubPos(char *main_str, char *sub_str, int pos)
{
	int main_len = strlen(main_str);
	int sub_len = strlen(sub_str);

	// end of main string
	if (*main_str == '\0' || main_len < sub_len)
		return -1;
	// substring match with main string
	if (strncmp(main_str, sub_str, sub_len) == 0)
		return pos;
	return findSubPos(main_str + 1, sub_str, pos + 1);
}

void upperWord(char *str, int pos)
{
	if (str[pos] == '\0')
		return;
	if (pos == 0 || str[pos - 1] == ' ')
	{
		if (str[pos] >= 'a' && str[pos] <= 'z')
			str[pos] += 'A' - 'a';
	}
	upperWord(str, pos + 1);
}

void swapChar(char &a, char &b)
{
	char temp = a; a = b; b = temp;
}

void printPermutation(char *str, int left, int right)
{
	if (left == right)
		cout << str << endl;
	else
	{
		for (int i = left; i <= right; ++i)
		{
			swapChar(str[i], str[left]);
			printPermutation(str, left + 1, right);
			swapChar(str[i], str[left]);
		}
	}
}