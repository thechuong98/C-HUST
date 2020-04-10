#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Address{
  char web[20];
  char ip[30];
  int ban;
} Address;

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

int cmp_web(void *a, void *b){
  Address *a1 = (Address *)a;
  Address *a2 = (Address *)b;
  if(strcmp(a1->web, a2->web) < 0) return -1;
  else if(strcmp(a1->web, a2->web) > 0) return 1;
  else return 0;
}

int cmp_ip(void *a, void *b){
  Address *a1 = (Address *)a;
  Address *a2 = (Address *)b;
  int arr_1[4];
  int arr_2[4];
  sscanf(a1->ip, "%d.%d.%d.%d", &arr_1[0], &arr_1[1], &arr_1[2], &arr_1[3]);
  sscanf(a2->ip, "%d.%d.%d.%d", &arr_2[0], &arr_2[1], &arr_2[2], &arr_2[3]);
  if(arr_1[0] > arr_2[0]) return 1;
  if(arr_1[0] == arr_2[0] && arr_1[1] > arr_2[1]) return 1;
  if(arr_1[0] == arr_2[0] && arr_1[1] == arr_2[1] && arr_1[2] > arr_2[2]) return 1;
  if(arr_1[0] == arr_2[0] && arr_1[1] == arr_2[1] && arr_1[2] == arr_2[2] && arr_1[3] > arr_2[3]) return 1;
  if(arr_1[0] == arr_2[0] && arr_1[1] == arr_2[1] && arr_1[2] == arr_2[2] && arr_1[3] == arr_2[3]) return 0;
  else return -1;

}

void iterator_web(void *a){
  Address *a1 = (Address *)a;
  printf("%s %s\n", a1->web, a1->ip);
}



int lineCounter(char *fn){
  FILE *f = fopen(fn, "r");
  if ( f == NULL){
    printf("Cannot open the file\n");
    return 0;
  }
  int numOfLines = 0;
  char c;
  while ((c = fgetc(f)) != EOF){
    if (c == '\n') numOfLines++;
  }
  fclose(f);
  return(numOfLines);
}

void read_data(char *fn, tree *BST){
  FILE *fin = fopen(fn, "r");
  if(fin == NULL){
    printf("Cannot open the file.\n");
    return;
  }
  char buff[100];
  while(fgets(buff, 100, fin) != NULL){
    Address *a = malloc(sizeof(Address));
    sscanf(buff, "%s %s", a->web, a->ip); 
  tree_insert_bst(&(BST->root), a, BST->elementSize, cmp_web);
  }
}

void check_ip(tree *BST){
  Address *temp = malloc(sizeof(Address));
  printf("Enter the domain : ");
  scanf("%s", temp->web);
  treeNode *searched = NULL;
  if(temp->web[0] == 'w' && temp->web[1] == 'w' && temp->web[2] == 'w'){
    char *p = &temp->web[4];
    searched = tree_search(BST->root, p, cmp_web);
  }
  else{
    searched = tree_search(BST->root, temp, cmp_web);
  }
  if(searched != NULL){
    printf("Redirecting to %s\n", ((Address *)(searched->data))->ip);
  }
  else printf("This site can't be reached\n");
}

void display(char *fn){
  FILE *fin = fopen(fn, "r");
  char buff[100];
  while(fgets(buff, 100, fin) != NULL){
    printf("%s", buff);
  }
}

void banned(char *fn, tree *address_tree, tree *ip_tree){
  FILE *fin = fopen(fn, "r");
  char buff[100];
  while(fgets(buff, 100, fin) != NULL){
    fputs(buff, stdin);
    buff[strlen(buff)-1] = '\0';
    Address *a = malloc(sizeof(Address));
    if(isalpha(buff[0])){
      strcpy(a->web, buff);
      tree_insert_bst(&(address_tree->root), a, address_tree->elementSize, cmp_web);
    }
    if(isdigit(buff[0])){
      strcpy(a->ip, buff);
      tree_insert_bst(&(ip_tree->root), a, ip_tree->elementSize, cmp_ip);
    }
  } 
}

void search_ban(tree *only_address, tree *only_ip, tree *address_tree, tree *ip_tree){
  Address *temp = malloc(sizeof(Address));
  treeNode *searched = NULL;
  char temp_str[30];
  printf("Enter the address : ");
  scanf("%s", temp_str);
  if(isdigit(temp_str[0])){
    strcpy(temp->ip, temp_str);
    searched = tree_search(only_ip->root, temp, cmp_ip);
    if(searched != NULL){
      printf("This site has been blocked");
    }
    else{
      searched = tree_search(ip_tree->root, temp, cmp_ip);
      if(searched != NULL) printf("Redirecting to %s\n", ((Address *)(searched->data))->web);
    }
  }
  if(isalpha(temp_str[0])){
    strcpy(temp->web, temp_str);
    searched = tree_search(only_address->root, temp, cmp_web);
    if(searched != NULL){
      printf("This site has been blocked");
    }
    else{
      searched = tree_search(address_tree->root, temp, cmp_web);
      if(searched != NULL)
	printf("Redirecting to %s\n", ((Address *)(searched->data))->ip);
    }
  }
}

void read_data_ip(char *fn, tree *BST){
  FILE *fin = fopen(fn, "r");
  if(fin == NULL){
    printf("Cannot open the file.\n");
    return;
  }
  char buff[100];
  while(fgets(buff, 100, fin) != NULL){
    Address *a = malloc(sizeof(Address));
    sscanf(buff, "%s %s", a->web, a->ip); 
    tree_insert_bst(&(BST->root), a, BST->elementSize, cmp_ip);
  }
}



void sort_ip(tree *ip_tree, treeNode *root){
  if(root == NULL) return;
  tree_insert_bst(&(ip_tree->root), root->data, ip_tree->elementSize, cmp_ip);
  if(root->right != NULL) sort_ip(ip_tree, root->right);
  if(root->left != NULL) sort_ip(ip_tree, root->left);
}

int main(){
  tree address_tree;
  tree ip_tree;
  tree only_address;
  tree only_ip;
  tree_new(&only_address, sizeof(Address));
  tree_new(&only_ip, sizeof(Address));
  tree_new(&address_tree, sizeof(Address));
  tree_new(&ip_tree, sizeof(Address));
  int option;
  do{
    printf("\n---------------------\n");
    printf("IP Lookup\n");
    printf("1.Read data\n");
    printf("2.Redirecting\n");
    printf("3.Banned\n");
    printf("4.Web sorting\n");
    printf("5.Quit\n");
    printf("\n---------------------\n");
    scanf("%d", &option);
    clear_buffer();
    switch(option){
    case 1:{
      read_data_ip("ip.txt", &ip_tree);
      read_data("ip.txt", &address_tree);
      LDR(address_tree.root, iterator_web);
      break;
    }
    case 2:{
      check_ip(&address_tree);
      break;
    }
    case 3:{
      display("blockedip.txt");
      banned("blockedip.txt", &only_address, &only_ip);
      search_ban(&only_address, &only_ip, &address_tree, &ip_tree);
      break;
    }
    case 4:{
      LDR(ip_tree.root, iterator_web);
      break;
    }
    case 5:{
      printf("Bye bye\n");
      break;
    }
    default:{
      printf("Enter one of those options\n");
      break;
    }
    }
  }while(option != 5);
}
