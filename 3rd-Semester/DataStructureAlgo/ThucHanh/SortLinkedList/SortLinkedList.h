#ifndef _SORTLINKEDLIST_H
#define _SORTLINKEDLIST_H

#include "LinkedList.h"
#include <string>

using namespace std;

// Test
void resetList(List &l, int size, int *arr_test);
bool isSort(List l);

// Quick sort
void quickSortWithPrev(List &l, pNode prevList);
void quickSort(List &l);

// Merge sort
void divideList(List &l, List &lleft, List &lright);
void merge(List &l, List &lleft, List &lright);
void mergeSort(List &l);

// Insertion sort
void insertionSort(List &l);

// Selection sort
void selectionSort(List &l);

#endif