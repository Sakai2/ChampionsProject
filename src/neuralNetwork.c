#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
/bin/bash: q : commande introuvable
{
  return (1.0/(1.0 + exp(-x)));
}

double Random()
{
	return rand()/(double)RAND_MAX;
}


RRN Initialize()
{
	RRN neu;
	neu.nbrInput = 2;
	//neu.Hidden = 3;
	neu.InputValue = malloc(sizeof(int)*8);
	neu.Goal = malloc(sizeof(int)*4);
	neu.WeightIH = malloc(sizeof(double)*neu.nbrInput*neu.nbrHidden);
	neu.WeightHO = malloc(sizeof(double)*neu.nbrHidden);
	neu.BiasH = malloc(sizeof(double)*neu.nbrHidden);
	neu.BiasO = Random();
	neu.OutputH = malloc(sizeof(double)*neu.nbrHidden);
	neu.OutputO = 0;
	neu.dWeightIH = malloc(sizeof(double)*neu.nbrInput*neu.nbrHidden);
	neu.dWeightHO = malloc(sizeof(double)*neu.nbrHidden);
	neu.dOutputO = 0.0;
	neu.dHidden = malloc(sizeof(double)*net.nbrHidden);
	neu.ErrorRate = 0.0;
	neu.eta = 0.5;
	neu.alpha = 0.9;
	return neu;
}

void InitializeValues(RRN *reu)//neu 
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

	for(int i = 0; i < (*neu).nbrInput ; i++)
	{
		for(int j = 0; j < (*neu).nbrHidden ; j++)
		{
			*((*neu).WeightIH[h + i * (*neu).nbrHidden]) = Random();
			*((*neu).dWeightIH[h + i * (*neu).nbrHidden]) = 0.0;
		}
	}

	for(int n = 0; n < (*neu).nbrHidden; n++)
	{
		*((*neu).WeightHO[n]) = Random();
		*((*neu).dWeightHO[n]) = 0.0;
		*((*neu).BiasH[n]) = Random();
		*((*neu).dBiasH[n]) = 0.0;
	}
	(*neu).dBiasO = 0.0;
}

void ForwardPass()
{}
}*/
