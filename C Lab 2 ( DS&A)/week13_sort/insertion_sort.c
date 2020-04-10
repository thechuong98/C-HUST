#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CSlist.h"

void data_generate(char *fn){
  FILE *fin = fopen(fn, "w+");
  srand(time(NULL));
  for(int i = 0; i < 10000; ++i){
    int rand_num = rand()%1000;
    fprintf(fin, "%d ", rand_num);
  }
  fclose(fin);
}

void data_to_slist(char *fn, list *list){
  FILE *fin = fopen(fn, "r");
  int num;
  while(fscanf(fin, "%d", &num) == 1){
    list_append(list, &num);
  }
  fclose(fin);
}

void insertion_sort_array(int arr[], int n){
  int key;
  for(int i = 0; i < n; ++i){
    key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}

void sort_Insert(listNode **root, listNode *new){
  listNode *cur;
  if(*root == NULL || *(int *)((*root)->data) > *(int *)(new->data)){
    new->next = *root;
    *root = new;
  }
  else{
    cur = *root;
    while(cur->next != NULL && *(int *)(cur->next->data) < *(int *)(new->data)){
      cur = cur->next;
    }
    new->next = cur->next;
    cur->next = new;
  }
}

void insertion_sort_slist(list *list){
  listNode *newList = NULL;
  listNode *current = list->head;
  while(current != NULL){
    listNode *next = current->next;
    sort_Insert(&newList, current);
    current = next;
  }
  list->head = newList;
}

void listNode_swap_int(listNode *a, listNode *b){
  int *aint = (int *)(a->data);
  int *bint = (int *)(b->data);
  int temp;
  temp = *aint;
  *aint = *bint;
  *bint = temp;
}

void iterator_int(void *data){
  int *a = (int *)data;
  printf("Found int value: %d\n",*a);
}


int main(){
  list list_a;
  list_new(&list_a, sizeof(int));
  int arr[9] = {3,2,1,8,6,9,7,5,4};
  for(int i = 0; i < 9; ++i){
    list_append(&list_a, &arr[i]);
  }
  insertion_sort_slist(&list_a);
  list_for_each(&list_a, iterator_int);
  data_generate("num.txt");
  list list_num;
  list_new(&list_num, sizeof(int));
  data_to_slist("num.txt", &list_num);
  insertion_sort_slist(&list_num);
  list_for_each(&list_num, iterator_int);
}
