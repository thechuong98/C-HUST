#ifndef __CSTACK_H
#define __CSTACK_H

// from previous post on linked-list implementation
// in C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CSlist.h"
 
typedef struct {
  list list;
} stack;
 
void stack_new(stack *s, int elementSize);
void stack_destroy(stack *s);
void stack_push(stack *s, void *element);
void* stack_pop(stack *s);
void* stack_peek(stack *s);
int stack_size(stack *s);
int stack_is_empty(stack *s);

#endif
