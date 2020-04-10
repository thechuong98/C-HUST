#include <stdio.h>

void CharReadWrite(FILE *IN, FILE *OUT){
  int c;
  while((c=fgetc(IN)) != EOF){
    fputc(c, OUT);
    putchar(c);
  }
}

int main(){
  FILE *IN;
  FILE *OUT;
  char input[] = "lab1.txt";
  char ouput[] = "lab1w.txt";
  if((IN = fopen(input, "r")) == NULL){
    printf("cannot open file %s\n", input);
  }
  else{
    OUT = fopen(ouput, "w+");
    CharReadWrite(IN, OUT);
    fclose(IN);
    fclose(OUT);
  }
  
}
