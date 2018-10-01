#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "ChangeColors.h"
#include "DetectBlocText.h"
#include "NeuralNetwork.h"
#include "DetectLetters.h"

int main()
{
	Matrix c = ConsrtuctMatrix(4, 4);
	initMatrix(c);
	printMatrix(c);

	system("PAUSE");
	return(0);
}