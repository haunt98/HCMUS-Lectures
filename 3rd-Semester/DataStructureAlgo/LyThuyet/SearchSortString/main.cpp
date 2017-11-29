#include "random.h"
#include "search.h"
#include "sort.h"
#include "strmatch.h"
#include <iostream>
using namespace std;

#define MAXSIZE 10

int main()
{
    char T[] = "abcbabcab";
    char P[] = "ababcdabcdea";
    cout << naiveMatch(T, P) << endl;
    cout << dfaMatch(T, P) << endl;
    cout << kmpMatch(T, P) << endl;
    cout << hpMatch(T, P) << endl;
    cout << rkMatch(T, P) << endl;
    return 0;
}
