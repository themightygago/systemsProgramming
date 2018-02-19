//contains the main testing of malloc and free functions
#include "mymalloc.h"
int main()
{
  int *x = malloc(50*sizeof(int));
  free(x);
  free(x);
  
}
