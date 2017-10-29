#ifndef SISTEMA_H
#define SISTEMA_H

#include<math.h>

double x3(double v, double w);

double *ut(int k);

double *dxt(double *x, double *u);

double *xt(double *u, int t);

double *Yt(double *x);

double *yt(double *u, int t);

#endif

