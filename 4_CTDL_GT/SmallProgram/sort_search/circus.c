#include <stdio.h>

struct Per {
	int height, weight;
};

int compare(struct Per A, struct Per B);
void sortCircus(struct Per *arr, int *n);

int main()
{
	return 0;
}

int compare(struct Per A, struct Per B)
{
	if (A.height > B.height && A.weight > B.weight)
		return 1;
	else if (A.height < B.height && A.weight < B.weight)
		return -1;
	return 0;
}

void sortCircus(struct Per *arr, int *n);
