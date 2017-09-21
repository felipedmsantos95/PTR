#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//Função para cálculo de x bola

double *dxt(double *x, double *u)
{   
    double * result = (double *) calloc (3, sizeof (double));
    double v = u[0];
    double w = u[1];

    result[0] = x[1];
    result[1] = -(x[0]);
    result[2] = u[1];

    return result;    
    
}

