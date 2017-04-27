#include <iostream>
using namespace std;

// top-down
// Chieu dai max khi ket thuc tai i
// them track
int max_long_i_1(int *a, int i, int *solution, int *track);

void show_track_1(int *a, int size, int *track);

// bottum-up
int max_long_i_2(int *a, int i, int *track);

void show_track_2(int *a, int size, int *track);