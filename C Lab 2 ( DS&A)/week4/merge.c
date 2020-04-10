#include<stdio.h>
#include<string.h>
#define MAX_LEN 100

void merge(FILE *F1, FILE *F2, FILE *F3){
  char buff1[MAX_LEN], buff2[MAX_LEN];
  while((fgets(buff1, MAX_LEN, F1) != NULL) && (fgets(buff2, MAX_LEN, F2) != NULL)){
    fputs(buff1, F3);
    fputs(buff2, F3);
  }
  if(buff1 != NULL) fputs(buff1, F3);
  while((fgets(buff1, MAX_LEN, F1) != NULL))
    fputs(buff1, F3);
  while((fgets(buff2, MAX_LEN, F2) != NULL))
    fputs(buff2, F3);
}

int main(int argc, const char* argv[4]){
  if(argc == 4){
    FILE *f1, *f2, *f3;
    if((f1 = fopen(argv[1], "r")) == NULL || ((f2 = fopen(argv[2], "r")) == NULL) || ((f3 = fopen(argv[3], "w")) == NULL))
       printf("Cannot open all of the file");
    else merge(f1, f2, f3);
  }
  
}
