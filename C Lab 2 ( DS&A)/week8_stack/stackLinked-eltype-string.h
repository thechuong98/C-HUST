#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX 50

typedef char eltype;

struct node{
  eltype data[MAX];
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
  strcpy(new->data, addr);
  new->next = NULL;
  return new;
}

int is_empty(stack *list){
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

eltype *pop(stack *list){
  static eltype value[MAX]; 
  if(is_empty(list)){
    printf("stack empty.\n");
    exit(0);
  }
  node* tmp = list->root;
  list->root = tmp->next;
  strcpy(value, tmp->data);
  free(tmp);
  return value;
}

void top(stack *list){
  if(is_empty(list)){
    printf("stack empty.\n");
    return;
  }
  printf("Top : %s\n", list->root->data);
  return;
}
