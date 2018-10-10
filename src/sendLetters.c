#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "matrix.h"

Matrix sendPosition(Matrix mat)
{
	Matrix pos = ConstructMatrix(1,2);
	initMatrix(pos);
	int i = 0;
	int j = 0;
	while(i < mat.x)
	{
		while(j < mat.y && mat.mat[j+i*mat.y] != 2) //represent the beginning of a letter
		{
			j++;
		}
		i++;
	}
	pos.mat[0] = i;
	pos.mat[1] = j;
	return pos;
}
