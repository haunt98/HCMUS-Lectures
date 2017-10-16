#include "random.h"
#include "search.h"
#include "sort.h"
#include "string_search.h"
#include <iostream>
using namespace std;

#define MAXSIZE 1000

int main()
{
    cout << bruteForce("ababababc", "abc") << endl;
    return 0;
}
