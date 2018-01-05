#include <iostream>
using namespace std;

#define NO_FIND -1
// dest : destination
// src : source

// work
char *StringNCopy(char *dest, char *src, int num_char_copy);
char *StringCopy(char *dest, char *src);
void DeleteSubString(char *src, int startPos, int num_char_del);
int FindSubString(char *src, char *sub, int startPos);
bool IsSubString(char *src, char *sub);
int CountMatches(char *src, char *sub);

// test
void CopySubString(char *dest, char *src, int startPos, int numChars);
void InsertSubString(char *str, char *substr, int startPos);