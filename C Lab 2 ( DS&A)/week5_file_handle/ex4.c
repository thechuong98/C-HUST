#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void headerPrint(FILE *streamO, char *Arr[], int num){
  if((streamO = fopen("file.txt", "w+b")) == NULL) printf("Cannot open the file");
  else{
    int irc = fwrite(Arr, sizeof(char), num, streamO);
    fclose(streamO);
  }
}

double FileSize(FILE *streamO){
  fseek(streamO, 0L, SEEK_END);
  double sz = ftell(streamO);
  rewind(streamO);
  return 0;
}

int main(){
  FILE *streamO;
  char *Arr[] = {
    "Chu The Chuong",
    "asdfasdfasdfasd",
    "afasfdadsfsadfasfda"
  };
}
