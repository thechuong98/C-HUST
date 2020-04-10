#include <stdio.h>
#include <string.h>

int main(){
  FILE *IN;
  char filename[100];
  printf("enter the file name : ");
  scanf("%s", filename);
  if ((IN = fopen(filename, "r+")) == NULL ) printf("Cannot open the file\n");
  else{
    int c;
    while ((c = fgetc(IN)) != EOF){
      printf("%c", c);
      if(c == '\n'){
	int *ptr = &c;
	fputc('\n', IN);
	printf("%p\n", ptr);
      }
    }
  }
}
