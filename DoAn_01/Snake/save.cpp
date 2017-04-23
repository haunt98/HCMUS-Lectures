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
	for (int i = 0; i < FOOD_INDEX; ++i)
	{
		fprintf(f, "%d %d ", food[i].x, food[i].y);
	}
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
	for (int i = 0; i < FOOD_INDEX; ++i)
	{
		fscanf(f, "%d %d", &food[i].x, &food[i].y);
	}
}