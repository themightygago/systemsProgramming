//contains function implementaions of mymalloc and myfree
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mymalloc.h"


static char myblock[5000];
Node *freeList = (void*)myblock;

void firstCall()
{
  freeList->size=5000-sizeof(Node);
  freeList->isFree = 1; // is free 1 = it IS free
  freeList->next=NULL;
}

//Used to fit memory needed to a slot that is too big, splits the extra memory
//into a new node that points to another node with excess memory.
void firstFit(Node *slot,size_t sizeNeeded)
{
  Node *newNode=(void*)((void*)slot+sizeNeeded+sizeof(Node));
  newNode->size=(slot->size)-sizeNeeded-sizeof(Node);
  newNode->isFree=1;
  newNode->next=slot->next;
  slot->size=sizeNeeded;
  slot->isFree=0;
  slot->next=newNode;
}

//function to run everytime free is called, checks for contiguous free blocks and combines them
void merge()
{
  Node *current;
  current = freeList;

  //runs through the entire list of free blocks starting at the beginning
  while((current->next)!=NULL)
  {
    if((current->isFree)&&(current->next->isFree))//checks to see if to contiguous blocks are free
    {
      current->size = (current->size)+(current->next->size)+(sizeof(Node));//merges the size of two contiguous free blocks
      current->next = current->next->next;//reassigns pointer to be the next node in the list
    }
    current=current->next;//move one node down the list of free nodes
  }
}

void *mymalloc(size_t sizeRequested, char* file, int line)
{
  Node *current;
  void *returnPointer;
  char* fileName = file;
  int lineNum = line;

  if(!(freeList->size))//Checks to see if the size of the freeList of bytes is 0. If it's 0 then this means it is the first malloc call and the list needs to be intialized.
  {
    printf("First call to malloc, memory will be intialized\n");
    firstCall();
  }
  //Assigns current node to point to the beginning of the list of blocks.
  current=freeList;
  //Checks the list of free nodes until it finds one that satisfies the size requested by the user
  while(((current->isFree)==0)&&((current->next!=NULL)||(current->size)<sizeRequested))
  {
    current=current->next;
  }

  //This checks to see if the size required is the exact size of the block available, if so it will return the pointer to that address of memory.
  if((current->size)==sizeRequested)
  {
    current->isFree=0;
    returnPointer=(void*)(current++);
    printf("malloc worked\n");
    return returnPointer;
  }
    else
    if((current->size)>(sizeRequested+sizeof(Node)))
    {
      firstFit(current,sizeRequested);
      returnPointer = (void*)(current++);
      printf("malloc worked had to split memory\n");
      return returnPointer;
    }
      else
      {
        returnPointer = NULL;
        printf("Error. Not enough memory. Malloc call on line %i in file %s \n", lineNum, fileName);
        return returnPointer;
      }
}

void myfree(void* pointer, char* file, int num)
{
  char* fileName = file;
  int lineNum = num;
  Node * current;
  current = pointer;//set the pointer to a node it's variables are accessible (isFree,size,and next)
  current--;

  if(pointer<=((void*)(myblock+5000))&&((pointer>=(void*)myblock)))//checks to make sure the pointer is within bounds of the memory
  {
    if(current->isFree == 0)
    {
      current->isFree = 1;
      printf("free worked!\n");
      merge();
    }
    else
    {
      printf("Error on line: %i in file: %s. This memory is already free. \n", lineNum, fileName);
    }
  }
  else
  {
    printf("Error on line: %i in file: %s. Pointer entered is not a valid pointer set by malloc.\n", lineNum, fileName);
  }

}
