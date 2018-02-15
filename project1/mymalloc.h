#ifndef MYMALLOC_H
#DEFINE MYMALLOC_H

#define malloc(x) mymalloc(x, __FILE__,__LINE__)
#define free(x) myfree(x, __FILE__,__LINE__)

struct node
{
  size_t size;//size of the node
  int free;
  struct node *next;
}

void *mymalloc(size_t, char *,int);
void myfree(size_t, char *,int);


#endif
