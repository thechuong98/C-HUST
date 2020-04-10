#ifndef _TYPE_H_
#define _TYPE_H_
typedef enum {False, True} bool;
//List
typedef void (*freeFunction)(void *); //free memory of block;
typedef void (*listIterator)(void *); //return value of function listIterator(void *) is a boolean listIterator
//Tree
typedef void (*treeIterator)(void *);
typedef int (*comparator)(void *, void *);
//test struct
typedef struct phoneAdress{
  char name[30];
  char tele[20];
} phoneAddress;

#endif