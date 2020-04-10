#ifndef __CQUEUE_H
#define __CQUEUE_H

// from previous post on linked-list implementation
// in C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CSlist.h"

typedef struct {
  list list;
} queue;
 
void queue_new(queue *Q, int elementSize);
int isEmptyQueue(queue *Q);
void enQueue(queue *Q, void *data);
void* deQueue(queue *Q);
void queue_delete(queue *Q);
void queue_reverse(queue *Q);
int queue_size(queue *Q);

#endif
