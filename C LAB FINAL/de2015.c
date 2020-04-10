#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"

typedef struct pack{
  int id;
  char toy[30];
} pack;

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
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

int cmp_id(void *a, void *b){
  pack *p1 = (pack *)a;
  pack *p2 = (pack *)b;
  if(p1->id < p2->id) return -1;
  else if(p1->id > p2->id) return 1;
  else return 0;
}

void iterator_pack(void *data){
  pack *a = (pack *)data;
  printf("%d %s\n", a->id, a->toy);
}

void read_file_to_bst(char *fn, tree *packs){
  FILE *fin = fopen(fn, "r");
  char buff[100];
  while(fgets(buff, 100, fin) != NULL){
    pack *a = malloc(sizeof(pack));
    sscanf(buff, "%d\t%s", &a->id, a->toy);
    if(a->toy[0] == '\0' || a->toy[0] == EOF){
      clear_buffer();
      printf("Pack id %d hasnt have a name of toy yet. Enter it!\n",a->id);
      scanf("%[^\n]s", a->toy);
    }
    tree_insert_bst(&(packs->root), a, packs->elementSize, cmp_id);
    printf("Read successfully id %d\n", a->id);
  }
}

void read_file_to_arr(char *fn, pack *packs, int num){
  FILE *fin = fopen(fn, "r");
  char buff[100];
  int i = 0;
  while(fgets(buff, 100, fin) != NULL && i < num){
    sscanf(buff, "%d\t%s", &packs[i].id, packs[i].toy);
    if(packs[i].toy[0] == '\0' || packs[i].toy[0] == EOF){ // if it reach EOF
      printf("Pack id %d hasnt have a name of toy yet. Enter it!\n",packs[i].id);
      scanf("%s", packs[i].toy);
    }
    i++;
  }
}

void delete_duplicate(tree *tree, pack packs[], int n){
  for(int i = 0; i < n; ++i){
    int id_tmp = packs[i].id;
    if(tree_search(tree->root, &packs[i], cmp_id) != NULL){
      tree_delete_bst(&tree->root, tree_search(tree->root, &packs[i], cmp_id), sizeof(tree->elementSize),  cmp_id);
    }
  }
}

void insert(tree *tree, pack packs[], int n){
  for(int i = 0; i < n; ++i){
    tree_insert_bst(&tree->root, &packs[i], tree->elementSize, cmp_id);
  }
}

int main(){
  tree packs;
  int num = lineCounter("B.txt");
  pack *packB = (pack *)malloc(num*sizeof(pack));
  tree_new(&packs, sizeof(pack));
  int option;
  do{
    printf("\n---------------------\n");
    printf("Santa Clause is comin' to town\n");
    printf("1.Read A\n");
    printf("2.Read B\n");
    printf("3.Seacrch\n");
    printf("4.Summary\n");
    printf("5.Analysis\n");
    printf("6.Bye Bye\n");
    printf("\n---------------------\n");
    scanf("%d", &option);
    switch(option){
    case 1:{
      read_file_to_bst("A.txt", &packs);
      LDR((packs.root), iterator_pack);
      break; 
    }
    case 2:{
      read_file_to_arr("B.txt", packB, num);
      for(int i = 0; i < num; ++i){
	   printf("%d %s\n", packB[i].id, packB[i].toy);
      }
      break;
    }
    case 3:{
      delete_duplicate(&packs, packB, num);
      LDR(packs.root, iterator_pack);
      break;
    }
    case 4:{
      insert(&packs, packB, num);
      LDR(packs.root, iterator_pack);
      break;
    }
    case 5:{
      
      break;
    }
    case 6:{
      printf("Bye bye\n");
      break;
    }
    default:{
      printf("Enter one of those options\n");
      break;
    }
    }
  }while(option != 6);
}
