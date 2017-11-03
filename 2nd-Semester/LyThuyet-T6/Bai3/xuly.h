#include <iostream>
#include <string.h>
using namespace std;
#define MAX 20

void reverseString(char *str, int left, int right);

// Tim vi tri cua chuoi con trong chuoi lon
int findSubPos(char *main_str, char *sub_str, int pos);

void upperWord(char *str, int pos);

void swapChar(char &a, char &b);

void printPermutation(char *str, int left, int right);