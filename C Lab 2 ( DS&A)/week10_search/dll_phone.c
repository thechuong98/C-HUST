#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct phone{
  char model[20];
  char rom[10];
  float display;
  char price[10];
} phone;

typedef phone T;

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
    printf("%-20s%-10s%-10lf%-10s\n", cur->data.model, cur->data.rom, cur->data.display, cur->data.price);
    cur = cur->next;
  }
}


//READ DATA TO DAT FILE

void txt2bin(char *fnIn, char *fnOut, phone phones[], int n){
  FILE *fi = fopen(fnIn, "r");
  FILE *fo = fopen(fnOut, "w+b");

  if(fi == NULL){
    printf("cannot open the file.\n");
    return;
  }
  for(int i = 0; i < n; ++i){
    fscanf(fi, "%s", phones[i].model);
    fscanf(fi, "%s", phones[i].rom);
    fscanf(fi, "%f", &phones[i].display);
    fscanf(fi, "%s", phones[i].price);
  }
  fwrite(phones, sizeof(phone), n, fo);
  fclose(fi);
  fclose(fo);
}

int lineCounter(char *fn){
  FILE *f = fopen(fn, "r");
  if ( f == NULL){
    printf("Cannot open the file\n");
    return 0;
  }
  int numOfLines = 1;
  char c;
  while ((c = fgetc(f)) != EOF){
    if (c == '\n') numOfLines++;
  }
  fclose(f);
  return(numOfLines);
}

void readDatatoList(char *fn, node **root){
  FILE *f = fopen(fn, "rb");
  if(f == NULL){
    printf("cannot open the file.\n");
    return;
  }
  else{
    node *cur = (node *)malloc(sizeof(node));
    node *prev = (node *)malloc(sizeof(node));
    while(!feof(f)){
      node *p = (node *)malloc(sizeof(node)); //tao 1 node p
      if((*root) == NULL){
        *root = p;
        cur = *root;
      }
      fread(&p->data, sizeof(phone), 1, f); // doc du lieu vao p->data
      cur->next = p;
      p->prev = cur;
      prev = cur;
      cur = p;
    }
    fclose(f);
  }
} 

