#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "detectLetters.h"
#include "matrix.h"

int countOneY(int i, int j, Matrix RLSA)
{
	int countY = 0;
	int ji = j;
	while (RLSA.mat[ji + i * RLSA.y] == 1 && ji != RLSA.y)
	{
		countY++;
		ji++;
	}
	return countY;
}

int countOneX(int i, int j, Matrix RLSA)
{
	int countX = 0;
	int ji = j;
	while (RLSA.mat[ji + i * RLSA.y] == 1 && ji != RLSA.y)
	{
		countX++;
		ji += RLSA.y;
	}
	return countX;
}

void applyBox(int i, int j, int countX, int countY, Matrix trueMat)
{
	int totX = 0;
	int totY = 0;
	int realX = countX;
	int realY = countY;
	while (totY < countY + 2)
	{
		trueMat.mat[(j + totY) + i * trueMat.y] = 2;
		trueMat.mat[(j + totY) + (i + realX + 1) * trueMat.y] = 2;
		totX++;
		totY++;
	}
	totX = 0;
	totY = 0;
	while (totX < countX + 2)
	{
		trueMat.mat[(j)+(i + totX) * trueMat.y] = 2;
		trueMat.mat[(j + realY + 1) + (i + totX) * trueMat.y] = 2;
		totX++;
		totY++;
	}
}


Matrix boxColors(Matrix RLSA, Matrix trueMat)
{
	int countX = 0;
	int countY = 0;
	for (int i = 0; i < RLSA.x; i++)
	{
		for (int j = 0; j < RLSA.y; j++)
		{
			if (RLSA.mat[j + i * RLSA.y] == 1)
			{
				countX = countOneX(i, j, RLSA);
				countY = countOneY(i, j, RLSA);
				applyBox(i - 1, j - 1, countX, countY, trueMat);
				i += countX;
			}
		}
	}
	return trueMat;
}
