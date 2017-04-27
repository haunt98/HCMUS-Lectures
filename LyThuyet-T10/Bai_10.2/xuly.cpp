#include "xuly.h"

int max_long_i_1(int *a, int i, int *solution, int *track)
{
	if (solution[i] == -1)
	{
		if (i == 0)
		{
			solution[i] = 1;
			track[i] = -1;
		}
		else
		{
			int temp = 0, j;
			for (j = 0; j < i; j++)
			{
				if (a[j] < a[i])
				{
					if (temp < max_long_i_1(a, j, solution, track))
					{
						temp = max_long_i_1(a, j, solution, track);
						track[i] = j;
					}
				}
			}
			solution[i] = temp + 1;
		}
	}
	return solution[i];
}

void show_track_1(int *a, int size, int *track)
{
	int temp = 0;
	int i_max = 0;
	int *solution = new int[7];
	for (int i = 0; i < 7; ++i)
	{
		solution[i] = -1;
	}
	for (int i = 0; i < size; ++i)
	{
		if (temp < max_long_i_1(a, i, solution, track))
		{
			temp = max_long_i_1(a, i, solution, track);
			i_max = i;
		}
	}
	int *sub_a = new int[temp];
	for (int i = temp - 1; i >= 0; i--)
	{
		sub_a[i] = a[i_max];
		i_max = track[i_max];
	}
	for (int i = 0; i < temp; i++)
	{
		cout << sub_a[i] << " ";
	}
	cout << endl;
	delete[]sub_a;
	delete[]solution;
}

int max_long_i_2(int *a, int i, int *track)
{
	int *solution = new int[i + 1];
	int temp, j, k;
	for (j = 0; j <= i; j++)
	{
		temp = 0;
		track[j] = -1;
		for (k = 0; k < j; k++)
		{
			if (a[k] < a[j])
			{
				if (temp < solution[k])
					temp = solution[k];
				track[j] = k;
			}
		}
		solution[j] = temp + 1;
	}
	int result = solution[i];
	delete[]solution;
	return result;
}

void show_track_2(int *a, int size, int *track)
{
	int temp = 0;
	int i_max = 0;
	for (int i = 0; i < size; i++)
	{
		if (temp < max_long_i_2(a, i, track))
		{
			temp = max_long_i_2(a, i, track);
			i_max = i;
		}
	}
	int *sub_a = new int[temp];
	for (int i = temp - 1; i >= 0; i--)
	{
		sub_a[i] = a[i_max];
		i_max = track[i_max];
	}
	for (int i = 0; i < temp; i++)
	{
		cout << sub_a[i] << " ";
	}
	cout << endl;
	delete[]sub_a;
}