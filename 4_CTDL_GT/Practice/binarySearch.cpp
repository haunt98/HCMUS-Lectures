#include <iostream>

using namespace std;

// binary search x in sorted array
// return index or -1 if not found
int binarySearch(int x, int *A, int low, int high)
{
	if (low == high) {
		if (A[low] == x)
			return low;
		return -1;
	}
	int mid = (low + high) / 2;
	if (A[mid] == x)
		return mid;
	else if (A[mid] > x) {
		return binarySearch(x, A, low, mid - 1);
	} else {
		return binarySearch(x, A, mid + 1, high);
	}
}

int main()
{
	int A[] = {1, 2, 3, 5, 6, 8, 9, 11, 12, 13, 20, 21, 22};
	int size = sizeof(A) / sizeof(A[0]);

	int x;
	cin >> x;
	int i = binarySearch(x, A, 0, size - 1);
	cout << "A[" << i << "] = " << A[i] << endl;

	return 0;
}
