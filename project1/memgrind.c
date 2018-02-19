//contains the main testing of malloc and free functions
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "mymalloc.h"


int main()
{
  int  A[100], B[100], C[100] ,D[100];
  int suma = 0, sumb = 0, sumc = 0, sumd = 0;
  int *x, i, n;
  n = 0
  struct timeval start, end;
  
  //Workload A
  gettimeofday(&start, NULL);
  for(i=0; i < 150; i++){
    x = malloc(sizeof(int));
    free(x);
  }
  gettimeofday(&end, NULL);
  A[n] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
  
  //Workload B
  
}
