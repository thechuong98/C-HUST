#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Cstack.h"
#include "typedef.h"

void stack_new(stack *s, int elementSize){
  s->list = malloc(sizeof(list));
  if(s->list == NULL){
    printf("Memory overflow!\n");
    return;
  }
  list_new(s->list, elementSize);
}

void stack_destroy(stack *s){
  list_destroy(s->list);
  free(s->list);
}

void stack_push(stack *s, void *element){
  list_prepend(s->list, element);
}

void stack_pop(stack *s, void *element){
  if(stack_size(s) == 0){
    printf("Stack underflow\n");
    return;
    
  }
  listNode *node = s->list->head;
  memcpy(element, node->data, s->list->elementSize);
  s->list->head = node->next;
  s->list->length--;
  free(node->data);
  free(node);
}

void stack_peek(stack *s, void *element){
  if(stack_size(s) == 0){
    printf("Stack underflow\n");
    return;
    
  }
  listNode *node = s->list->head;
  memcpy(element, node->data, s->list->elementSize);
}

int stack_size(stack *s){
  return list_size(s->list);
}
