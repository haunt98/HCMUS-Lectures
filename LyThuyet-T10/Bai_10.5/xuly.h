#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;

//test
struct Apartment{
	int **money;
	int Floor;
	int Room;
};

Apartment createApartment(int Floor, int Room);
void showApartment(Apartment A);
void delApartment(Apartment &A);

// Top-down
// Max money in floor : i  ; room : j
int max_ij_1(Apartment A, int i, int j, int **solution, int **track);

void show_max_track_1(Apartment A);

// Bottum-up
int max_ij_2(Apartment A, int i, int j, int **track);

void show_max_track_2(Apartment A);