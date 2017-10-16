#include "string_search.h"

// Su dung DFA
// Tao bang 2D luu cac state (trang thai),
// biet o vi tri i, chu tiep theo la 'c',
// trang thai tiep theo la Table[i]['c'-'a']
// Cach tao bang luu cac state,
// o vi tri i, chu tiep theo la 'c': P[0..i-1]c
// lay Q[] dai nhat sao cho Q[] vua la prefix vua la postfix
// state tiep theo chinh la chieu dai cua Q
int **getTable(const char *P);
int strSearchDFABrute(const char *T, const char *P);
