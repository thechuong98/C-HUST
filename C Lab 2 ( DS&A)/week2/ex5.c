#include <stdio.h>

void convert(FILE *IN, FILE *OUT){
	int c;
	while((c = fgetc(IN)) != EOF){
		if( c >= 65 && c <= 90){
			c = c + 32;
		}
		else if (c >= 97 && c <= 122){
			c = c - 32;
		}
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
    convert(IN, OUT);
    fclose(IN);
    fclose(OUT);
  }
}