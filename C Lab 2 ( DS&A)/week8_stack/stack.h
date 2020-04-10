#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

typedef enum stack_type {
    STACK_CHAR,
    STACK_INT,
    STACK_STRING,
    STACK_FLOAT,
    STACK_DOUBLE,
    STACK_POINTER
} stack_type;

#define typename(x) _Generic((x), \
    int:     "int", \
    float:   "float", \
    char:	 "char", \
    char*:	 "string",\
    double:  "double",\
    default: "other")

typedef void* T;

typedef struct stackNode stackNode;
void stack_init(stackNode **stack, stack_type type);
void push(stackNode **top, ...);
void *pop(stackNode **top, void *p);
void *peek(stackNode **top, void *p);
int isEmpty(stackNode **top);
void freeStack(stackNode **top);


#endif // STACK_H
	