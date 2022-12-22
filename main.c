#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage:\n");
        printf("    %s <output file> <points>", argv[0]);

        return 0;
    }

    char *output_filename = argv[1];
    int points = atoi(argv[2]);

    printf("Points: %i\n", points);
    //print output file name
    printf("Output file: %s\n", output_filename);

    //create output file data
    struct array t;
    t.len = points;
    t.data = malloc(t.len * sizeof(double));
    zeros_array(&t);

    struct array y;
    y.len = points;
    y.data = malloc(y.len * sizeof(double));
    zeros_array(&y);

    linspace(0, 10*M_PI, points, &t);
    // print_array(t);

    sine(&t, &y);
    // print_array(y);

    for(int i = 0; i<t.len; i++)
    {
        FILE * fp = fopen(argv[1], "a");
        fprintf(fp, "%f, %f\n", t.data[i], y.data[i]);
        fclose(fp);
    }

    //free memory
    free(t.data);
    free(y.data);

    return 0;
}