#include "myfsort.h"
#include "random.h"
#include "utah.h"
#include <iostream>

using namespace std;

#define MYSIZE 10

int main()
{
	int *arr;
	int size = MYSIZE;
	randArr(arr, size);
	// printArr(arr, size);
	myFlashSort(arr, size);
	// printArr(arr, size);
	cout << "Sorted: " << isSorted(arr, size) << endl;
	delete[] arr;
	return 0;
}
