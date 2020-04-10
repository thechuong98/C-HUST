/*Count characters in a text file*/

#include <stdio.h>
#include <string.h>
#define MAX 127
int Alphabet[MAX] = {0};

void stats(FILE* IN, FILE *OUT){
  int c;
  while(((c = fgetc(IN)) != EOF)){
    if(c >= 'A' && c <= 'Z'){
      Alphabet[c+('a'-'A')] += 1;
    }
    else{
      Alphabet[c] += 1;
    }
  }
  for(int i = 0; i < MAX; ++i){
    if(Alphabet[i] != 0){
      printf("%c appear %d times\n", i, Alphabet[i]);
      fprintf(OUT, "%c appear %d times\n", i, Alphabet[i]);
    }
  }
}

int main(int argc, const char* argv[]){
  if(argc == 2){
    char input[100];
    FILE *IN;
    FILE *OUT;
    OUT = fopen("sourcestats.txt", "w+");
    strcpy(input, argv[1]);
    if((IN = fopen(input, "r")) == NULL){
      printf("cannot open file %s\n", input);
    }
    else{
      stats(IN, OUT);
    }
    fclose(IN);
    fclose(OUT);
  }
  else printf("The program takes 2 argument in form 'program input_file'\n");
}
