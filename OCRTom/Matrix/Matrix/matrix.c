#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

void printMatrix(Matrix mat) //for print the Matrix
{
	for (int i = 0; i < mat.x; i++)
	{
		for (int j = 0; j < mat.y; j++)
		{
			printf("%d ", mat.mat[i,j]); //j + i * nbr de colonne
		}
		printf("\n");
	}
}

Matrix ConsrtuctMatrix(int x, int y) //for construct the matrix with malloc
{
	Matrix a;
	a.x = x;
	a.y = y;
	a.mat = malloc(x * y * sizeof(int));
	return(a);
}

void initMatrix(Matrix a) //init our matrix with 0
{
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			a.mat[i, j] = 0;
		}
	}
}

Matrix sumMatrix(Matrix a, Matrix b) //sum between two matrices
{
	Matrix c = ConsrtuctMatrix(a.x, a.y);
	initMatrix(c);
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			c.mat[i, j] += a.mat[i, j] + b.mat[i, j];
		}
	}
	return(c);
}

Matrix subtractionMatrix(Matrix a, Matrix b) //subtraction between two matrices
{
	Matrix c = ConsrtuctMatrix(a.x, a.y);
	initMatrix(c);
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			if (a.mat[i, j] - b.mat[i, j] >= 0)
				c.mat[i, j] += a.mat[i, j] - b.mat[i, j];
		}
	}
	return(c);
}

Matrix multMatrix(Matrix a, Matrix b) //multiplication between two matrices
{
	Matrix c = ConsrtuctMatrix(a.x, b.y);
	initMatrix(c);
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < b.y; j++)
		{
			for (int k = 0; k < b.x; k++)
			{
				c.mat[j, k] += a.mat[i, k] * b.mat[k, j];
			}
		}
	}
	return(c);
}

Matrix multMatrixLambda(Matrix a, int lambda) //multiplication between a matrice and an integer
{
	Matrix c = ConsrtuctMatrix(a.x, a.y);
	initMatrix(c);
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			c.mat[i, j] += a.mat[i, j] * lambda;
		}
	}
	return(c);
}

Matrix sumMatrixLambda(Matrix a, int lambda) //sum between a matrice and an integer
{
	Matrix c = ConsrtuctMatrix(a.x, a.y);
	initMatrix(c);
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			c.mat[i, j] += a.mat[i, j] + lambda;
		}
	}
	return(c);
}

Matrix subtractionMatrixLambda(Matrix a, int lambda) //subtraction between a matrice and an integer
{
	Matrix c = ConsrtuctMatrix(a.x, a.y);
	initMatrix(c);
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			if (a.mat[i, j] - lambda >=0)
				c.mat[i, j] += a.mat[i, j] - lambda;
		}
	}
	return(c);
}