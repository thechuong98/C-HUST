#ifndef __CLIST_H
#define __CLIST_H
#include "typedef.h"
 
typedef struct _listNode {
  void *data;
  struct _listNode *next;
} listNode;
 
typedef struct {
  int length;
  int elementSize;
  listNode *head;
  listNode *tail;
} list;
 
void list_new(list *list, int elementSize);
void list_destroy(list *list);
void list_prepend(list *list, void *element);
void list_append(list *list, void *element);
void list_insert(list *list, void *element, int position);
int list_size(list *list);
void list_delete_pos(list *list, int position);
void list_delete_data(list *list, void *data);
void list_for_each(list *list, listIterator iterator);
bool is_Same(void *data1, void *data2);
void list_reverse(list *list);
void iterator_name(void *data);
#endif
