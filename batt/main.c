#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PATH_BATT_STATE "/sys/class/power_supply/BAT0/voltage_now"
#define SIZE 40

int main(int argc, char *argv[]) 
{
    if(argc < 3)
    {
        printf("Usage:\n");
        printf("    %s <filename> <utime>", argv[0]);

        return 0;
    }

    int time = atoi(argv[2]);
    char *output_filename = argv[1];
    char file_location[SIZE] = "output_file/";

    int battStateHandle;
    short int readlen=0;
    char buf[25];
    size_t nbytes;
    ssize_t bytes_read;
    nbytes = sizeof(buf);


    //concatenate file location and output file name
    strcat(file_location, output_filename);

    printf("Time: %i\n", time);
    printf("Output file: %s \n", file_location);

    //Battery voltage test for program
    if (-1 == (battStateHandle = open(PATH_BATT_STATE,O_RDONLY))) 
    {
        perror("Could not open battery info for reading\n");
        exit(-1);
    }
    else 
    {
        printf("Battery info opened for reading...\n");

        while (1)
        {
            battStateHandle = open(PATH_BATT_STATE,O_RDONLY);
            read(battStateHandle, buf, nbytes);
            //remove the trailing zeros from the string buff
            //printf("Battery voltage: %s", buf);

            FILE * fp = fopen(file_location, "a+");
            fprintf(fp, "%s", buf);
            fclose(fp);

            close(battStateHandle);
            usleep(time);
        }
        // read(battStateHandle, buf, nbytes);
        // printf("Battery voltage: %s", buf);
    }

   return 0;
}