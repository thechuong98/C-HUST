#include <stdio.h>
#include <stdlib.h>

typedef char* eltype;

struct node{
  eltype  data;
  struct node* next;
};
typedef struct node node;

typedef struct{
  node *root;
  node *cur;
}stack;

void init_stack(stack *list){
  list->root = NULL;
  list->cur = NULL;
  return;
}

node* makeNewNode(eltype *addr){
  node* new = (node*)malloc(sizeof(node));
  new->data = *addr;
  new->next = NULL;
  return new;
}

int isEmpty(stack *list){
  return (list->root==NULL);
}

void push(eltype *addr, stack *list){
  node *new = makeNewNode(addr);
  if(list->root==NULL){
    list->root = new;
    list->cur = list->root;
    return;
  }else{
    new->next = list->root;
    list->root = new;
    list->cur = list->root;
  }
}

eltype pop(stack *list){
  eltype value; 
  if(isEmpty(list)){
    printf("stack empty.\n");
    exit(0);
  }
  node* tmp = list->root;
  list->root = tmp->next;
  value = tmp->data;
  free(tmp);
  return value;
}

eltype top(stack *list){
  if(isEmpty(list)){
    printf("stack empty.\n");
    exit(1);
  }
  printf("value of top is: %s \n", list->root->data);
  return list->root->data;
}
