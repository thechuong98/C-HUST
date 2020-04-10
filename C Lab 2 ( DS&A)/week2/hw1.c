/*copy*/
#include <stdio.h>
#include <string.h>

void CharReadWrite(FILE *IN, FILE *OUT){
  int c;
  while((c=fgetc(IN)) != EOF){
    fputc(c, OUT);
    putchar(c);
  }
}

int main(int argc, const char* argv[]){
  FILE *IN;
  FILE *OUT;
  char INPUT[100];
  char OUTPUT[100];
  if (argc == 3){
    strcpy(INPUT, argv[1]);
    strcpy(OUTPUT, argv[2]);
    if((IN = fopen(INPUT, "r")) == NULL){
      printf("cannot open file %s\n", INPUT);
    }
    else if((OUT = fopen(OUTPUT, "w")) == NULL){
      printf("cannot open file %s\n", OUTPUT);
    }
    else CharReadWrite(IN, OUT);
  }
  else printf("Not in form, it should be in form 'program sourcefile destinationfile'\n");
}
