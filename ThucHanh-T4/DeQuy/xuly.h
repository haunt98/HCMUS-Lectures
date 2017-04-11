#include <iostream>
using namespace std;
#define MAX 100
#define YES 1
#define NO 0

int giai_thua(int n);

// S2(n) = 1 + (1 / 3) + (1 / 5) + .. + 1 / (2n + 1)
double tinh_S2(int n);

// S3(n) = (1/2) + (3/4) + .. + ((2n+1)/(2n+2))
double tinh_S3(int n);

// S4(n,x) =  x + x^2 + x^3 + .. + x^n
double tinh_S4(int n, double x);

// S5(n,x) =  x + (x2/ (1 + 2)) + (x3/ (1 + 2 + 3)) + .. + (xn/ (1 + 2 + .. + n))
double tinh_S5(int n, double x);

double x_mu_n(int n, double x);

int countPrime(int *a, int left, int right);

bool isPrime(int n);

void inputArray(int *a, int &n);

int countPerfect(int *a, int left, int right);

bool isPerfect(int n);

int sumEven(int *a, int left, int right);

void outputPrimePos(int *a, int left, int right);

void outputEvenPos(int *a, int left, int right);

// Tong cac so trong mang lon hon gia tri lien truoc
int sumBigger(int *a, int left, int right);

// Dem cac gia tri phan biet trong mang
int countDiffe(int *a, int size);

// Kiem tra x co trong mang khong ? Tra ve 0 va 1
int appearArray(int *a, int left, int right, int x);