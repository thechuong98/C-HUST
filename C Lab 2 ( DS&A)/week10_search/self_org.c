#include "dll_self_org.c"

node *sentinelSearch(node *root, T key){
  node *cur = root;
  while(cur->next != NULL){ //get Tail
    cur = cur->next;
  }
  node *tail = cur;

  T last = tail->data; // now cur is last node;
  tail->data = key;
  //start searching
  cur = root;
  int i = 1;
  while(cur->data != key && cur->next != NULL){
    cur = cur->next;
    i++;
  }
  tail->data = last;
  if(i < listLength(root) || (key == cur->data)){
    return cur;
  }
  else{
    return NULL;
  }
}

node *transpose(node **root, T key){
  node *keyNode = sentinelSearch(*root, key);
  if(keyNode == NULL) return NULL;
  if(keyNode->prev == NULL) return keyNode;
  node *prevNode = keyNode->prev;
  int temp = prevNode->data;
  prevNode->data = keyNode->data;
  keyNode->data = temp;
  return prevNode;
}

node *MTF(node **root, T key){
  node *keyNode = sentinelSearch(*root, key);
  if(keyNode == NULL) return NULL;
  else if(keyNode == *root) return keyNode;
  else if(keyNode->prev != NULL && keyNode->next == NULL){
    keyNode->prev->next = NULL;
    keyNode->next = *root;
    keyNode->prev = NULL;
    *root = keyNode;
  }
  else if(keyNode->prev != NULL && keyNode->next != NULL){
    keyNode->prev->next = keyNode->next;
    keyNode->next->prev = keyNode->prev;
    keyNode->next = *root;
    (*root)->prev = keyNode;
    keyNode->prev = NULL;
    *root = keyNode;
  }
  return keyNode;
}

void init_count(node *root){
  for(node *cur = root; cur->next != NULL; cur = cur->next){
    cur->count = 0;
  }
}

void countMethod(node **root, T key){
  node *current = *root;
  node *prev = NULL;
  if(sentinelSearch(*root, key) != NULL){
    current = sentinelSearch(*root, key);
    current->count += 1;
    prev = current->prev;
    if(current == *root) return; //still at beginning;
    else if(current->next == NULL){
      while(current->prev != NULL && current->prev->count < current->count){
        T temp = current->prev->data;
        int count_tmp = current->prev->count;
        current->prev->data = current->data;
        current->prev->count = current->count;
        current->data = temp;
        current->count = count_tmp;
        current = current->prev;
      }
    }
    else{
      node *temp = *root;
      node *temp_prev = NULL;
      while(current->count < temp->count){
        temp_prev = temp;
        temp = temp->next;
      }
      if(current != temp){
        prev->next = current->next;
        current->next->prev = prev;
        current->next = temp;
        temp->prev = current;
        if(temp == *root){
          *root = current;
        }
        else{
          temp_prev->next = current;
          current->prev = temp_prev;
        }
      }
    }

  }
}

int main(){
  node *root = newNode(5);
  insert(&root, 2, listLength(root));
  insert(&root, 3, listLength(root));
  init_count(root);
  countMethod(&root, 5);
  countMethod(&root, 2);
  countMethod(&root, 3);
  countMethod(&root, 2);
  countMethod(&root, 5);
  countMethod(&root, 5);
  traversingList(root);
}
