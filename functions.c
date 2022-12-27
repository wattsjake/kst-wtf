#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(struct array x)
{
    for(int i = 0; i <x.len; i++)
    {
        printf("%f  \n", x.data[i]);
    }
}

void fill_array(array *x, double value)
{
    for(int i = 0; i < x->len; i++)
    {
        x->data[i] = value;
    }
}

void zeros_array(array *X)
{
    for(int i = 0; i < X->len; i++)
    {
        X->data[i] = 0;
    }
}

void add_array(array *X, array *Y)
{
    for(int i = 0; i < X->len; i++)
    {
        X->data[i] = X->data[i] + Y->data[i];
    }
}

void linspace(double start, double end, int n, array *X)
{
    double step = (end - start) / (double)(n - 1);

    for (int i = 0; i < n; i++)
    {
        X->data[i] = start + ((double)i * step);
    }
}

void sine(array *t, array *y)
{
    for(int i = 0; i < t->len; i++)
    {
        y->data[i] = sin(t->data[i]);
    }
}

void random_array(array *X, double low, double high)
{
    for(int i = 0; i < X->len; i++)
    {
        X->data[i] =  (double)rand() * (high - low)/ (double)RAND_MAX + low;
    }
}


