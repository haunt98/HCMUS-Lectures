#include "face.h"
#include <iostream>

using namespace std;

int EyedFace::count = 0;

int main()
{
	Face fc;
	Face fc1("Rectangle");
	testFace(&fc1);

	EyedFace e1("1", 1);
	cout << e1.count << endl;
	EyedFace e2("2", 2);
	cout << e2.count << endl;
	EyedFace e3("3", 3);
	cout << e3.count << endl;

	return 0;
}