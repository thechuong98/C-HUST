#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"

void iterator_string(void *a){
  char *s1 = (char *)a;
  printf("%s\n", s1);
}

int comparator_string(void *a, void *b){
  char *s1 = (char *)a;
  char *s2 = (char *)b;
  if(strcmp(s1,s2) > 0) return 1;
  else if(strcmp(s1, s2) < 0) return -1;
  else return 0;
}

int main(){
  tree Arr;
  tree_new(&Arr, sizeof(char*));
  char str[] = "abc def ghi";
  char **res = NULL; //result array;
  char *p = strtok(str, " ");
  int num_of_element = 0;
  while(p){
    num_of_element += 1;
    res = realloc(res, sizeof(char*) * num_of_element);
    res[num_of_element-1] = p;
    p = strtok(NULL, " ");
  }
  for(int i = 0; i < num_of_element; ++i){
    tree_insert_bst(&(Arr.root), res[i], Arr.elementSize, comparator_string); 
  }
  LDR(Arr.root, iterator_string);
}
