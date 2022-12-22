#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct array
{
    int len;
    double *data;
}array;


void print_array(struct array x);

void fill_array(array *x, double value);

void zeros_array(array *X);

void add_array(array *X, array *Y);

void linspace(double start, double end, int n, array *X);

void sine(array *t, array *y);

#endif
