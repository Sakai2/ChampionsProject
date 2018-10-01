#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "ChangeColors.h"
#include "DetectBlocText.h"
#include "NeuralNetwork.h"
#include "DetectLetters.h"

int main()
{
	Matrix c = aleaMatrix(2, 2);
	printMatrix(c);
	printf("\n\n\n\n");
	Matrix d = aleaMatrix(2, 3);
	printMatrix(d);
	printf("\n\n\n\n");
	Matrix e = multMatrix(c, d);
	printMatrix(e);


	system("PAUSE");
	return(0);
}