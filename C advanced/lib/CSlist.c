#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CSlist.h"

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
  node->data = element; // size def for data field;
  node->next = list->head;
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
  node->data = element;

  if(list->length == 0){
    list->head = list->tail = node;
  }
  else{
    list->tail->next = node;
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
  node->data = element;

  listNode *cur = list->head;
  listNode *prev = NULL;
  for(int i = 0; i < position - 1; ++i){
    prev = cur;
    cur = cur->next;
  }
  prev->next = node;
  node->next = cur;

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
    free(cur);
    if(position == list_size(list)) list->tail = prev;
    list->length--;
    return;
  }
  if(position <= 0){
    printf("Delete from 1 to %d\n", list_size(list));
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
    free(cur);
    if(position == list_size(list)) list->tail = prev; //update the list_tail if delete the last node;
  }
  list->length--;
}

void list_delete_data(list *list, void *data, is_same is_Same_data){
  if(list->length == 0){
    printf("List empty\n");
    return;
  }
  listNode *cur = list->head;
  listNode *prev = NULL;
  int found = False;
  while(!found){
    if(cur != NULL && is_Same_data(cur->data, data)){
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
  if(prev == NULL)
    list->head = cur->next;
  else{
    prev->next = cur->next;
    if(cur == list->tail){
      list->tail = prev; //update list->tail
    }
    free(cur);
  }
  list->length--;
}

listNode *list_merge(listNode *a, listNode *b, comparator cmp){
  listNode *result = NULL;
  if(a == NULL) return b;
  if(b == NULL) return a;
  if(cmp(a->data, b->data) <= 0){
    result = a;
    result->next = list_merge(a->next, b, cmp);
  }
  else{
    result = b;
    result->next = list_merge(a, b->next, cmp);
  }
  return result;
}

void list_for_each(list *list, listIterator iterator){
  if(iterator != NULL){
    listNode *node = list->head;
    while(node != NULL){
      iterator(node->data);
      node = node->next;
    }
  }
}

listNode *list_search(listNode *head, void *element, comparator cmp){
  if(head == NULL) return NULL;
  if(cmp(head->data, element) == 0) return head;
  else{
    listNode *tmp = list_search(head->next, element, cmp);
    if(tmp != NULL) return tmp;
  }
}

void iterator_int(void *data){
  int *a = (int *)data;
  printf("Found string value: %d\n", *a);
}

bool is_Same_int(void *data1, void *data2){
  if(memcmp(data1, data2, sizeof(int)) == 0) return True;
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

void list_for_each_end(listNode *head, listIterator iterator){
  //dung de quy nen phai truyen listNode * chu k phai la list *
  if(head == NULL){
      return;
  }
  listNode *tail = head->next;
  list_for_each_end(tail, iterator);
  iterator(head->data);
}

void delete_duplicates(list *list){
  listNode *cur = list->head;
  while(cur != NULL && cur->next != NULL){
    if(memcmp(cur->data, cur->next->data, sizeof(int)) == 0){
      cur->next = cur->next->next;
      list->length--;
    }
    else cur = cur->next;
  }
} 

void swap(listNode *a, listNode *b)
{
    void* temp = a->data;
    a->data = b->data;
    b->data = temp;
}


void list_sort(listNode* root, comparator cmp)
{
    int swapped;
    listNode *ptr1;
    listNode *lptr = NULL;
    if (root == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = root;
        while (ptr1->next != lptr)
        {
            if (cmp(ptr1->data, ptr1->next->data) > 0)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


 // int main(){ 
 //   list list; 
 //   list_new(&list, sizeof(phoneAddress)); 
 //   phoneAddress a; 
 //   strcpy(a.name, "Chu The Chuong"); 
 //   strcpy(a.tele, "0981082834"); 
 //   phoneAddress b; 
 //   strcpy(b.name, "Nguyen Duc Dung"); 
 //   strcpy(b.tele, "0134121234"); 
 //   phoneAddress c; 
 //   strcpy(c.name, "Vu Thanh Tung"); 
 //   strcpy(c.tele, "0021491243"); 
 //   list_append(&list, &a); 
 //   list_insert(&list, &b, 2); 
 //   list_insert(&list, &c, 2); 
 //   list_delete_pos(&list, 3); 
 //   list_for_each(&list, iterator_name) ;
 //   list_reverse(&list); 
 //   list_for_each(&list, iterator_name); 
 //   iterator_name(list.tail->data); 
 // } 
