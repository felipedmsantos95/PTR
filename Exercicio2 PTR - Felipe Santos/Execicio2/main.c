#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema.h"
#include "simulacao.h"


int main(int argc, char *argv[])
{
    double *u = (double *) calloc (2, sizeof (double)); //Entrada
    double *y = (double *) calloc (3, sizeof (double)); //Saida
    int t = 20;
    
    simulacao(t, u, y);

    return 0;
}
