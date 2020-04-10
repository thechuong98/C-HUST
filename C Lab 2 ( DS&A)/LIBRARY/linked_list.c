#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
} node;

node *newNode(T data){
  node *new = (node *)malloc(sizeof(node));
  new->data = data;
  new->next = NULL;
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
  node *cur, *prev, *new;
  new = newNode(data);
  cur = *root;
  if(position > listLength(*root) || position < 1){
    printf("Not in range.\n");
    return;
  }
  if(position == 1){
    //insert At Head
    new->next = cur;
    *root = new;
  }
  else{//traverse until position
    while((cur->next!=NULL) && (k < position)){
      k++;
      prev = cur;
      cur = cur->next; 
    }
    if(cur == NULL){ //insertAtEnd
      cur->next = new;
      new->next = NULL;
    }
    else{//insert At Mid
      prev->next = new;
      new->next = cur;
    }
  }
}

void delete(node **root, int position){
  int k = 1;
  node *cur, *prev;
  if(*root == NULL){
    printf("List Empty");
    return;
  }
  cur = *root;
  if(position == 1){
    cur = *root;
    *root = (*root)->next;
    free(cur);
    return;
  }
  else{
    while((cur != NULL) && (k < position)){
      k++;
      prev = cur;
      cur = cur->next;
    }
    if(cur == NULL){
      printf("position does not exist\n");
      return;
    }
    else{
      prev->next = cur->next;
      free(cur);
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



int main(){
  node *root = newNode(3);
  insert(&root, 4, 1);
  insert(&root, 5, 1);
  insert(&root, 6, 10);
  traversingList(root);
  delete(&root, 5);
  traversingList(root);
}
