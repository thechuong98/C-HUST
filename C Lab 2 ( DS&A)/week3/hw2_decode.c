#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decode(FILE *SOURCE, int n){
  int c;
  while((c = fgetc(SOURCE)) != EOF){
    if(c >= 'a' && c <= 'z'){
      if ( c - n < 'a'){
	c = c - n + 'z' - 'a' + 1; 
      }
      else c = c - n;      
    }
    else if(c >= 'A' && c <= 'Z'){
      if ( c - n <= 'A') c = c - n + 'Z' - 'A' + 1;
      else c = c - n;
    }
    else if(c - n < 0) c = c - n + 127 + 1;
    else c = c - n;
    fseek(SOURCE, -1, SEEK_CUR); // current point - 1
    fputc(c, SOURCE); 
  }
}

int main(int argc, const char* argv[]){
  if(argc == 3){
    FILE *SOURCE;
    char source_file[100];
    int decode_num = atoi(argv[2]);
    strcpy(source_file, argv[1]);
    if((SOURCE = fopen(source_file, "r+")) == NULL){
	printf("Cannot open the source file\n");
    }
    else{
      decode(SOURCE, decode_num);
    }
  }
  else printf("The program take 3 argument 'program input_file number'\n");
}
