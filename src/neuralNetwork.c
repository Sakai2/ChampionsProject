#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Sigmoide(double x)
{
  return (1.0/(1.0 + exp(-x)));
}

double Random()
{
	return rand()/(double)RAND_MAX;
}

typedef struct RRN
{
	int nbrInput;
	int nbrHidden;
	int nbrOutput;

	double *InputValues;
	double *Goal;

	double Error_rate;
}RRN;

RRN Initialize()
{
	RRN neu;
	neu.nbrInput = 2;
	//neu.Hidden = 3;
	neu.InputValue = malloc(sizeof(double)*8);
	neu.Goal = malloc(sizeof(double)*4);
	
	neu.Error_rate = 0.0;

	return neu;
}

void InitializeValues(RRN *reu)//*neu 
}
*((*neu).InputValues[0]) = 0; // pointeur to pointeur
*((*neu).InputValues[1]) = 0;
*((*neu).InputValues[2]) = 1;
*((*neu).InputValues[3]) = 0;
*((*neu).InputValues[4]) = 0;
*((*neu).InputValues[5]) = 1;
*((*neu).InputValues[6]) = 1;
*((*neu).InputValues[7]) = 1;

*((*neu).Goal[0]) = 0;
*((*neu).Goal[1]) = 1;
*((*neu).Goal[2]) = 1;
*((*neu).Goal[3]) = 0;

}
