#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

// giver string text and string word
// find the first occurrence of word in text
int bruteSearch(char *text, char *word)
{
	bool flag;
	for (int cur = 0; cur <= strlen(text) - strlen(word);
	     cur++) // go through text
	{
		flag = true; // reset flag for every index
		for (int i = cur; text[i] & word[i - cur]; i++) {
			if (text[i] != word[i - cur])
				flag = false; // 1 error make difference
		}
		if (flag)
			return cur;
	}
	return -1;
}

// longest proper prefix for word
vector<int> fixWord(char *word)
{
	vector<int> temp(strlen(word));
	temp[0] = 0; // the first always 0

	int i = 1;   // run from 1
	int len = 0; // len of longest prefix

	while (i < temp.size()) {
		if (word[i] == word[len]) {
			len++;
			temp[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = temp[len - 1]; // I don't know
						     // do not increment i here
			} else {
				temp[i] = 0;
				i++;
			}
		}
	}
	return temp;
}

// Use KMP algorithm
int KMPSearch(char *text, char *word)
{
	bool flag;
	vector<int> prefixWord = fixWord(word);
	int i = 0; // for text
	int j = 0; // for word
	while (i < strlen(text)) {
		if (word[j] == text[i]) {
			i++, j++;
		} else if (j == strlen(word)) {
			return i - j; // end at j so
		}
		// mismatch after j matched
		else if (i < strlen(word) && word[j] != text[i]) {
			if (j != 0) {
				j = prefixWord[j - 1];
			} else {
				i++;
			}
		}
	}
	return -1;
}

// print vector int
void printVect(vector<int> temp)
{
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << " ";
	}
	cout << endl;
}

int main()
{
	char text[] = "abc23a123b123c123";
	char word[] = "123";

	int i_b = bruteSearch(text, word);
	cout << i_b << endl;
	int i_kmp = KMPSearch(text, word);
	cout << i_kmp << endl;
	return 0;
}
