#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{

   if(argc < 2)
   {
      printf("Usage:\n");
      printf("    %s <utime>", argv[0]);

      return 0;
   }

   int time = atoi(argv[1]);
   printf("Time: %i\n", time);

   //Memory usage test for program

   struct rusage r_usage;
   int *p = 0;
   while(1) {
      p = (int*)malloc(sizeof(int)*1000);
      int ret = getrusage(RUSAGE_SELF,&r_usage);
      if(ret == 0)
         printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
      else
         printf("Error in getrusage. errno = %d\n", errno);
      usleep(time);
   }

   return 0;
}