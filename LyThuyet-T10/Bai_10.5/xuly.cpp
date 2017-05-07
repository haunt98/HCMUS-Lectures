#include "xuly.h"

Apartment createApartment(int Floor, int Room)
{
	Apartment A;
	A.money = new int*[Floor];
	for (int i = 0; i < Floor; i++)
	{
		A.money[i] = new int[Room];
	}
	srand(time(NULL));
	for (int i = 0; i < Floor; i++)
	{
		for (int j = 0; j < Room; j++)
			A.money[i][j] = rand() % 10;
	}
	A.Floor = Floor;
	A.Room = Room;
	return A;
}

void showApartment(Apartment A)
{
	cout << "Building " << endl;
	for (int i = A.Floor - 1; i >= 0; i--)
	{
		for (int j = 0; j < A.Room; j++)
		{
			cout << A.money[i][j] << " ";
		}
		cout << endl;
	}
	cout << "End Building" << endl;
}

void delApartment(Apartment &A)
{
	for (int i = 0; i < A.Floor; i++)
	{
		delete[]A.money[i];
	}
	delete[]A.money;
}

// Phong o tren = max 3 phong ngay o duoi + money tai phong do
int max_ij_1(Apartment A, int i, int j, int **solution, int **track)
{
	if (i == 0) // Tang tret
	{
		for (int temp = 0; temp < A.Room; temp++)
		{
			solution[i][temp] = A.money[i][temp];
			track[0][temp] = 0;
		}
	}
	else
	{
		if (solution[i][j] == -1)
		{
			int X, Y, Z;
			if (j == 0) // Phong dau tien
			{
				X = max_ij_1(A, i - 1, j, solution, track);
				Y = max_ij_1(A, i - 1, j + 1, solution, track);
				if (X > Y)
				{
					solution[i][j] = X;
					track[i][j] = 0;
				}
				else
				{
					solution[i][j] = Y;
					track[i][j] = 1;
				}
			}
			else if (j == A.Room - 1) // Phong cuoi cung
			{
				X = max_ij_1(A, i - 1, j - 1, solution, track);
				Y = max_ij_1(A, i - 1, j, solution, track);
				if (X > Y)
				{
					solution[i][j] = X;
					track[i][j] = -1;
				}
				else
				{
					solution[i][j] = Y;
					track[i][j] = 0;
				}
			}
			else
			{
				X = max_ij_1(A, i - 1, j - 1, solution, track);
				Y = max_ij_1(A, i - 1, j, solution, track);
				Z = max_ij_1(A, i - 1, j + 1, solution, track);
				if (X > Y && X > Z)
				{
					solution[i][j] = X;
					track[i][j] = -1;
				}
				else if (Y > X && Y > Z)
				{
					solution[i][j] = Y;
					track[i][j] = 0;
				}
				else
				{
					solution[i][j] = Z;
					track[i][j] = 1;
				}
			}
			solution[i][j] += A.money[i][j];
		}
	}
	return solution[i][j];
}

void show_max_track_1(Apartment A)
{
	// creat olution and track
	int **solution = new int*[A.Floor];
	for (int i = 0; i < A.Floor; i++)
	{
		solution[i] = new int[A.Room];
	}
	for (int i = 0; i < A.Floor; i++)
	{
		for (int j = 0; j < A.Room; j++)
		{
			solution[i][j] = -1;
		}
	}
	int **track = new int*[A.Floor];
	for (int i = 0; i < A.Floor; i++)
	{
		track[i] = new int[A.Room];
	}
	// max money in highest
	int temp = 0;
	int j_max = 0;
	for (int j = 0; j < A.Room; j++)
	{
		if (temp < max_ij_1(A, A.Floor - 1, j, solution, track))
		{
			temp = max_ij_1(A, A.Floor - 1, j, solution, track);
			j_max = j;
		}
	}
	// print track
	int i = A.Floor - 1;
	int j = j_max;
	int *print_track = new int[A.Floor];
	while (i >= 0)
	{
		print_track[i] = j;
		j = j + track[i][j];
		i--;
	}
	cout << "Cach di : " << endl;
	for (int i = 0; i < A.Floor; i++)
	{
		cout << "Tang " << i << " Phong " << print_track[i] << endl;
	}
	// delete solution and track
	for (int i = 0; i < A.Floor; i++)
	{
		delete[]solution[i];
	}
	delete[]solution;
	for (int i = 0; i < A.Floor; i++)
	{
		delete[]track[i];
	}
	delete[]track;
}

int max_ij_2(Apartment A, int i, int j, int **track)
{
	int **solution = new int*[A.Floor];
	for (int temp = 0; temp < A.Floor; temp++)
	{
		solution[temp] = new int[A.Room];
	}
	// tao gia tri ban dau
	for (int temp = 0; temp < A.Room; temp++)
	{
		solution[0][temp] = A.money[0][temp];
		track[0][temp] = 0;
	}
	// vong lap
	int flo, roo;
	for (flo = 1; flo < i; flo++)
	{
		for (roo = 0; roo < A.Room; roo++)
		{
			int X, Y, Z;
			if (roo == 0)
			{
				X = solution[flo - 1][roo];
				Y = solution[flo - 1][roo + 1];
				if (X > Y)
				{
					solution[flo][roo] = X;
					track[flo][roo] = 0;
				}
				else
				{
					solution[flo][roo] = Y;
					track[flo][roo] = 1;
				}
			}
			else if (roo == A.Room - 1)
			{
				X = solution[flo - 1][roo - 1];
				Y = solution[flo - 1][roo];
				if (X > Y)
				{
					solution[flo][roo] = X;
					track[flo][roo] = -1;
				}
				else
				{
					solution[flo][roo] = Y;
					track[flo][roo] = 0;
				}
			}
			else
			{
				X = solution[flo - 1][roo - 1];
				Y = solution[flo - 1][roo];
				Z = solution[flo - 1][roo + 1];
				if (X > Y && X > Z)
				{
					solution[flo][roo] = X;
					track[flo][roo] = -1;
				}
				else if (Y > X && Y > Z)
				{
					solution[flo][roo] = Y;
					track[flo][roo] = 0;
				}
				else
				{
					solution[flo][roo] = Z;
					track[flo][roo] = 1;
				}
			}
			solution[flo][roo] += A.money[flo][roo];
		}
	}
	if (j == 0)
	{
		int X = solution[i - 1][j];
		int Y = solution[i - 1][j + 1];
		if (X > Y)
		{
			solution[i][j] = X;
			track[i][j] = 0;
		}
		else
		{
			solution[i][j] = Y;
			track[i][j] = 1;
		}
	}
	else if (j == A.Room - 1)
	{
		int X = solution[i - 1][j - 1];
		int Y = solution[i - 1][j];
		if (X > Y)
		{
			solution[i][j] = X;
			track[i][j] = -1;
		}
		else
		{
			solution[i][j] = Y;
			track[i][j] = 0;
		}
	}
	else
	{
		int X = solution[i - 1][j - 1];
		int Y = solution[i - 1][j];
		int Z = solution[i - 1][j + 1];
		if (X > Y && X > Z)
		{
			solution[i][j] = X;
			track[i][j] = -1;
		}
		else if (Y > X && Y > Z)
		{
			solution[i][j] = Y;
			track[i][j] = 0;
		}
		else
		{
			solution[i][j] = Z;
			track[i][j] = 1;
		}
	}
	solution[i][j] += A.money[i][j];
	int result = solution[i][j];
	for (int temp = 0; temp < A.Floor; temp++)
	{
		delete[]solution[temp];
	}
	delete[]solution;
	return result;
}

void show_max_track_2(Apartment A)
{
	// create track
	int **track = new int*[A.Floor];
	for (int i = 0; i < A.Floor; i++)
	{
		track[i] = new int[A.Room];
	}
	// max money in highest
	int temp = 0;
	int j_max = 0;
	for (int j = 0; j < A.Room; j++)
	{
		if (temp < max_ij_2(A, A.Floor - 1, j, track))
		{
			temp = max_ij_2(A, A.Floor - 1, j, track);
			j_max = j;
		}
	}
	// print track
	int i = A.Floor - 1;
	int j = j_max;
	int *print_track = new int[A.Floor];
	while (i >= 0)
	{
		print_track[i] = j;
		j = j + track[i][j];
		i--;
	}
	cout << "Cach di : " << endl;
	for (int i = 0; i < A.Floor; i++)
	{
		cout << "Tang " << i << " Phong " << print_track[i] << endl;
	}
	for (int i = 0; i < A.Floor; i++)
	{
		delete[]track[i];
	}
	delete[]track;
}