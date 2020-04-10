#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
  char name[30];
  char tel[15];
  char email[30];
} address;

typedef struct node{
  address addr;
  struct node *next;
} node;
// 3 global pointer
int length = 0;

node *newNode(address addr){
  node *new = (node*)malloc(sizeof(node));
  new->addr = addr;
  new->next = NULL;
  return new;
}

void displayNode(node *p){
  if(p == NULL) printf("NULL\n");
  printf("%s\n", p->addr.name);
  printf("%s\n", p->addr.tel);
  printf("%s\n", p->addr.email);
}

void insertAtBeginning(address addr){
  node *node = newNode(addr);
  if(root == NULL) root = node;
  else{
    node->next = root;
    root = node;
  }
  length += 1;
}

void insertAtEnd(address addr){
  node *node = newNode(addr);
  cur = root;
  while(cur->next != NULL){
    cur = cur->next;
  }
  cur->next = node;
  length += 1;
}

void insertAtAfterPos(address addr, int pos){
  if((pos > length) || (pos < 0)){
    printf("pos in 0...length\n");
    return;
  }
  else{
    if(pos == 0){
      insertAtBeginning(addr);
    }
    else if (pos == length){
      insertAtEnd(addr);
    }
    else{
      node *new = newNode(addr);
      cur = root;
      for(int i = 0; i < pos - 1; ++i){
	cur = cur->next;
      }
      new->next = cur->next;
      cur->next = new;
      cur = new; //current pointer points to the new node
      length += 1;
    }
  }
}

void insertAfterCur(address addr){
  node *new = newNode(addr);
  if(root == NULL){
    root = new;
    cur = root;
  }
  else {
    new->next = cur->next;
    cur->next = new;
    prev = cur;
    cur = cur->next;
  }
}

void insertBeforeCur(address addr){
  node *new = newNode(addr);
  if(root == NULL){
    root = new;
    cur = root;
  }
  else {
    new->next = cur;
    prev->next = new;
    prev = cur;
    cur = new;
  }
}

void deleteAtEnd(){
  if(length == 0) printf("The list is empty\n");
  else{
    cur = root;
    prev = root;
    while (cur->next != NULL){
      prev = cur;
      cur = cur->next;
    }
    prev->next = NULL;
    length -= 1;
  }
}

void deleteAtHead(){
  if(length == 0) printf("The list is empty\n");
  else{
    prev = root;
    root = root->next;
    free(prev);
    length -= 1;
  }
}

void deleteWithNode(node *a){
  if(length == 0) printf("The list is empty\n");
  else{
    cur = root;
    prev = NULL;
    int found = 0;
    while(!found){
      if(cur == a){
        found = 1;
      }
      else if(cur == NULL){
	       printf("Node not in list\n");
    	   return;
      }
      else{
	prev = cur;
	cur = cur->next;
      }
    }
  }
  if(prev == NULL){
    root = cur->next;
  }
  else{
    prev->next = cur->next;
  }
  length -= 1;
}

void deleteWithData(address addr){
  if(length == 0) printf("The list is empty.\n");
  else{
    cur = root;
    prev = NULL;
    int found = 0;
    while(!found){
      if(strcmp(cur->addr.email, addr.email)==0 && strcmp(cur->addr.tel , addr.tel)==0 &&strcmp(cur->addr.name, addr.name) == 0){
        found = 1;
      }
      else if(cur == NULL){
        printf("Address not in a list\n");
        return;
      }
      else{
        prev= cur;
        cur = cur->next;
      }
    }
  }
  if(prev == NULL){
    root = cur->next;
  }
  else{
    prev->next = cur->next;
  }
  length -= 1;
}

void deleteAtPos(int n){
  if(length < n-1) printf("Doesn't have the n-th element\n.");
  else{
    cur = root;
    prev = NULL;
    for(int i = 0; i < n; ++i){
      prev = cur;
      cur = cur->next;
    }
    prev->next = cur->next;
    length -= 1;
    cur = root;
  }
}

void traversingList(){
  node *p;
  for( p = root; p != NULL; p = p->next)
    displayNode(p);
}

void freeList(){
  root = NULL;
}

void readDatatoList(char *fn){
  FILE *f = fopen(fn, "rb");
  if(f == NULL){
    printf("cannot open the file.\n");
    return;
  }
  else{
    while(!feof(f)){
      node *p = malloc(sizeof(node)); //tao 1 node p
      if(!root){
	root = p;
	cur = root;
      }
      fread(&p->addr, sizeof(address), 1, f); // doc du lieu vao p->addr
      cur->next = p;
      cur = p;
    }
    fclose(f);
  }   
}

node listReverse(node *root){
  node *cur, *prev;
  cur  = prev = NULL;
  while(root != NULL){
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  return prev;

}

int main(){
  address addr;
  strcpy(addr.name,"Chuong");
  strcpy(addr.email,"chuthechuong@gmail.com");
  strcpy(addr.tel,"0981082834");
  address addr1;
  strcpy(addr1.name,"Thanh");
  strcpy(addr1.email,"daongocthanh@gmail.com");
  strcpy(addr1.tel,"0123456789");
  /* address addr2; */
  /* strcpy(addr2.name,"Dung"); */
  /* strcpy(addr2.email,"ducdung@gmail.com"); */
  /* strcpy(addr2.tel,"1234156798"); */
  /* root = newNode(addr); */
  /* insertAtBeginning(addr1); */
  /* insertAtPos(addr2, 1); */
  /* traversingList(); */
  /* printf("-------delete---------\n"); */
  /* deleteAtHead(); */
  /* traversingList(); */
  /* free(root); */
  readDatatoList("phone.dat");
  cur = root;
  insertAfterCur(addr);
  insertBeforeCur(addr1);
  traversingList();
}
