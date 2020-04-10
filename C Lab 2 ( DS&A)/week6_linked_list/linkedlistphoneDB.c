#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct phone {
  char model[20];
  char rom[10];
  float display;
  char price[10];
} phone;

typedef struct node{
  phone phone;
  struct node *next;
} node;
// 3 global pointer
node *root, *cur, *prev;
node *prevn1, *prevn2, *root2, *root3;
int length = 0;

node *newNode(phone phone){
  node *new = (node*)malloc(sizeof(node));
  new->phone = phone;
  new->next = NULL;
  return new;
}

void displayNode(node *p){
  if(p == NULL) printf("NULL\n");
  printf("%s\t", p->phone.model);
  printf("%s\t", p->phone.rom);
  printf("%lf\t", p->phone.display);
  printf("%s\n", p->phone.price);
}

void insertAtBeginning(phone phone){
  node *node = newNode(phone);
  if(root == NULL) root = node;
  else{
    node->next = root;
    root = node;
  }
  length += 1;
}

void insertAtEnd(phone phone){
  node *node = newNode(phone);
  cur = root;
  while(cur->next != NULL){
    cur = cur->next;
  }
  cur->next = node;
  length += 1;
}

void insertAtAfterPos(phone phone, int pos){
  if((pos > length) || (pos < 0)){
    printf("pos in 0...length\n");
    return;
  }
  else{
    if(pos == 0){
      insertAtBeginning(phone);
    }
    else if (pos == length){
      insertAtEnd(phone);
    }
    else{
      node *new = newNode(phone);
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

void insertAfterCur(phone phone){
  node *new = newNode(phone);
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

void insertBeforeCur(phone phone){
  node *new = newNode(phone);
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
    root = root->next;
    length -= 1;
  }
}

void deleteCur(){
  if(cur == root) deleteAtHead();
  else if (cur->next == NULL) deleteAtEnd();
  else{
    prev->next = cur->next;
    cur = prev->next;
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
    cur = prev;
  }
  length -= 1;
}

void deleteWithData(phone phone){
  cur = root;
  prev = root;
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

void Reverse(){
  node *last = NULL;
  node *nextNode;
  cur = root;
  while(cur != NULL){
    nextNode = cur->next;
    cur->next = last;
    last = cur;
    cur = nextNode;
  }
  root = last;
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
      fread(&p->phone, sizeof(phone), 1, f); // doc du lieu vao p->addr
      cur->next = p;
      cur = p;
      prev = cur;
      length += 1;
    }
    fclose(f);
  }   
}

void Save(char *out){
  FILE *output = fopen(out, "wb");
  if(output == NULL){
    printf("Cannot open the file.\n");
    return;
  }
  else{
    for(cur = root; cur != NULL; cur = cur->next){
      fwrite(&cur->phone, sizeof(phone), 1, output);
    }
  }
  fclose(output);
}

void splitList(node *root, int n1, int n2){
  int count1 = 0;
  int count2 = 0;
  while(cur->next != NULL){
    prevn1 = cur;
    cur = cur->next;
    count1++;
    if(count1 == n1) break;
    printf("node %dth is not in the list\n", n1);
  }
  root2 = cur;
  while(cur->next != NULL){
    prevn2 = cur;
    cur = cur->next;
    count2++;
    if(count2 == n2) break;
    printf("node %dth is not in the list\n", n2);
  }
  prevn1->next = cur->next;
  cur->next = NULL;
  length = length - n2;
  int length2 = n2;
}

// void readDatafromText(char *fn){
//   FILE *f =fopen(fn, "rb");
//   if(f == NULL){
//     printf("Cannot open the file.\n");
//     return;
//   }
//   else{
//     while(!feof(f)){
      
//     }
//   }
// }

int main(){
  int choice = 0;
  phone Phone;
  strcpy(Phone.model, "Nokia");
  strcpy(Phone.rom, "12GB"); 
  Phone.display = 11;
  strcpy(Phone.price, "12tr");
  
  while(choice != 12){
    printf("Functions : \n");
    printf("1. Import from DB\n"
          "2. Display\n"
          "3. Add new\n"
          "4. Insert At Position\n"
          "5. Delete At Position\n"
          "6. Delete current\n"
          "7. Delete head\n"
          "8. Search and Update\n"
          "9. Dividing and Extract\n"
          "10. Reverse List\n"
          "11. Save to file\n"
          "12. Quit\n");
    scanf("%d", &choice);
    switch(choice){
      case 1 : 
       readDatatoList("phoneDB.dat");
        break;
      case 2 :
        traversingList();
        break;
      case 3 :
        insertAtEnd(Phone);
        break;
      case 4 : 
        insertAtAfterPos(Phone, 2);
        break;
      case 5 : 
        deleteAtPos(2);
        break;
      case 6 : 
        deleteWithNode(cur);
        break;
      case 7: 
        deleteAtHead();
        break;
    // case 8:
    //   searchUpdate();
    //   break;
      case 9:
        splitList(root, 3, 7);
        break;
      case 10:
        Reverse();
        break;
      case 11 :
        Save("phoneDB.dat");
        break;
      case 12 :
        freeList();
        break;
    }
  }
}
