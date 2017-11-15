#include "SlinkedList.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    ref_n head = NULL;
    ref_n tail = NULL;

    int size = 4;
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
    {
        addHead(head, tail, rand() % 100);
    }

    priList(head, tail);

    delList(head, tail);

    return 0;
}
