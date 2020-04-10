#include "Cstack.h"
#include "typedef.h"

void stack_new(stack *s, int elementSize){
  list_new(&(s->list), elementSize);
}

void stack_destroy(stack *s){
  list_destroy(&s->list);
  free(&s->list);
}

void stack_push(stack *s, void *element){
  list_prepend(&s->list, element);
}

void* stack_pop(stack *s){
  if(stack_size(s) == 0){
    printf("Stack underflow\n");
    return NULL;
    
  }
  void *element = malloc(sizeof(s->list.elementSize));
  listNode *node = s->list.head;
  s->list.head = s->list.head->next;
  s->list.length -= 1;
  element = node->data;
  return element;
}

void* stack_peek(stack *s){
  void *element;
  if(stack_size(s) == 0){
    printf("Stack underflow\n");
    return NULL;
    
  }
  listNode *node = s->list.head;
  memcpy(element, node->data, s->list.elementSize);
  return element;
}

int stack_size(stack *s){
  return list_size(&s->list);
}

int stack_is_empty(stack *s){
  return (s->list.length == 0);
}