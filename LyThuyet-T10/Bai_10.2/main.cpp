#include "xuly.h"

int main()
{
	// Tim chuoi con tang dan dai nhat
	int a[] = { 1, -1, 2, 3, 13, 7, 11 };
	cout << "top-down" << endl;
	int *track = new int[7];
	show_track_1(a, 7, track);
	cout << "bottum-up" << endl;
	show_track_2(a, 7, track);
	delete[]track;
	return 0;
}