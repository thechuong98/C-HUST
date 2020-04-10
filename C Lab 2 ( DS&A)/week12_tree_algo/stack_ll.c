#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char T;

typedef struct node{
  T val;
  struct node *next;
} node;

typedef struct stack{
  node *root;
} stack;

node *newNode(T val){
  node *new = (node*)malloc(sizeof(node));
  new->val = val;
  new->next = NULL;
  return new;
}

void initStack(stack *S){
  S->root = NULL;
}

int isEmpty(node *root){
  return (root == NULL);
}

void displayNode(node *p){
  if(p == NULL) printf("NULL\n");
  printf("%d", p->val);
}

void push(node **root, T val){
  node *node = newNode(val);
  if(node == NULL){
  	printf("Stack overflow!\n");
  	return;
  }
  if(*root == NULL) *root = node;
  else{
    node->next = *root;
    *root = node;
  }
}

T pop(node **root){
  node *prev;
  if(*root == NULL){
  	printf("Stack underflow!\n");
  	return 0;
  }
  else{
    prev = *root;
    *root = (*root)->next;
    }
  int val = prev->val;
  free(prev);
  return val;
}

T peek(node *root){
	return root->val;
}

void traversingList(node *root){
  node *p;
  for( p = root; p != NULL; p = p->next)
    displayNode(p);
}

int main(){
}
