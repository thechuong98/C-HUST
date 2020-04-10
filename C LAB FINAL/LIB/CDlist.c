#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CDlist.h"

void list_new(list *list, int elementSize){
  list->elementSize = elementSize;
  list->head = list->tail = NULL;
  list->length = 0;
}

void list_destroy(list *list)
{
  listNode *current;
  while(list->head != NULL) {
    current = list->head;
    list->head = current->next;
    free(current->data);
    free(current);
  }
}

void list_prepend(list *list, void *element){
  listNode *node = malloc(sizeof(listNode)); // mem allocate for newNode
  node->data = malloc(list->elementSize); // size def for data field;
  memcpy(node->data, element, list->elementSize);

  node->next = list->head;
  node->prev = NULL;
  list->head->prev = node;
  list->head = node;
  //first node
  if(!list->tail){
    list->tail = list->head;
  }
  list->length++;
}


void list_append(list *list, void *element){
  listNode *node = malloc(sizeof(listNode));
  node->data = malloc(list->elementSize);
  memcpy(node->data, element, list->elementSize);

  if(list->length == 0){
    list->head = list->tail = node;
  }
  else{
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
  }

  list->length++;
}

int list_size(list *list){
  return list->length;
}

void list_insert(list *list, void *element, int position){
  if(position == 1){
    list_prepend(list, element);
    return;
  }
  else if(position > list->length || position <= 0){
    list_append(list, element);
    return;
  }
  listNode *node = malloc(sizeof(listNode));
  node->data = malloc(list->elementSize);
  memcpy(node->data, element, list->elementSize);

  listNode *cur = list->head;
  listNode *prev = NULL;
  for(int i = 0; i < position - 1; ++i){
    prev = cur;
    cur = cur->next;
  }
  prev->next = node;
  node->prev = prev;
  node->next = cur;
  cur->prev = node;

  list->length++;
}

void list_delete_pos(list *list, int position){
  int i = 0;
  if(list->head == NULL){
    printf("List empty\n");
    return;
  }
  listNode *cur = list->head;
  listNode *prev = NULL;
  if(position == 1){
    cur = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(cur);
    return;
  }
  else{
    while(cur != NULL && i < position - 1){
      i++;
      prev = cur;
      cur = cur->next;
    }
    if(cur ==  NULL){
      printf("position does not exist\n");
      printf("delete from 1 to %d\n", list_size(list));
      return;
    }
    prev->next = cur->next;
    cur->next->prev = prev;
    free(cur);
  }
  list->length--;
}

void list_delete_data(list *list, void *data){
  if(list->length == 0){
    printf("List empty\n");
    return;
  }
  listNode *cur = list->head;
  listNode *prev = NULL;
  int found = False;
  while(!found){
    if(cur != NULL && is_Same(cur->data, data)){
      found = True;
    }
    else if(cur == NULL){
      printf("data not found\n");
      return;
    }
    else{
      prev = cur;
      cur = cur->next;
    }
  }
  if(prev == NULL){
    list->head = cur->next;
    list->head->prev = NULL;
  }
  else{
    prev->next = cur->next;
    cur->next->prev = prev;
    free(cur);
  }
  list->length--;
}

void list_for_each(list *list, listIterator iterator){
  if(iterator != NULL){
    listNode *node = list->head;
    while(node != NULL){
      iterator(node->data); //if print successfully iterator return True;
      node = node->next;
    }
  }
}



void iterator_name(void *data){
  phoneAddress *a = (phoneAddress *)data;
  printf("Found string value: %s\n", a->name);
}

bool is_Same(void *data1, void *data2){
  if(memcmp(data1, data2, sizeof(phoneAddress)) == 0) return True;
  else return False;
}

void list_reverse(list *list){
  listNode *cur, *prev;
  cur = prev = NULL;
  list->tail = list->head;
  while(list->head != NULL){
    cur = list->head;
    list->head = list->head->next;
    cur->next = prev;
    prev = cur;
  }
  list->head = prev;
}

// /* int main(){ */
// /*   list list; */
// /*   list_new(&list, sizeof(phoneAddress)); */
// /*   phoneAddress a; */
// /*   strcpy(a.name, "Chu The Chuong"); */
// /*   strcpy(a.tele, "0981082834"); */
// /*   phoneAddress b; */
// /*   strcpy(b.name, "Nguyen Duc Dung"); */
// /*   strcpy(b.tele, "0134121234"); */
// /*   phoneAddress c; */
//    strcpy(c.name, "Vu Thanh Tung"); 
// /*   strcpy(c.tele, "0021491243"); */
// /*   list_append(&list, &a); */
// /*   list_insert(&list, &b, 2); */
// /*   list_insert(&list, &c, 2); */
//    list_delete_pos(&list, 3); 
//   /* list_for_each(&list, iterator_name) */;
//   /* list_reverse(&list); */
//   /* list_for_each(&list, iterator_name); */
//   /* iterator_name(list.tail->data); */
// /* } */
