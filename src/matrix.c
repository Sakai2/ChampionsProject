#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h"



void printMatrix(Matrix mat) //for print the Matrix
{
	for (int i = 0; i < mat.x; i++)
	{
		for (int j = 0; j < mat.y; j++)
		{
			printf("%d ", mat.mat[j+i*mat.y]); //j + i * nbr de colonne
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
			a.mat[j + i * a.y] = 0; //like a.mat[i,j]
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
			c.mat[j + i * c.y] += a.mat[j + i * a.y] + b.mat[j + i * b.y];
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
			if (a.mat[j + i * a.y] - b.mat[j + i * b.y] >= 0)
				c.mat[j + i * c.y] += a.mat[j + i * a.y] - b.mat[j + i * b.y];
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
				c.mat[j + i * c.y] += a.mat[k + i * a.y] * b.mat[j + k * b.y];
			}		//[j,k]					//[i,k]				[k,j]
		}
	}
	return(c);
}

Matrix giveMatrixDiag(int x, int y)
{
	Matrix c = ConsrtuctMatrix(x, y);
	initMatrix(c);
	for (int i = 0; i < c.x; i++)
	{
		for (int j = 0; j < c.y; j++)
		{
			if (i == j)
				c.mat[j + i * c.y] = 1;
			else
				c.mat[j + i * c.y] = 0;
		}
	}
	return c;
}

Matrix multMatrixLambda(Matrix a, int lambda) //multiplication between a matrice and an integer
{
	Matrix c = ConsrtuctMatrix(a.x, a.y);
	initMatrix(c);
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			c.mat[j + i * c.y] += a.mat[j + i * a.y] * lambda;
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
			c.mat[j + i * c.y] += a.mat[j + i * a.y] + lambda;
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
			if (a.mat[j + i * a.y] - lambda >=0)
				c.mat[j + i * a.y] += a.mat[j + i * a.y] - lambda;
		}
	}
	return(c);
}

int rand_a_b(int a, int b)
{
	srand(time(NULL));
	return rand() % (b - a) + a;		//genere un nombre alea dans [a,b[
}

Matrix aleaMatrix(int x, int y)
{
	Matrix matrice = ConsrtuctMatrix(x, y);
	initMatrix(matrice);
	int* rand;
	int rand2;
	srand(time(NULL)); //le random change à chaque test
	for (int i = 0; i < matrice.x; i++)
	{
		for (int j = 0; j < matrice.y; j++) 
		{
			rand = rand_a_b(0, 10);
			rand2 = rand;
			matrice.mat[j + i * matrice.y] += rand2;
		}
	}
	return(matrice);
}

Matrix OrBinary(Matrix a, Matrix b)
{
  Matrix mat = ConstructMatrix(a.x, a.y);
  if(a.x == b.x && a.y == b.y)
    {
      for(int i = 0; i < a.x; i++)
	{
	  for(int j = 0; j < a.y; j++)
	    {
	      if(a.mat[j+i*a.y] == 0 || b.mat[j+i*b.y] == 0)
		mat.mat[j+i*mat.y] = 0;
	      else
		mat.mat[j+i*mat.y] = 1;	  
	    }
	}
    }
  return mat;
}
