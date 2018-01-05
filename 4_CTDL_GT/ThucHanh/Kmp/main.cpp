#include "kmp.h"
#include <iostream>
using namespace std;

int main()
{
	char T[] = "ababaca";
	char P[] = "ca";
	cout << kmpMatch(T, P) << endl;

	return 0;
}
