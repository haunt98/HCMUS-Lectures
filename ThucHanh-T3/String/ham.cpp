#include "ham.h"

// homework
char *StringNCopy(char *dest, char *src, int num_char_copy)
{
	if (num_char_copy > strlen(src) || num_char_copy < 0)
		return NULL;
	int i;
	for (i = 0; i < num_char_copy; ++i)
		*(dest + i) = *(src + i);
	dest[i] = '\0';
	return dest;
}
char *StringCopy(char *dest, char *src)
{
	/*
	int i;
	for (i = 0; i < strlen(src); ++i)
	dest[i] = src[i];
	dest[i] = '\0';
	*/
	StringNCopy(dest, src, strlen(src));
	return dest;
}
void DeleteSubString(char *src, int startPos, int num_char_del)
{
	int len_src = strlen(src);
	if (startPos + num_char_del - 1 >= len_src)
	{
		src[startPos] = '\0';
		return;
	}
	char *temp = new char[len_src - num_char_del - startPos + 1];
	StringCopy(temp, src + startPos + num_char_del);
	StringCopy(src + startPos, temp);
	delete[]temp;
}
int FindSubString(char *src, char *sub, int startPos)
{
	int i, j, len_src = strlen(src), len_sub = strlen(sub), flag = NO_FIND;
	for (i = startPos; i < len_src - len_sub + 1; ++i)
	{
		flag = i - startPos;
		for (j = 0; j < len_sub; ++j)
		{
			if (src[i + j] != sub[j])
				flag = NO_FIND;
		}
		if (flag != NO_FIND)
			return flag;
	}
	return flag;
}
bool IsSubString(char *src, char *sub)
{
	if (FindSubString(src, sub, 0) == -1)
		return false;
	return true;
}
int CountMatches(char *src, char *sub)
{
	int i, j, len_src = strlen(src), len_sub = strlen(sub), flag = NO_FIND, count = 0;
	for (i = 0; i < len_src - len_sub + 1; ++i)
	{
		flag = i;
		for (j = 0; j < len_sub; ++j)
		{
			if (src[i + j] != sub[j])
				flag = NO_FIND;
		}
		if (flag != NO_FIND)
			count += 1;
	}
	return count;
}

// test
void CopySubString(char* dest, char* src, int startPos, int numChars)
{
	StringNCopy(dest, src + startPos, numChars);
	dest[numChars] = '\0';
}
void InsertSubString(char* str, char* substr, int startPos)
{
	int length = strlen(str);
	int sublength = strlen(substr);
	char* temp;
	if (startPos >= length)
	{
		startPos = length;
		StringCopy(str + startPos, substr);
	}
	else
	{
		temp = new char[length - startPos + 1];
		StringCopy(temp, str + startPos);
		StringCopy(str + startPos, substr);
		StringCopy(str + startPos + sublength, temp);
		delete[] temp;
	}
}