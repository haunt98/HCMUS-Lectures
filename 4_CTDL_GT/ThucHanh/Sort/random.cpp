#include "random.h"
#include <stdlib.h>
#include <time.h>

#define RANDMAX 1000000

void randArr(int *&arr, int size)
{
	srand(time(NULL));
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % RANDMAX;
	}
}

void copyArr(int *old_arr, int size, int *&new_arr)
{
	for (int i = 0; i < size; i++) {
		new_arr[i] = old_arr[i];
	}
}
