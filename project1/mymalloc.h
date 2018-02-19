#ifndef MYMALLOC_H
#define MYMALLOC_H

#define malloc(x) mymalloc(x, __FILE__,__LINE__)
#define free(x) myfree(x, __FILE__,__LINE__)
#include <stdio.h>

typedef struct node
{
  size_t size;//size of the node
  int isFree;
  struct node *next;
}Node;

void *mymalloc(size_t, char *,int);
void myfree(void* pointer, char *,int);
void merge();
void firstCall(); // first call to malloc will initialize the memory.
void firstFit(Node *sizeAvailable,size_t sizeNeeded);


#endif
