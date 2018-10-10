#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

//colorise the pixels between two '1' verticaly
void coloriseV(Matrix mat, int i, int j, int count)
{
	int ji = j;
	int k = 0;
	while (mat.mat[i + ji * mat.y] == 0 && k < count)
	{
		mat.mat[i + ji * mat.y] = 1;
		k++;
		ji++;
	}
}

//colorise the pixels between two '1' horizontaly
void coloriseH(Matrix mat, int i, int j, int count)
{
	int ji = j;
	int k = 0;
	while (mat.mat[ji + i * mat.y] != 1 && k < count)
	{
		mat.mat[ji + i * mat.y] = 1;
		ji++;
		k++;
	}
}

//calcul the distance between two '1' in the image verticaly
int distanceV(Matrix mat, int i, int j, int max, Matrix Colori)
{
	int count = 0;
	int ji = j;
	while (mat.mat[i + ji * mat.y] == 0 && ji < mat.x)
	{
		count++;
		ji++;
	}

	if (count < max && ji != mat.x)
	{
		coloriseV(Colori, i, j, count);
	}
	return count;
}

//calcul the distance between two '1' in the image horizontally
int distanceH(Matrix mat, int i, int j, int max, Matrix colori)
{
	int count = 0;
	int ji = j;
	while (mat.mat[ji + i * mat.y] == 0 && ji < mat.y)
	{
		count++;
		ji += 1;
	}
	if (count < max && ji != mat.y)
	{
		coloriseH(colori, i, j, count);
	}
	return count;
}

//give us an image after a Vertical RLSA
Matrix RlsaVertical(Matrix mat, int max)
{
	Matrix c = ConstructMatrix(mat.x, mat.y);
	initMatrix(c);
	int test = 0;
	for (int i = 0; i < c.y; i++)
	{
		for (int j = 0; j < c.x; j++)
		{
			if (mat.mat[i + j * c.y] == 1)
			{
				c.mat[i + j * c.y] = 1;
				test = distanceV(mat, i, j + 1, max, c);
				j += test;
				test = 0;
			}
		}
	}
	return c;
}

//give us an image after a Honrizontal RLSA
Matrix RlsaHorizontal(Matrix mat, int max)
{
	Matrix c = ConstructMatrix(mat.x, mat.y);
	initMatrix(c);
	int test = 0;
	for (int i = 0; i < c.x; i++)
	{
		for (int j = 0; j < c.y; j++)
		{
			if (mat.mat[j + i * c.y] == 1)
			{
				c.mat[j + i * c.y] = 1;
				test = distanceH(mat, i, j + 1, max, c);
				j += test;
				test = 0;
			}
		}
	}
	return c;
}

//Main fonction of the LRSA, call all of the fonction
Matrix RlsaGlobal(Matrix mat, int max)
{
	Matrix Vertical = RlsaVertical(mat, max);
	Matrix Horizontal = RlsaHorizontal(mat, max);
	//printf("\n\n\n");
	printMatrix(Vertical);
	//printf("\n\n\n");
	printMatrix(Horizontal);
	Matrix RLSA = andBinary(Vertical, Horizontal); //"Or" for the 0 with two matrices
	return RLSA;
}
