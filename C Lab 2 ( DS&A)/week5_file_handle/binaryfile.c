#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100

void BlockReadWrite(FILE *fin, FILE *fout){
  int num;
  char buff[MAX_LEN+1];

  while(!feof(fin)){
    num = fread(buff, sizeof(char), MAX_LEN, fin);
    buff[num*sizeof(char)] = '\0';
    printf("%s", buff);
    fwrite(buff, sizeof(char), num, fout);
  }
}

int main(){
  
}
