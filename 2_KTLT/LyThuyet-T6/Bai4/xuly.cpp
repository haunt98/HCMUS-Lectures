#include "xuly.h"

int to_hop(int i, int n)
{
	if (i == 0 || i == n)
		return 1;
	return to_hop(i - 1, n) * (n - i + 1) / i;
}

void tgPascal(int n)
{
	if (n == 0)
		cout << "1" << endl;
	else {
		tgPascal(n - 1);
		for (int i = 0; i <= n; ++i)
			cout << to_hop(i, n) << " ";
		cout << endl;
	}
}