#include "strmatch.h"
#include <iostream>
#include <string.h>

using namespace std;

// Brute-force
int naiveMatch(const char *T, const char *P)
{
    int n = strlen(T);
    int m = strlen(P);
    for (int i = 0; i <= n - m; ++i)
    {
        bool match = true; // reset for each match
        for (int j = 0; j < m; ++j)
        {
            if (P[j] != T[j + i]) // 1 error is enough
            {
                match = false;
                break;
            }
        }
        if (match == true)
            return i;
    }
    return -1;
}

// Use DFA (Determine Finite Automata)
const int ALPHABET_NUM = 256;
bool isSuffix(const char *P, int k, int q, char a)
{
    // P[0..k-1] is suffix P[0..q-1,a]
    if (k == 0)
        return true;
    if (P[k - 1] != a)
        return false;
    for (int i = q - 1, j = k - 2; j >= 0; --i, --j)
    {
        if (P[i] != P[j])
            return false;
    }
    return true;
}

dfaTable::dfaTable(const char *P)
{
    m_state = strlen(P);
    m_alphabet = ALPHABET_NUM;

    m_table = new int *[m_state + 1];
    for (int i = 0; i <= m_state; ++i)
    {
        m_table[i] = new int[m_alphabet];
    }

    for (int q = 0; q <= m_state; ++q) // 0..m state
    {
        for (int c = 0; c < m_alphabet; ++c) // list char in language sigma
        {
            int k = m_state + 1 < q + 2 ? m_state + 1 : q + 2;
            do
            {
                --k;
            } while (!isSuffix(P, k, q, c)); // end when Pk is suffix Pp'c'
            m_table[q][c] = k;
        }
    }
}

dfaTable::~dfaTable()
{
    for (int i = 0; i <= m_state; ++i)
    {
        delete[] m_table[i];
    }
    delete[] m_table;
}

int *dfaTable::operator[](int i)
{
    return m_table[i];
}

int dfaMatch(const char *T, const char *P)
{
    int n = strlen(T);
    int m = strlen(P);

    // Preprocessor P
    dfaTable table(P);

    int state = 0;
    for (int i = 0; i < n; ++i)
    {
        state = table[state][(int)T[i]];
        if (state == m) // final state
        {
            return i - m + 1;
        }
    }

    return -1;
}

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

    int q = 0; // num of char *matched* in P
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
            // this is for searching all, not the first one
            // q = pi[q];
        }
    }
    delete[] pi;
    return -1;
}

// Thuat toan Horspool
// Dac diem la xet tu phai qua
void hpTable(const char *P, int *shift)
{
    int m = strlen(P);
    for (int i = 0; i < ALPHABET_NUM; ++i)
    {
        shift[i] = m;
    }
    for (int i = 0; i < m - 1; ++i)
    {
        // Lay khoang cach tu vi tri phai nhat -> end char
        shift[(int)P[i]] = m - 1 - i;
    }
}

int hpMatch(const char *T, const char *P)
{
    int n = strlen(T);
    int m = strlen(P);

    // Preprocess tao mang shift
    int *shift = new int[ALPHABET_NUM];
    hpTable(P, shift);

    int i = m - 1;
    while (i < n)
    {
        int k = 0;                                // reset moi lan duyet
        while (k < m && P[m - 1 - k] == T[i - k]) // Duyet phai -> trai
            ++k;
        if (k == m)
            return i - m + 1;

        // Dich con tro dang xet sang phai
        // Hy vong T[i] tiep theo la end char cua P
        i += shift[(int)T[i]];
    }
    return -1;
}

// Thuat toan Rabin Karp
// Y tuong: tu P[0..m-1] -> tao ra p
// tuong tu cho T[0..m-1] -> t0, T[1..m] -> t1
// roi so sanh p va t0 t1 t2
// p co the rat lon nen ta su dung mod q
// nhung khong dam bao chinh xac nen phai check lai
// vi a = b (mod q) khong co nghia a = b
int rkMatch(const char *T, const char *P)
{
    int n = strlen(T);
    int m = strlen(P);

    const int d = sizeof(char); // size of all char
    const int mod = 10;         // for modulo
    int h = 1;                  // d^(m-1) mod q
    for (int i = 0; i < m - 1; ++i)
    {
        h = (h * d) % mod;
    }

    int hash_p = 0; // for pattern
    int hash_t = 0; // for text
    for (int i = 0; i < m; ++i)
    {
        // Giong nhu co so (base), tu trai qua
        hash_p = (d * hash_p + P[i]) % mod;
        hash_t = (d * hash_t + T[i]) % mod;
    }

    for (int i = 0; i <= n - m; ++i)
    {
        if (hash_p == hash_t)
        {
            bool match = true;
            for (int j = 0; j < n; ++j)
            {
                if (P[j] != T[i + j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return i;
            }
        }
        // Compute for next compare,
        // but not check when i==n-m, because there is no next
        // remember else if because only do this when hash_p != hash_t
        else if (i < n - m)
        {
            // i..i+m-1 -> i+1..i+m
            hash_t = (d * (hash_t - T[i] * h) + T[i + m]) & mod;
            if (hash_t < 0)
            {
                hash_t += mod;
            }
        }
    }
    return -1;
}