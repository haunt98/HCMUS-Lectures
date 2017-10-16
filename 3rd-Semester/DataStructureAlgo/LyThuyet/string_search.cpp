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

int strSearchKMP(const char *T, const char *P)
{
    return 0;
}
