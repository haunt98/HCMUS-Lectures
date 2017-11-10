#include "xuly.h"

void towerHanoi(int n, char src, char dest, char temp)
{
	if (n == 1)
	{
		cout << "Move 1 disk from " << src << " to " << dest << endl;
		return;
	}
	towerHanoi(n - 1, src, temp, dest);
	towerHanoi(1, src, dest, temp);
	towerHanoi(n - 1, temp, dest, src);
}