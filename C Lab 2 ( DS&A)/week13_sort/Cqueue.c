#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Cqueue.h"
#include "typedef.h"


void queue_new(queue *Q, int elementSize){
  Q->list = (list *)malloc(sizeof(list));
  if(Q->list == NULL){
    printf("Memory Overflow!\n");
    return;
  }
  list_new(Q->list, elementSize);
}

int isEmptyQueue(queue *Q){
  return (Q->list->length == 0);
}

void enQueue(queue *Q, void *data){
  list_prepend(Q->list, data);
}

void deQueue(queue *Q, void *store){
  listNode *node = Q->list->tail;
  memcpy(store, node->data, Q->list->elementSize);
  list_delete_pos(Q->list, list_size(Q->list));
  Q->list->length--;
}

// int main(){
//   queue Q;
//   queue_new(&Q, sizeof(phoneAddress));
//   phoneAddress a;
//   strcpy(a.name, "Chu The Chuong");
//   strcpy(a.tele, "0981082834");
//   phoneAddress b;
//   strcpy(b.name, "Nguyen Duc Dung");
//   strcpy(b.tele, "0134121234");
//   phoneAddress c;
//   strcpy(c.name, "Vu Thanh Tung");
//   strcpy(c.tele, "0021491243");
//   enQueue(&Q, &a);
//   enQueue(&Q, &b);
//   enQueue(&Q, &c);
//   void *store = malloc(sizeof(phoneAddress));
//   deQueue(&Q, store);
//   enQueue(&Q, &a);
//   list_for_each(Q.list, iterator_name);
// }
