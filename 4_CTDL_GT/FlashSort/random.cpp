#include "random.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define RANDMAX 10

void myswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void randArr(int *&arr, int size)
{
	srand(time(NULL));
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % RANDMAX;
	}
}

void printArr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool isSorted(int *arr, int size)
{
	if (size == 1)
		return true;
	if (arr[size - 2] > arr[size - 1])
		return false;
	return isSorted(arr, size - 1);
}