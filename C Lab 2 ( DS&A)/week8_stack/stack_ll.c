#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int T;

typedef struct node{
  T val;
  struct node *next;
} node;
// 3 global pointer
node *root, *cur, *prev;
int length = 0;

node *newNode(T val){
  node *new = (node*)malloc(sizeof(node));
  new->val = val;
  new->next = NULL;
  return new;
}

int isEmpty(){
	return length == 0;
}

void displayNode(node *p){
  if(p == NULL) printf("NULL\n");
  printf("%d", p->val);
}

void push(T val){
  node *node = newNode(val);
  if(node == NULL){
  	printf("Stack overflow!\n");
  	return;
  }
  if(root == NULL) root = node;
  else{
    node->next = root;
    root = node;
  }
  length += 1;
}

T pop(){
  if(length == 0){
  	printf("Stack underflow!\n");
  	return 0;
  }
  else{
    prev = root;
    root = root->next;
    }
  int val = prev->val;
  free(prev);
  length -= 1;
  return val;
}

T peek(){
	return root->val;
}

void traversingList(){
  node *p;
  for( p = root; p != NULL; p = p->next)
    displayNode(p);
}

int main(){
}
