#include "xuly.h"

void SaveGame(char *filename)
{
	FILE *f = fopen(filename, "w");
	fprintf(f, "%d %d\n", SIZE_SNAKE, FOOD_INDEX);
	fprintf(f, "%d %d %d\n", CHAR_LOCK, MOVING, SPEED);
	for (int i = 0; i < SIZE_SNAKE; ++i)
	{
		fprintf(f, "%d %d ", snake[i].x, snake[i].y);
	}
	fprintf(f, "\n");
	if (FOOD_INDEX)
	{
		for (int i = 0; i < FOOD_INDEX; ++i)
		{
			fprintf(f, "%d %d ", food[i].x, food[i].y);
		}
		fprintf(f, "\n");
	}
	fprintf(f, "%d\n", GATE_STATE);
	if (GATE_STATE)
	{
		for (int i = 0; i < SIZE_GATE; ++i)
			fprintf(f, "%d %d ", my_gate[i].x, my_gate[i].y);
	}
	fclose(f);
}

void LoadGame(char *filename)
{
	FILE *f = fopen(filename, "r");
	fscanf(f, "%d %d", &SIZE_SNAKE, &FOOD_INDEX);
	fscanf(f, "%d %d %d", &CHAR_LOCK, &MOVING, &SPEED);
	for (int i = 0; i < SIZE_SNAKE; ++i)
	{
		fscanf(f, "%d %d", &snake[i].x, &snake[i].y);
	}
	if (FOOD_INDEX)
	{
		for (int i = 0; i < FOOD_INDEX; ++i)
		{
			fscanf(f, "%d %d", &food[i].x, &food[i].y);
		}
	}
	fscanf(f, "%d", &GATE_STATE);
	if (GATE_STATE)
	{
		for (int i = 0; i < SIZE_GATE; ++i)
			fscanf(f, "%d %d", &my_gate[i].x, &my_gate[i].y);
	}
	fclose(f);
}