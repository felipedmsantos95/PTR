#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//Funcao que calcula o y em funcao de x
double *Yt(double *x)
{
   
    double * y = (double *) calloc (3, sizeof (double));    
    //Multiplicacao das matrizes envolvidas
    y[0] = (1 * x[0]) + (0 * x[1]) + (0 * x[2]);
    y[1] = (0 * x[0]) + (1 * x[1]) + (0 * x[2]);
    y[2] = (0 * x[0]) + (0 * x[1]) + (1 * x[2]);    
    

    return y;
}

