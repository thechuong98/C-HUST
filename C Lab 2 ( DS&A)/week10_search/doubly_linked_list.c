#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct phone{
  char model[20];
  char rom[10];
  float display;
  char price[10];
} phone;

typedef int T;

typedef struct node{
  T data;
  struct node *next;
  struct node *prev;
} node;

node *newNode(T data){
  node *new = (node*)malloc(sizeof(node));
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

int listLength(node *root){
  node *cur = root;
  int count = 0;
  while(cur != NULL){
    count++;
    cur = cur->next;
  }
  return count;
}

void insert(node **root, T data, int position){
  int k = 1;
  node *current, *previous, *new;
  new = newNode(data);
  current = *root;
  if(position > (listLength(*root)+1) || position < 1){
    printf("Not in range.\n");
    return;
  }
  else if(position == 1){ //HEAD
    new->next = current;
    *root = new;
  }
  else{ //traverse until position
    while((current != NULL) && (k < position)){
      k++;
      previous = current;
      current = current->next;
    }
    if(current == NULL){
      current->next = new;
      new->next = NULL;
      new->prev = current;
    }
    else{
      previous->next = new;
      new->prev = previous;
      new->next = current;
      current->prev = new;
    }
  } 
}

void delete(node **root, int position){
  int k = 1;
  node *current, *previous;
  if(*root == NULL){
    printf("List empty\n");
    return;
  }
  current = *root;
  if(position == 1){
    current = *root;
    *root = (*root)->next;
    free(current);
    return;
  }
  else{
    while(current != NULL && k < position){
      k++;
      previous = current;
      current = current->next;
    }
    if(current== NULL){
      printf("Position does not exist\n");
      return;
    }
    else{
      previous->next = current->next;
      current->next->prev = previous;
      free(current);
    }
  }
}

void traversingList(node *root){
  node *cur = root;
  while(cur != NULL){
    printf("%d\n", cur->data);
    cur = cur->next;
  }
}

