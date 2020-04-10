#ifndef __CQUEUE_H
#define __CQUEUE_H

// from previous post on linked-list implementation
// in C
#include "CSlist.h"

typedef struct {
  list *list;
} queue;
 
void queue_new(queue *Q, int elementSize);
int isEmptyQueue(queue *Q);
void enQueue(queue *Q, void *data);
void deQueue(queue *Q, void *store);
void queue_delete(queue *Q);
void queue_reverse(queue *Q);

#endif
