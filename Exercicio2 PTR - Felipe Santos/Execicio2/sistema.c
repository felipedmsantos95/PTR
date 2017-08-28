#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Calcular a orientacao do robô
//v é a velocidade linear e w é a velocidade angular

double x3(double v, double w)
{    
    return ((v * 0) +  (w * 1));
}


//Funcao que determina valores de entrada a partir do tempo
double *ut(int k)
{
    double * u = (double *) calloc (2, sizeof (double));

    if(k < 0)
    {
        u[0] = 0;//v
        u[1] = 0;//w
    }
    else if (k >= 0 && k < 10)
    {
        u[0] = 1;//v
        u[1] = M_PI * 0.2;//w
    }
    else
    {
        u[0] = 1;//v
        u[1] = -(M_PI * 0.2);//w
    }

    return u;
}


//Função para calcular o vetor x(t) do problema
double *xt(double v, double w)
{
    double * x = (double *) calloc (3, sizeof (double));
    
    //Linhas do vetor resultante
    double theta = x3(v, w);

    double xc = ((v * sin(theta)) +  (w * 0));

    double yc = ((v * cos(theta)) +  (w * 0));

    //retornando o vetor calculado

    x[0] = xc;
    x[1] = yc;
    x[2] = theta;
    
    return x;    
}

//Funcao para o calculo da saída y(t)

double *yt(double v, double w)
{   
     double * x = (double *) calloc (3, sizeof (double));
     x = xt(v, w);
     double * y = (double *) calloc (3, sizeof (double));
    
    //Multiplicacao das matrizes envolvidas
    y[0] = (1 * x[0]) + (0 * x[1]) + (0 * x[2]);
    y[1] = (0 * x[0]) + (1 * x[1]) + (0 * x[2]);
    y[2] = (0 * x[0]) + (0 * x[1]) + (1 * x[2]);    
    
    return y;
}


