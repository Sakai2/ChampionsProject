#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996) //sinon scanf marche pas




/*
int main(int argc, const char * argv[]) {
	FILE* fp;
	fp = fopen("test.bmp", "r");
	printf("teest");					//pour ouvrir un doc
	system("PAUSE");
	fclose(fp);
	return 0;
}*/

typedef struct Matrix Matrix;
struct Matrix
{
	int x;
	int y;
	int* mat;// = malloc(x*y * sizeof(int);
};


int rand_a_b(int a, int b)
{
	return rand() % (b - a) + a;		//genere un nombre alea dans [a,b[
}


int main()
{
	Matrix matrice;
	matrice.x = 20;
	matrice.y = 20;
	int* rand;
	matrice.mat = malloc(20 * 20 * sizeof(int));
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++) {
			rand = rand_a_b(0, 255);
			//printf("%d ", rand);
			if (rand > 128)
				matrice.mat[i, j] = 1;		//si pixel > 128, alors il devient blanc, noir sinon
			else
				matrice.mat[i, j] = 0;
			printf("%d ", matrice.mat[i, j]);
		}
		printf("\n");
	}

	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", matrice.mat[i, j]);
		}
		printf("\n");
	}*/
	int test;
	scanf("%d", &test);		//pour freezer la console
}



