#ifndef SORT_H
#define SORT_H

#include "LinkedList.h"

bool isSort(List l);

// Radix sort
int maxList(List l);
int getK(int n, int base, int k);
int soChuSo(int n, int base);
void radixListK(List &l, int base, int k);
void radixList(List &l, int base);

// Quick sort
void quickSortWithPrev(List &l, pNode prevList);
void quickSort(List &l);

// Merge sort
void merge(List &l);
void mergeSort(List &l);

#endif