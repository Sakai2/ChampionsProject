#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996) //sinon scanf marche pas

typedef struct Matrix Matrix;
struct Matrix
{
	int x;
	int y;
	int* mat; // = malloc(x*y * sizeof(int);
};

Matrix detectBloc(Matrix matrix)
{

	int maxSpace = 3;
	int count = 0;
	int i = 0; int j = 0;
	while (i < matrix.x && matrix.mat[i, j] != 0)
	{
		while (j < matrix.y && matrix.mat[i, j] != 0)
		{
			j++;
			count++;
			printf("%d ", count);
		}
		if (matrix.mat[i, j] != 0)
		{
			i++;
			j = 0;
		}
		else
		{
			i = matrix.x;
		}
	}

	while (i < matrix.x)
	{
		if (matrix.mat[i, j] == 0)
			//donner couleur noir au pixel
			i++;
		else if (i + 1 < matrix.x && i + 2 < matrix.x && matrix.mat[i + 1] == 0 || matrix.x && matrix.mat[i + 2] == 0)
			i += 2;
		else
			//do something
			i += maxSpace;
	}
}

int rand_a_b(int a, int b)
{
	return rand() % (b - a) + a;
}

int test()
{
	Matrix mat;
	mat.x = 10;
	mat.y = 10;
	int* rand;
	srand(time(NULL));
	mat.mat = malloc(10 * 10 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			rand = rand_a_b(0, 2);
			mat.mat[i, j] = rand;
		}
	}
	detectBloc(mat);
	printf("\n\n\n");
	printMat(mat);

	int test;
	scanf("%d", &test);		//pour freezer la console
	return 0;
}

int printMat(Matrix mat)
{
	for (int i = 0; i < mat.x; i++)
	{
		for (int j = 0; j < mat.y; j++)
		{
			printf("%d", mat.mat[i, j]);
		}
		printf("\n");
	}
}

