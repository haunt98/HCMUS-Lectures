#include <iostream>

int sum(int a, int b)
{
	std::cout << "int" << std::endl;
	return a + b;
}

double sum(double a, double b)
{
	std::cout << "double" << std::endl;
	return a + b;
}

int sum(int a, int b, int c)
{
	std::cout << "3 int" << std::endl;
	return a, b, c;
}

void printArr(int *arr, int size)
{
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void printArr(double *arr, int size)
{
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int A[] = {2, 3, 4};
	int size_A = sizeof(A) / sizeof(A[0]);

	double B[] = {2.2, 3.4, 4.5};
	int size_B = sizeof(B) / sizeof(B[0]);

	printArr(A, size_A);
	printArr(B, size_B);
	return 0;
}
