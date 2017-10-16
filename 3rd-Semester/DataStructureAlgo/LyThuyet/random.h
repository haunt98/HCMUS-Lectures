#ifndef RANDOM_H
#define RANDOM_H

void printArr(int *arr, int size);
void copyArr(int *arr, int size, int *new_arr);
void randArr(int *arr, int size);
void calcTime(int *arr, int size, void (*sort)(int *, int));
void calcTime(int *arr, int left, int right, void (*sort)(int *, int, int));
bool isSorted(int *arr, int size);

#endif
