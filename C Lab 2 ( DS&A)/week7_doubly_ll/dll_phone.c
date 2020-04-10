#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct phone{
  char model[20];
  char rom[10];
  float display;
  char price[10];
} phone;

typedef struct node{
  phone phone;
  struct node *next;
  struct node *prev;
} node;

node *newNode(phone phone){
  node *new = (node *)malloc(sizeof(node));
  new->phone = phone;
  new->next = NULL;
  new->prev = NULL;
  return new;
}




