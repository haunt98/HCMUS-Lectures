#include "string_search.h"
#include <string.h>

// Tim kiem toan bo truong hop
int bruteForce(const char *T, const char *P)
{
    int len_T = strlen(T);
    int len_P = strlen(P);
    bool found;
    for (int i = 0; i <= len_T - len_P; ++i)
    {
        found = true;
        for (int j = i; j < i + len_P; ++j)
        {
            if (T[j] != P[j - i])
            {
                found = false;
                break;
            }
        }
        if (found == true)
            return i;
    }
    return -1;
}

// Su dung DFA
// Tao bang 2D luu cac state (trang thai),
// biet o vi tri i, chu tiep theo la 'c',
// trang thai tiep theo la Table[i]['c'-'a']
// Cach tao bang luu cac state,
// o vi tri i, chu tiep theo la 'c': P[0..i-1]c
// lay Q[] dai nhat sao cho Q[] vua la prefix vua la postfix
// state tiep theo chinh la chieu dai cua Q
int *alphabetString(const char *P);
int **computeTableDFA(const char *P);

int *alphabetString(const char *P) {}

int strSearchKMP(const char *T, const char *P)
{
    return 0;
}
