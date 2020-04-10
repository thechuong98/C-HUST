#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phoneBook{
	char name[80];
	long number;
} phoneBook;

typedef struct{
	Entry *entries;
	int size, total;
	Entry (*makeNode)(void *, void *);
	int (*compare)(void *, void *);
}