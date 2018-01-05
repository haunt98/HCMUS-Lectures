#include "an.h"
#include "animal.h"
#include "dichuyen.h"
#include "sinhsan.h"
#include "xuly.h"
#include <iostream>

using namespace std;

int main()
{
	ConCaMap a;
	ConCaMap b;

	thiBoi(&a, &b);

	nuoiCa(&a);

	ConCaSau c;
	nuoiBoSat(&c);

	return 0;
}
