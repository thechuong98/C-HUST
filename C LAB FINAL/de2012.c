#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"

typedef struct student{
  char name[30];
  double score;
} student;

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

void iterator_student(void *data){
  student *s = (student *)data;
  printf("%s has score %lf\n", s->name, s->score);
}

void Import(char *fn, list *class){
  int num_line = lineCounter(fn);
  FILE *fin = fopen(fn, "r");
  for(int i = 0; i < (num_line)/2 + 1; ++i){
    student *a = malloc(sizeof(student));
    fgets(a->name, 30, fin);
    a->name[strlen(a->name)-1] = '\0';
    if(fscanf(fin, "%lf\n", &a->score) == 1){
      list_append(class, a);
    }
    else{
      printf("student %s havent had score yet. Enter : ", a->name);
      scanf("%lf", &a->score);
      list_append(class,a );
    }
  } 
}

void searchX(list *class, double x){
  listNode *cur = class->head;
  int count = 0;
  while(cur != NULL){
    if(((student *)(cur->data))->score >= x){
      iterator_student(cur->data);
      count++;
    }
    cur = cur->next;
  }
  if(count == 0) printf("No student has score >= x\n");
}


void searchY(list *class, list *excellentClass){
  listNode *cur = class->head;
  int count = 0;
  while(cur != NULL){
    if(((student *)(cur->data))->score >= 8.5){
      list_append(excellentClass, cur->data);
      count++;
    }
    cur = cur->next;
  }
  if(count == 0) printf("No student has score >= x\n");
}

void export(FILE *stream, listNode *head){
  if(head == NULL) return;
  student *a = (student *)(head->data);
  fprintf(stream, "%s\n%lf\n", a->name, a->score);
  export(stream, head->next);
}

int comparator_score(void *a, void *b){
  student *s1 = (student *)a;
  student *s2 = (student *)b;
  if(s1->score < s2->score) return -1;
  else if(s1->score > s2->score) return 1;
  else return 0;
}

void sort_list(listNode *head){
  
}

int main(){
  list classD, classE;
  list excellentClass;
  list mergeL;
  list_new(&mergeL, sizeof(student));
  list_new(&classD, sizeof(student));
  list_new(&classE, sizeof(student));
  list_new(&excellentClass, sizeof(student));
  int option;
  do{
    printf("\n---------------------\n");
    printf("C Basic\n");
    printf("1.Import\n");
    printf("2.Searching for something\n");
    printf("3.Excellent\n");
    printf("4.Export\n");
    printf("5.Merge\n");
    printf("\n---------------------\n");
    scanf("%d", &option);
    switch(option){
    case 1:{
      Import("6D", &classD);
      Import("6E", &classE);
      list_for_each(&classD, iterator_student);
      break;
    }
    case 2:{
      double x = 9.5;
      searchX(&classD, x);
      searchX(&classE, x);
      break;
    }
    case 3:{
      searchY(&classD, &excellentClass);
      searchY(&classE, &excellentClass);
      list_for_each(&excellentClass, iterator_student);
      break;
    }
    case 4:{
      FILE *stream = fopen("6Mearge", "w+");
      export(stream, excellentClass.head);
      fclose(stream);
      break;
    }
    case 5:{
      list_sort(classD.head, comparator_score);
      list_sort(classE.head, comparator_score);
      listNode *mergeList = list_merge(classD.head, classE.head, comparator_score);
      mergeL.head = mergeList;
      list_for_each(&mergeL, iterator_student);
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
