#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix Matrix;
struct Matrix
{
	int x;
	int y;
	int* mat;// = malloc(x*y * sizeof(int);
};

int* Matrix_to_list(Matrix tab)
{
	/*if (tab.x == NULL || tab.y == NULL || tab.x == 0 || tab.y == 0)
	{
		tab.x = 1;	tab.y = 1;
	}*/
	int n = tab.x * tab.y;
	int* toto = malloc(n * sizeof(int));
	if (toto == NULL)
	{
		printf("Memoire pas attribué");
		return 0;
	}
	int x = 0;
	for (int i = 0; i < tab.x; i++)
	{
		for (int j = 0; j < tab.y; j++)
		{
			toto[i + j + x] = tab.mat[i,j];
		}
		x += tab.y - 1;

	}
	return toto;
}
int main()
{
	Matrix matrice;
	matrice.x = 5;
	matrice.y = 5;
	matrice.mat = malloc(5 * 5 * sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			matrice.mat[i,j] = i + j;
		}
	}
	int* lol = Matrix_to_list(matrice);
}