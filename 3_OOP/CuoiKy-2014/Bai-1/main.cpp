#include "bike.h"
#include <iostream>

using namespace std;

int main()
{
    char cb1[] = "b1";
    char cb2[] = "b2";
    EBike b1(cb1);
    EBike b2(cb2);
    display(b1, b2);
    return 0;
}