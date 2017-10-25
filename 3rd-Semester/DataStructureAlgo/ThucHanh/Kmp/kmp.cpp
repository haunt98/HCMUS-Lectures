#include "kmp.h"
#include <string.h>

// KMP algorithm
void kmpTable(const char *P, int *pi)
{
    int m = strlen(P);
    pi[0] = 0;
    int q = 0; // point to position need to be compared
    for (int i = 1; i < m; ++i)
    {
        while (q > 0 && P[q] != P[i])
        {
            q = pi[q];
        }
        if (P[q] == P[i])
        {
            ++q;
        }
        pi[i] = q;
    }
}
int kmpMatch(const char *T, const char *P)
{
    int n = strlen(T);
    int m = strlen(P);

    int *pi = new int[m];
    kmpTable(P, pi);

    int q = 0; // num of char matched in P
    // look like kmpTable but change P[i] -> T[i]
    for (int i = 0; i < n; ++i)
    {
        while (q > 0 && P[q] != T[i]) // if not matched, traverse q in pi
        {
            q = pi[q];
        }
        if (P[q] == T[i]) // if matched, increase q
        {
            ++q;
        }
        if (q == m)
        {
            delete[] pi;
            return i - m + 1;
            // q = pi[q];
        }
    }
    delete[] pi;
    return -1;
}
