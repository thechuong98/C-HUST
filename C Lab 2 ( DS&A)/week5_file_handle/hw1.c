#include<stdio.h>
#include<stdlib.h>

typedef struct {
  char vn[50];
  char en[50];
} pair;

void text2bin(char *fnIn, char *fnOut){
  FILE *fin = fopen(fnIn, "r");
  FILE *fout = fopen(fnOut, "w+b");
  if(fin == NULL) {
    printf("Cannot open the file\n");
    return;
  }

  char *buff = (char *)malloc(1000*sizeof(char));
  while (!feof(fin)){
    fread(buff, sizeof(char), 1000, fin);
    fwrite(buff, sizeof(char), 1000, fout);
  }
  free(buff);
  fclose(fin);
  fclose(fout);  
}

void wordsBetween(char *fn, int start, int end){
  FILE *f = fopen(fn,"r");
  if(f == NULL){
    printf("Cannot open the file");
    return;
  }

  char buff[100];
  for(int i = 0; i < start; ++i){
    fgets(buff, 100, f);
  }
  for(int i = start; i < end; ++i){
    fgets(buff, 100, f);
    printf("%s", buff);
  }
  return;
}


int main(){
  text2bin("vnedict.txt", "vnedict.bin");
  wordsBetween("vnedict.txt", 5, 6);
  return 0;
}
