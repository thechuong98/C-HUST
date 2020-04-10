#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "doubly_linked_list.c"

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
