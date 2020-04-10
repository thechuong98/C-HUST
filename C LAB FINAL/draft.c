#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"
#include <time.h>


typedef struct Address{
  char web[20];
  char ip[15];
} Address;

int randomNum(){
  time_t t;
  srand((unsigned) time(&t));
  int c = rand()%10;
  return c;
}

void countTime(){
  clock_t start = clock();
  clock_t end = clock();
  printf("Executed time : %g\n", (double)(end-start)/CLOCKS_PER_SEC);
}


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

int main(){
  tree address_tree;
  tree_new(&address_tree, sizeof(Address));
  
  int option;
  do{
    printf("\n---------------------\n");
    printf("IP Lookup\n");
    printf("1.Read data\n");
    printf("2.Check IP\n");
    printf("3.Banned\n");
    printf("4.Web sorting\n");
    printf("5.Quit\n");
    printf("\n---------------------\n");
    scanf("%d", &option);
    clear_buffer();
    switch(option){
    case 1:{
      read_data("ip.txt", &address_tree);
      LDR(address_tree.root, iterator_web);
      break;
    }
    case 2:{
      break;
    }
    case 3:{
      break;
    }
    case 4:{
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
