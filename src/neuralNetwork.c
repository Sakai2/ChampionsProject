#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NeuralNetwork.h"

/*
double Sigmoide(double x)
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
	neu.Hidden = 3;
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

void InitializeValues(RRN *neu)
{
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

void ForwardPass(RRN *neu, int n, int rank)
{
	for (int j = 0; j < (*neu).nbrHidden; j++)
	{
		double SumIH = 0.0;
		for (int i = 0; i < (*neu).nbrInput; i++)
		{
			SumIH += *((*neu).WeightIH[j + i * (*neu).nbrHidden]) * ((*neu).InputValues[i + n * (*neu).nbrInput]);
		}
		*((*neu).OutputH[j]) = sigmoid(SumIH + *((*neu).BiasH[j]);
	}
	double SumHO = 0;
	for (int j = 0; j < (*neu).nbrHidden; j++)
	{
		SumHO += *((*neu).WeightHO[j]) * *((*neu).OutputH[j]);
	}
	(*neu).OutputO = sigmoid(SumHO + (*neu).BiasO);

	(*neu).ErrorRate += 0.5 * (*((*neu).Goal[n]) - (*neu).OutputO) * (*((*neu).Goal[n]) - (*neu).OutputO); // A comprendre les valeurs (0,5)

	/*if (rank % je sais pas cb == 0)
		printf ("Pattern n°: %d -- %f XOR %f => %f\n", p, *((*neu).InputValues[n*2], *((*neu).InputValues[n*2+1], (*neu).OutputO);
}
	
void BackwardPass(RRN *neu, int n)
{

}

void XOR()
{
	int nbrPat = 4;
	int nbrRank = 1000;
	RRN neural_network = Initialize();
	RRN *neu = &neural_network;
	InitializeValues(neu);
	for (int rank = 0; rank < nbrRank; rank++)
	{
		(*neu).ErrorRate = 0.0;
		for (int n = 0; n < nbrPat; n++)
		{
			ForwardPass(neu, n, rank);
			BackwardPass(neu, n);
		}
		/*if (epoch % 100 == 0)
		{
			printf("Epoch %-5d => ErrorRate = %f\n", epoch, (*net).ErrorRate);  Je sais pas
		}
	}
}*/

