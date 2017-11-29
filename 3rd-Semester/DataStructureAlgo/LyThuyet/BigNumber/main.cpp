#include "big.h"
#include <iostream>

using namespace std;

int main()
{
    BigNum a("1");
    BigNum b("11111");
    a -= b;
    a.print();
    return 0;
}