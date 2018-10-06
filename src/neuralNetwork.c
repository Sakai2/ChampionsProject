#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Sigmoide(double x)
{
  return (1.0/(1.0 + exp(-x)));
}

