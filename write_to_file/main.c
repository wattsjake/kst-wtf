#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 40

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage:\n");
        printf("    %s <output file> <points>", argv[0]);

        return 0;
    }

    char *output_filename = argv[1];

    char file_location[SIZE] = "output_file/";

    int points = atoi(argv[2]);

    //concatenate file location and output file name
    strcat(file_location, output_filename);

    printf("Output file: %s\n", output_filename);

    printf("file_location: %s\n", file_location);

    printf("Points: %i\n", points);

    //create output file data
    struct array t;
    t.len = points;
    t.data = malloc(t.len * sizeof(double));
    zeros_array(&t);

    struct array y;
    y.len = points;
    y.data = malloc(y.len * sizeof(double));
    zeros_array(&y);

    struct array temp;
    temp.len = points;
    temp.data = malloc(temp.len * sizeof(double));
    zeros_array(&temp);

    linspace(0, 10*M_PI, points, &t);
    // print_array(t);

    sine(&t, &y);
    // print_array(y);

    //random_array(&temp, 0, 0.1);
    // print_array(temp);

    add_array(&y, &temp);
    // print_array(y);

    for(int i = 0; i<t.len; i++)
    {
        FILE * fp = fopen(file_location, "a+");
        fprintf(fp, "%f, %f\n", t.data[i], y.data[i]);
        fclose(fp);
    }

    //free memory
    free(t.data);
    free(y.data);
    free(temp.data);


    return 0;
}