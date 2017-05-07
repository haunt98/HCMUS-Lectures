#include "xuly.h"
#define M 4
#define N 5

int main()
{
	Apartment A = createApartment(M, N);
	showApartment(A);
	cout << "Top-down" << endl;
	show_max_track_1(A);
	cout << "Bottom-up" << endl;
	show_max_track_2(A);
	//delete apartment
	delApartment(A);
	return 0;
}