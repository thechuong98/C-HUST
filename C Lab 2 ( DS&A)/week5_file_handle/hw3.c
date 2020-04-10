#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copyByChar(char *fnIn, char *fnOut){
  FILE *fin = fopen(fnIn, "r");
  FILE *fout = fopen(fnOut, "w+");
  if (fin == NULL){
    printf("cannot open the file.\n");
    return;
  }
  char c;
  while((c=fgetc(fin)) != EOF){
    fputc(c, fout);
  }
  fclose(fin);
  fclose(fout);
}

void copyByLine(char *fnIn, char *fnOut){
  FILE *fin = fopen(fnIn, "r");
  FILE *fout = fopen(fnOut, "w+");
  if(fin == NULL){
    printf("cannot open the file.\n");
    return;
  }
  char buff[100];
  while(!feof(fin)){
    fgets(buff, 100, fin);
    fputs(buff, fout);
  }

  fclose(fin);
  fclose(fout);
}

void copyByBlock(char *fnIn, char *fnOut, int size){
  FILE *fin = fopen(fnIn, "r");
  FILE *fout = fopen(fnOut, "w+b");
  if(fin == NULL){
    printf("cannot open the file.\n");
    return;
  }
  char *buff;
  buff = (char *)malloc(size*sizeof(char));
  while(!feof(fin)){
    fread(buff, sizeof(char), size, fin);
    fwrite(buff, sizeof(char), size, fout);
  }
  fclose(fin);
  fclose(fout);
}

int main(){
  int choice = 0;
  printf("Choose 1 in 3 option: \n");
  printf("1. Copy By Character\n");
  printf("2. Copy By Line\n");
  printf("3. Copy By Block\n");
  printf("Your option : ");
  scanf("%d", &choice);

  switch(choice){
  case 1:{
    clock_t begin = clock();
    copyByChar("test.txt", "test_1.txt");
    clock_t end = clock();
    double time = (double)(end -begin)/CLOCKS_PER_SEC;
    printf("Runtime : %.4lf\n", time);
  }
  case 2:{
    clock_t begin = clock();
    copyByLine("test.txt", "test_1.txt");
    clock_t end = clock();
    double time = (double)(end -begin)/CLOCKS_PER_SEC;
    printf("Runtime : %.4lf\n", time);
  }
  case 3:{
    clock_t begin = clock();
    copyByBlock("test.txt", "test_1.txt", 10000);
    clock_t end = clock();
    double time = (double)(end -begin)/CLOCKS_PER_SEC;
    printf("Runtime : %.4lf\n", time);
  }
  }
  return 0;
}
