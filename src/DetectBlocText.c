#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Matrix.h"

//colorise the pixels between two '1' verticaly
void coloriseV(Matrix mat,int i, int j int count)
{
  for(int k = 0; k < count; k++)
  {
      mat.mat[j+i*mat.y] = 1;
  }
}

//colorise the pixels between two '1' honrizontaly
void coloriseH(Matrix mat,int i, int j, int count)
{
  for(int k = 0; k < count; k++)
  {
      mat.mat[i+j*mat.x] = 1;
  }
}

//calcul the distance between two '1' in the image verticaly
int distanceV(Matrix mat, int i, int j, int max, Matrix Colori)
{
  int count = 0;
  while(mat.mat[i+j*mat.x] == 0 && count < max)
  {
      count++;
  }
  if(count <= max)
  {
     coloriseV(colori,i,j,count)
	 return count;
  }
  else
    return -1;
}

//calcul the distance between two '1' in the image honrizontally
int distanceH(Matrix mat, int i, int j, int max, Matrix colori)
{
  int count = 0;
  while (mat.mat[j + i * mat.y] == 0 && count < max)
  {
	  count++;
  }
  if(count <= max)
  {
      coloriseV(colori,i,j,count);
      return count;
  }
  else
    return -1;
}

//give us an image after a Vertical RLSA
Matrix RlsaVertical(Matrix mat, int max)
{
  Matrix c = ConstructMatrix(mat.x, mat.y);
  initMatrix(c);

  for(int i = 0; i < c.y; i++)
  {
      for(int j = 0; j < c.x; j++)
	  {
			if(mat.mat[i+j*c.x] == 1)
			{
				int test = distanceV(mat,i,j,max,c);
				if(test != 1)
					j+=test;
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

  for(int i = 0; i < c.x; i++)
  {
		for(int j = 0; j < c.y; j++)
		{
			if(c.mat[j + i * c.y] == 1)
			{
				int test = distanceH(mat,i,j+1,max,c) 
				if (test != -1)
				j+= test;
			}
		}
  }
  return c;
}

//Main fonction of the LRSA, call all of the fonction 
Matrix RlsaGlobal(Matrix mat, int max)
{
  Matrix vertical = RlsaVetical(mat,max);
  Matrix Horizontal = RlsaHorizontal(mat,max);
  Matrix RLSA = OrBinary(Vertical,Horizontal); //Or with two matrices for the 0
  return RLSA;
}